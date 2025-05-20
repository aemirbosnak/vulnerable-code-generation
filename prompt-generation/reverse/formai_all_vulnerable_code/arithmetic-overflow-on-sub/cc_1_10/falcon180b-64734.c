//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>

// Function to get current time in milliseconds
long long int get_current_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((char*)userp)[(size_t)size * nmemb] = 0;
    return size * nmemb;
}

// Function to check if website is up or down
int check_website_status(char* website_url) {
    CURL* curl;
    CURLcode res;
    char* response = NULL;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website_url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    if(response && strstr(response, "200 OK")) {
        printf("Website is up\n");
        return 1;
    } else {
        printf("Website is down\n");
        return 0;
    }
}

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s <website_url>\n", argv[0]);
        exit(1);
    }

    char* website_url = argv[1];
    int website_status = 0;
    long long int last_check_time = get_current_time_ms();

    while(1) {
        sleep(60); // Check every minute

        website_status = check_website_status(website_url);

        if(website_status == 1) {
            printf("Website is up at %lld ms\n", get_current_time_ms() - last_check_time);
            last_check_time = get_current_time_ms();
        } else {
            printf("Website is down at %lld ms\n", get_current_time_ms() - last_check_time);
            last_check_time = get_current_time_ms();
        }
    }

    return 0;
}