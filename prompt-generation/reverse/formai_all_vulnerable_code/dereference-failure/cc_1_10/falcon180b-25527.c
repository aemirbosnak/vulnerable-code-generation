//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024
#define MAX_DATA_LEN 1024 * 1024 * 10

typedef struct {
    char *url;
    long response_code;
    long response_size;
    double speed;
} test_result_t;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((test_result_t *)userp)->response_size += size * nmemb;
    return size * nmemb;
}

static int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    double speed = (double)dlnow / (double)dltotal * 100.0;
    ((test_result_t *)clientp)->speed = speed;
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;
    test_result_t result = {0};

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        result.url = strdup(argv[1]);
        curl_easy_setopt(curl, CURLOPT_URL, result.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &result);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Downloaded %ld bytes from %s in %.2f seconds at %.2f KB/s\n",
                    result.response_size, result.url, result.speed, result.speed / 1024.0);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}