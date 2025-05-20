//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    char url[100];
    double download_speed, upload_speed;
    long response_code;

    if (argc!= 2) {
        printf("Usage: %s <server_address>\n", argv[0]);
        return 1;
    }

    strcpy(url, argv[1]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &download_speed);
            curl_easy_getinfo(curl, CURLINFO_SPEED_UPLOAD, &upload_speed);
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

            printf("Download speed: %.2f KB/s\n", download_speed / 1024);
            printf("Upload speed: %.2f KB/s\n", upload_speed / 1024);
            printf("Response code: %ld\n", response_code);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}