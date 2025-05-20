//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

typedef struct {
    char *url;
    int port;
    char *host;
    int timeout;
} website_t;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    if(argc < 4) {
        printf("Usage: %s <url> <port> <timeout>\n", argv[0]);
        return 1;
    }

    website_t website = {
       .url = argv[1],
       .port = atoi(argv[2]),
       .host = argv[3],
       .timeout = atoi(argv[4])
    };

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website.url);
        curl_easy_setopt(curl, CURLOPT_PORT, website.port);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, 0);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, 0);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, website.timeout);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}