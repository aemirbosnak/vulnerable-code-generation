//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *url;
    char *method;
    struct curl_slist *headers;
    char *post_data;
} Request;

typedef struct {
    CURL *curl;
    FILE *fp;
    char error[CURL_ERROR_SIZE];
} Response;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    FILE *stream = (FILE *)userp;
    return fwrite(contents, size, nmemb, stream);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url> [method] [headers] [post_data]\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *method = (argc > 2)? argv[2] : "GET";
    struct curl_slist *headers = NULL;
    char *post_data = (argc > 3)? argv[3] : NULL;

    CURL *curl = curl_easy_init();
    if (curl == NULL) {
        printf("Error initializing curl\n");
        return 1;
    }

    Response response = {curl, stdout, ""};
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response.fp);
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, response.error);

    if (headers!= NULL) {
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    }

    if (post_data!= NULL) {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(post_data));
    }

    CURLcode res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        printf("Error performing request: %s\n", response.error);
        return 1;
    }

    curl_easy_cleanup(curl);
    fclose(response.fp);

    return 0;
}