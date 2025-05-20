//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024
#define MAX_DATA_LEN 1024 * 1024

typedef struct {
    char url[MAX_URL_LEN];
    char data[MAX_DATA_LEN];
    size_t size;
} speed_test_data_t;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    speed_test_data_t *data = (speed_test_data_t *)userp;
    size_t new_size = data->size + size * nmemb;
    if (new_size > MAX_DATA_LEN) {
        return 0;
    }
    memcpy(data->data + data->size, ptr, size * nmemb);
    data->size = new_size;
    return size * nmemb;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <test_url>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        speed_test_data_t data;
        strcpy(data.url, argv[1]);
        data.size = 0;

        curl_easy_setopt(curl, CURLOPT_URL, data.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            double speed = (double)data.size / curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, NULL);
            printf("Download speed: %.2f bytes/sec\n", speed);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}