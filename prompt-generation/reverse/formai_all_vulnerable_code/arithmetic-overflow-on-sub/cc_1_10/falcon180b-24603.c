//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <stdbool.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[size * nmemb] = '\0';
    return size * nmemb;
}

bool IsWebsiteUp(char* url)
{
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &url);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            return true;
        }
    }
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return false;
}

int main()
{
    char* url = "https://www.example.com";
    time_t last_check = 0;
    bool is_up = false;

    while (true) {
        time_t current_time = time(NULL);
        if (current_time - last_check >= 60) {
            is_up = IsWebsiteUp(url);
            last_check = current_time;
        }
        if (!is_up) {
            printf("Website is down!\n");
        } else {
            printf("Website is up!\n");
        }
        sleep(1);
    }

    return 0;
}