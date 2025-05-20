//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>

typedef struct {
    size_t received;
    size_t size;
} write_data;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    write_data *w = (write_data *)userp;
    size_t realsize = size * nmemb;
    w->received += realsize;
    return realsize;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        write_data wdata;
        wdata.received = 0;
        wdata.size = 0;

        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &wdata);

        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();

        if(res != CURLE_OK) {
            fprintf(stderr, "Failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 1;
        }

        double speed = (wdata.received / (double)(end - start)) / 1024.0;
        printf("Downloaded %.2fKB in %.2fs, speed: %.2fKB/s\n", wdata.received / 1024.0, (end - start) / CLOCKS_PER_SEC, speed);

        curl_easy_cleanup(curl);
    }

    return 0;
}