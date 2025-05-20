//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define URL_SIZE 128
#define SPEED_FACTORS {1048576, 1024, 1}
#define SPEED_UNITS {"Mbps", "Kbps", "bps"}

size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream) {
    return size * nmemb;
}

int speed_factor(long speed, int* factor_array, char** unit_array) {
    int i;
    for (i = 0; i < 3; i++) {
        if (speed >= factor_array[i]) {
            return i;
        }
    }
    return 2;
}

double measure_speed(char* url) {
    double speed = 0.0;
    CURL* curl_handle = NULL;
    CURLcode res_code;
    double curl_time, data_size;
    long speed_factor_index;
    int factor_array[3] = SPEED_FACTORS;
    char* unit_array[3] = SPEED_UNITS;

    curl_global_init(CURL_GLOBAL_ALL);

    curl_handle = curl_easy_init();
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl_handle, CURLOPT_TCP_NODELAY, 1);
    curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 1);

    res_code = curl_easy_perform(curl_handle);
    if (res_code != CURLE_OK) {
        printf("Error: %s\n", curl_easy_strerror(res_code));
    } else {
        curl_easy_getinfo(curl_handle, CURLINFO_SIZE_DOWNLOAD, &data_size);
        curl_easy_getinfo(curl_handle, CURLINFO_TOTAL_TIME, &curl_time);

        speed_factor_index = speed_factor((long)(data_size / curl_time), factor_array, unit_array);

        speed = (double)(data_size / curl_time) / factor_array[speed_factor_index];
        printf("Download Speed: %.2f %s\n", speed, unit_array[speed_factor_index]);
    }

    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();

    return speed;
}

int main() {
    char url[URL_SIZE];
    double speed;

    printf("Enter the URL to test: ");
    fgets(url, URL_SIZE, stdin);

    /* remove newline character from input */
    url[strcspn(url, "\n")] = 0;

    speed = measure_speed(url);

    return 0;
}