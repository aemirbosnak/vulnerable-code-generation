//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

typedef struct {
    char *url;
    double speed;
    time_t timestamp;
} speed_test_result_t;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    speed_test_result_t *result = (speed_test_result_t *)userp;
    strncat(result->url, (char *)contents, size * nmemb);
    return size * nmemb;
}

int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    speed_test_result_t *result = (speed_test_result_t *)clientp;
    double speed = (double)dlnow / (double)dltotal * 100;
    result->speed = speed;
    return 0;
}

int main(int argc, char **argv) {
    CURL *curl;
    CURLcode res;
    speed_test_result_t result;
    char url[1024];
    struct timeval start, end;

    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    strcpy(result.url, argv[1]);
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &result);

        gettimeofday(&start, NULL);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        gettimeofday(&end, NULL);
        double duration = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

        printf("URL: %s\n", result.url);
        printf("Speed: %.2f Mbps\n", result.speed);
        printf("Duration: %.2f seconds\n", duration);

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}