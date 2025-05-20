//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
    char *method;
    char *url;
    char *version;
    struct curl_slist *headers;
    char *data;
    size_t data_len;
} Request;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    char *buffer = (char *)malloc(size * nmemb);
    memcpy(buffer, contents, size * nmemb);
    printf("%s", buffer);
    return size * nmemb;
}

int main()
{
    CURL *curl;
    CURLcode res;
    Request req;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        req.method = strdup("GET");
        req.url = strdup("https://www.example.com");
        req.version = strdup("HTTP/1.1");
        req.headers = NULL;
        req.data = NULL;
        req.data_len = 0;

        curl_easy_setopt(curl, CURLOPT_URL, req.url);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, req.method);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, req.headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}