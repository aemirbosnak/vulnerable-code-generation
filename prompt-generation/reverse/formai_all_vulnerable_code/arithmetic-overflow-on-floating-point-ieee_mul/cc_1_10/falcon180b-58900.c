//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

struct speedtest {
    char *url;
    long int speed;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

long int get_speed(struct speedtest *st) {
    CURL *curl;
    CURLcode res;
    double start_time, end_time;
    long int filesize = 0;
    long int speed = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, st->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, NULL);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &start_time);
            curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &filesize);
            curl_easy_cleanup(curl);

            speed = (long int) (filesize / (start_time * 1000.0));
        }
    } else {
        printf("curl_easy_init() failed\n");
    }

    curl_global_cleanup();
    return speed;
}

int main() {
    struct speedtest st = {"https://speedtest.net/speedtest.php", 0};
    long int speed = get_speed(&st);

    printf("Internet Speed: %ld kbps\n", speed);
    return 0;
}