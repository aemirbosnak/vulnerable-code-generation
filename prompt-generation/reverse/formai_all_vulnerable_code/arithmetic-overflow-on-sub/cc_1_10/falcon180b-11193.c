//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define CHECK_INTERVAL 60 // Check website every 60 seconds
#define TIMEOUT 10 // Timeout after 10 seconds

char *website = "https://www.example.com"; // Replace with the website you want to monitor

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int main() {
    CURL *curl;
    FILE *fp;
    char buffer[1024];
    time_t last_check = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

        while (1) {
            time_t current_time = time(NULL);

            if (current_time - last_check >= CHECK_INTERVAL) {
                last_check = current_time;

                curl_easy_perform(curl);
                curl_easy_cleanup(curl);

                fp = fopen("website_status.log", "a");
                if (fp) {
                    fprintf(fp, "Website checked at %s\n", ctime(&current_time));
                    fclose(fp);
                }
            }

            sleep(1);
        }
    }

    return 0;
}