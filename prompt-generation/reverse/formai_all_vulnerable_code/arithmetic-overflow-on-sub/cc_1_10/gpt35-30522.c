//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 100

typedef struct {
    char url[MAX_URL_LENGTH];
    time_t last_check;
    int status;
} Website;

void check_sites(Website sites[], int num_sites);
void update_status(Website *site);

int main() {
    Website sites[3] = {
        {"https://www.google.com", 0, 0},
        {"https://www.facebook.com", 0, 0},
        {"https://www.amazon.com", 0, 0}
    };
    int num_sites = sizeof(sites) / sizeof(Website);

    while(1) {
        check_sites(sites, num_sites);
        sleep(30);
    }
    
    return 0;
}

void check_sites(Website sites[], int num_sites) {
    CURL *curl;
    CURLcode res;
    int i;

    curl = curl_easy_init();
    if(curl) {
        for(i=0; i<num_sites; i++) {
            if(time(NULL) - sites[i].last_check > 300) {
                // if it's been more than 5 minutes since last check
                curl_easy_setopt(curl, CURLOPT_URL, sites[i].url);
                // follow redirects
                curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

                res = curl_easy_perform(curl);

                if(res == CURLE_OK) {
                    update_status(&sites[i]);
                } else {
                    printf("Error checking site %s: %s\n", sites[i].url, curl_easy_strerror(res));
                }
            }
        }
        curl_easy_cleanup(curl);
    }
}

void update_status(Website *site) {
    char *url = site->url;
    int http_code = 0;

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);

        /* Perform the request */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if(res != CURLE_OK)
          fprintf(stderr, "curl_easy_perform() failed: %s\n",
                  curl_easy_strerror(res));

        /* Get the response code */
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

        /* always cleanup */
        curl_easy_cleanup(curl);
    }

    if(http_code == 200) {
        site->status = 1;
        printf("%s is up!\n", site->url);
    } else {
        site->status = 0;
        printf("%s is down.\n", site->url);
    }

    site->last_check = time(NULL);
}