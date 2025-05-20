//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    // Callback function for curl_easy_setopt's writefunction parameter
    return size * nmemb;
}

int main() {
    CURL *curl_handle;
    CURLcode res;
    double speed;
    char url[] = "http://speedtest.tele2.net/100MB.zip"; // URL for speed test
    long http_code;

    curl_global_init(CURL_GLOBAL_ALL); // Initialize curl
    curl_handle = curl_easy_init(); // Create easy handle

    if(curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, url); // Set URL option
        curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L); // Follow redirects
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteCallback); // Set callback function for write data
        curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 1L); // HTTP HEAD request

        res = curl_easy_perform(curl_handle); // Perform HTTP HEAD request

        if(res != CURLE_OK) { // Check for errors
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else { // Get HTTP response code
            curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &http_code);

            if(http_code == 200) { // If response code is 200 OK
                curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 0L); // HTTP GET request

                clock_t start = clock(); // Start time
                res = curl_easy_perform(curl_handle); // Perform HTTP GET request
                clock_t stop = clock(); // Stop time

                if(res != CURLE_OK) { // Check for errors
                    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
                }
                else { // Calculate internet speed
                    double elapsed_time = (double)(stop - start) / CLOCKS_PER_SEC; // Elapsed time in seconds
                    double file_size = 100000000; // File size in bytes
                    speed = file_size / elapsed_time; // Calculate internet speed in bytes per second
                    
                    // Convert speed to human-readable format
                    if(speed >= 1000000000) { // Gigabytes per second
                        printf("Internet Speed: %.2f GB/s\n", speed / 1000000000);
                    }
                    else if(speed >= 1000000) { // Megabytes per second
                        printf("Internet Speed: %.2f MB/s\n", speed / 1000000);
                    }
                    else if(speed >= 1000) { // Kilobytes per second
                        printf("Internet Speed: %.2f KB/s\n", speed / 1000);
                    }
                    else { // Bytes per second
                        printf("Internet Speed: %.2f B/s\n", speed);
                    }
                }
            }
            else { // If response code is other than 200 OK
                fprintf(stderr, "HTTP request failed with error code: %ld\n", http_code);
            }
        }

        curl_easy_cleanup(curl_handle); // Cleanup curl
    }
    else { // If curl handle creation failed
        fprintf(stderr, "curl_easy_init() failed\n");
    }

    curl_global_cleanup(); // Cleanup curl globally

    return 0;
}