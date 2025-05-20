//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Custom data structure to store website information
typedef struct website {
    char *url;
    int status_code;
    time_t last_checked;
} website_t;

// Function to check the status code of a website
int check_website(website_t *website) {
    CURL *curl;
    CURLcode res;

    // Initialize the curl handle
    curl = curl_easy_init();
    if (curl == NULL) {
        fprintf(stderr, "Error initializing curl\n");
        return 1;
    }

    // Set the URL to check
    curl_easy_setopt(curl, CURLOPT_URL, website->url);

    // Set the timeout
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Set the follow location option to true
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);

    // Perform the request
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error performing request: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 1;
    }

    // Get the status code
    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    // Store the status code in the website struct
    website->status_code = (int) response_code;

    // Clean up the curl handle
    curl_easy_cleanup(curl);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified a website to check
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <website URL>\n", argv[0]);
        return 1;
    }

    // Create a website struct for the specified website
    website_t website;
    website.url = argv[1];
    website.status_code = -1;
    website.last_checked = 0;

    // Check the website once
    if (check_website(&website) != 0) {
        fprintf(stderr, "Error checking website\n");
        return 1;
    }

    // Print the website status
    printf("Website status: %d\n", website.status_code);

    // If the website is up, ask the user if they want to monitor it
    if (website.status_code == 200) {
        char answer;
        printf("Do you want to monitor this website (y/n)? ");
        scanf(" %c", &answer);

        if (answer == 'y') {
            // Monitor the website every 60 seconds
            while (1) {
                // Check the website
                if (check_website(&website) != 0) {
                    fprintf(stderr, "Error checking website\n");
                    break;
                }

                // Print the website status
                printf("Website status: %d\n", website.status_code);

                // Sleep for 60 seconds
                sleep(60);
            }
        }
    }

    return 0;
}