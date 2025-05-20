//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

// Function to calculate internet speed
double calculate_speed(long long bytes, double seconds) {
    double speed = (double)bytes / seconds;
    if (speed > 1024) {
        speed /= 1024;
    }
    return speed;
}

// Function to print speed in Sherlock Holmes style
void print_speed(double speed) {
    if (speed > 1) {
        printf("Ah, Watson, it seems we have a most intriguing speed of %.2lf Mbps. Quite remarkable, wouldn't you agree?\n", speed);
    } else {
        printf("My dear Watson, our internet speed is a rather pedestrian %.2lf Kbps. We shall have to remedy that posthaste!\n", speed);
    }
}

int main() {
    // Initialize cURL
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        // Set URL to speedtest.net
        char url[100] = "https://speedtest.net/speedtest.php?test=1";

        // Set cURL options
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);

        // Perform speed test
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "Speed test failed: %s\n", curl_easy_strerror(res));
            return 1;
        }

        // Get response data
        char *response;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response);

        // Calculate internet speed
        long long bytes = strtol(response, NULL, 10);
        double seconds = curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, NULL);

        // Print speed
        print_speed(calculate_speed(bytes, seconds));

        // Clean up cURL
        curl_easy_cleanup(curl);
    }

    return 0;
}