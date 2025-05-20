//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <ctype.h>

#define CHECK_INTERVAL 60 // Check website every 60 seconds
#define TIMEOUT_SEC 10 // Timeout after 10 seconds

// Function to check if website is up
int check_website(char *url) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT_SEC);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "Failed to check website: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return res == CURLE_OK;
}

// Function to send email alert
void send_email(char *subject, char *message) {
    FILE *fp;
    char cmd[256];

    sprintf(cmd, "echo '%s' | mail -s '%s' you@example.com", message, subject);

    fp = popen(cmd, "r");

    if(fp!= NULL) {
        pclose(fp);
    }
}

// Main function
int main() {
    char url[256];
    int is_up;

    printf("Enter website URL: ");
    scanf("%s", url);

    while(1) {
        is_up = check_website(url);

        if(!is_up) {
            send_email("Website Down Alert", "The website is down!");
        }

        sleep(CHECK_INTERVAL);
    }

    return 0;
}