//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE    1
#define FALSE   0
#define OK      200

// Function to perform HTTP GET request
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *data = (char*) malloc(realsize + 1);
    if (data == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 0;
    }
    memcpy(data, contents, realsize);
    data[realsize] = '\0';
    printf("%s", data);
    free(data);
    return realsize;
}

// Function to perform HTTP POST request
size_t ReadCallback(void *ptr, size_t size, size_t nmemb, void *userp)
{
    return fread(ptr, size, nmemb, stdin);
}

int main()
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        char url[100];
        printf("Enter the URL: ");
        scanf("%s", url);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Operation completed successfully\n");
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}