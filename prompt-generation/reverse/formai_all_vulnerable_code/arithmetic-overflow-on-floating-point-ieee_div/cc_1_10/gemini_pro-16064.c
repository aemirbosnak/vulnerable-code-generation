//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>

#include <curl/curl.h>

#define URL "https://www.example.com/"
#define TIMEOUT 5
#define MAX_SIZE 1024 * 1024

struct timeval start, end;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    return size * nmemb;
}

int main(int argc, char **argv) {
    CURL *curl;
    char *buffer;
    long double start_time, end_time, duration;
    double speed;
    int i, ret;

    buffer = malloc(MAX_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        return EXIT_FAILURE;
    }

    curl = curl_easy_init();
    if (curl == NULL) {
        fprintf(stderr, "Error initializing curl\n");
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, TIMEOUT);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

    for (i = 0; i < 10; i++) {
        gettimeofday(&start, NULL);
        ret = curl_easy_perform(curl);
        gettimeofday(&end, NULL);

        if (ret != CURLE_OK) {
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(ret));
            return EXIT_FAILURE;
        }

        start_time = start.tv_sec + (start.tv_usec / 1000000.0);
        end_time = end.tv_sec + (end.tv_usec / 1000000.0);
        duration = end_time - start_time;

        speed = (MAX_SIZE / 1024.0 / 1024.0) / duration;
        printf("Speed: %.2f MB/s\n", speed);
    }

    curl_easy_cleanup(curl);
    free(buffer);
    return EXIT_SUCCESS;
}