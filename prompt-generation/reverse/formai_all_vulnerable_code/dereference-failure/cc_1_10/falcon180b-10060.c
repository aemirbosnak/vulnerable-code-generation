//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <curl/curl.h>

#define INTERVAL 1 // in seconds

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char readBuffer[1024];
    double speed = 0;
    int bytesRead = 0;
    time_t start, end;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        fp = fopen("speedtest.txt", "wb");
        if(!fp) {
            printf("Unable to open file!\n");
            exit(1);
        }

        curl_easy_setopt(curl, CURLOPT_URL, "https://speedtest.net/speedtest.png");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            fclose(fp);
            start = time(NULL);
            while(1) {
                bytesRead = fread(readBuffer, 1, 1024, fp);
                if(bytesRead <= 0) {
                    break;
                }
                speed += (double)bytesRead;
            }
            end = time(NULL);
            printf("Internet speed: %0.2f bytes/second\n", speed / (end - start));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}