//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 256
#define MAX_RESPONSE_SIZE 1024

// Structure to store website uptime data
typedef struct website_uptime {
    char *url;
    time_t last_checked;
    int status_code;
    char *response;
} website_uptime;

// Function to check the uptime of a website
int check_website_uptime(website_uptime *website) {
    CURL *curl;
    CURLcode res;
    char *response = malloc(MAX_RESPONSE_SIZE);

    // Initialize CURL
    curl = curl_easy_init();
    if (curl == NULL) {
        return -1;
    }

    // Set the URL to check
    curl_easy_setopt(curl, CURLOPT_URL, website->url);

    // Set the response buffer
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

    // Perform the request
    res = curl_easy_perform(curl);

    // Get the status code
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &website->status_code);

    // Update the last checked time
    website->last_checked = time(NULL);

    // Clean up
    curl_easy_cleanup(curl);
    free(response);

    return res;
}

// Function to print the website uptime data
void print_website_uptime(website_uptime *website) {
    printf("URL: %s\n", website->url);
    printf("Last checked: %s", ctime(&website->last_checked));
    printf("Status code: %d\n", website->status_code);
    printf("Response: %s\n", website->response);
}

// Main function
int main() {
    // Initialize website uptime data
    website_uptime website;
    website.url = malloc(MAX_URL_SIZE);
    website.response = malloc(MAX_RESPONSE_SIZE);

    // Get the website URL from the user
    printf("Enter the website URL: ");
    scanf("%s", website.url);

    // Check the website uptime
    int res = check_website_uptime(&website);

    // Print the website uptime data
    if (res == CURLE_OK) {
        print_website_uptime(&website);
    } else {
        printf("Error checking website uptime: %s\n", curl_easy_strerror(res));
    }

    // Clean up
    free(website.url);
    free(website.response);

    return 0;
}