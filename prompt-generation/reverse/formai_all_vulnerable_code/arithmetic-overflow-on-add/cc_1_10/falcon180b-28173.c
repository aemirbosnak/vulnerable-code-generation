//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <math.h>

#define SERVER_URL "http://speedtest.net/speedtest.php"
#define BUFFER_SIZE 1024
#define MAX_DOWNLOAD_SPEED 1000000 // 1 Mbps
#define MAX_UPLOAD_SPEED 1000000 // 1 Mbps

int download_speed = 0;
int upload_speed = 0;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    return size * nmemb;
}

long int get_current_timestamp() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int main() {
    CURL* curl;
    FILE* file;
    char readBuffer[BUFFER_SIZE];
    long int startTime, endTime;
    double downloadTime, uploadTime;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (curl) {
        file = fopen("speedtest.html", "wb");

        if (!file) {
            fprintf(stderr, "Failed to open file for writing.\n");
            exit(1);
        }

        curl_easy_setopt(curl, CURLOPT_URL, SERVER_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        startTime = get_current_timestamp();
        curl_easy_perform(curl);
        endTime = get_current_timestamp();

        download_speed = (int) ((double) fread(readBuffer, 1, BUFFER_SIZE, file) / ((double) BUFFER_SIZE / (double) (endTime - startTime)));
        upload_speed = (int) ((double) fwrite(readBuffer, 1, BUFFER_SIZE, file) / ((double) BUFFER_SIZE / (double) (endTime - startTime)));

        fclose(file);
        curl_easy_cleanup(curl);
    }

    printf("Download speed: %d Kbps\n", download_speed);
    printf("Upload speed: %d Kbps\n", upload_speed);

    curl_global_cleanup();

    return 0;
}