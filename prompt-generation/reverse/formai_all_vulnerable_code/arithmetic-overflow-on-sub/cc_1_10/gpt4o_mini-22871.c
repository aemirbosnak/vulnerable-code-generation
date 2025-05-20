//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 10
#define MAX_URL_LENGTH 256

// Function to check the uptime of the provided URL
void check_url(const char *url) {
    CURL *curl;
    CURLcode res;
    long http_code = 0;
    double time_taken = 0.0;

    // Initialize CURL
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body
        curl_easy_setopt(curl, CURLOPT_HEADER, 1L); // We're interested in headers
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); // Timeout after 10 seconds

        // Time the request
        clock_t start_time = clock();
        res = curl_easy_perform(curl);
        clock_t end_time = clock();

        // Calculate elapsed time
        time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        // Check for errors and status code
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            printf("Checking %s... Response Code: %ld, Time Taken: %.2f seconds\n", url, http_code, time_taken);
        }

        // Cleanup
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize curl\n");
    }
}

int main(int argc, char *argv[]) {
    char *urls[MAX_URLS];
    int num_urls = 0;

    // Parse command line arguments (URLs)
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return 1;
    }

    // Store URLs in an array
    for (int i = 1; i < argc && num_urls < MAX_URLS; i++) {
        urls[num_urls] = argv[i];
        num_urls++;
    }

    printf("🌐 Welcome to the Fun-tastic Website Uptime Monitor! 🚀\n");
    printf("-----------------------------------------------------\n");
    
    // Perform uptime checks in a loop
    for (int i = 0; i < num_urls; i++) {
        check_url(urls[i]);

        // Add a little delay for user-friendly output
        printf("⏳ Checking next URL...\n");
        sleep(2);
    }

    printf("🎉 All done! Happy Monitoring! 🎉\n");
    
    return 0;
}