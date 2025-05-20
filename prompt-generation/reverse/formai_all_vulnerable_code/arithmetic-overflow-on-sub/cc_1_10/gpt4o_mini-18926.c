//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

// Function to write data to a file (dummy write)
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

// Function to perform the internet speed test
void test_internet_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    
    // Open a file to write downloaded content
    fp = fopen("testfile.tmp", "wb");
    if (!fp) {
        perror("Failed to create file");
        return;
    }

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        // Time the download
        clock_t start_time = clock();
        
        // Perform the download
        res = curl_easy_perform(curl);
        
        clock_t end_time = clock();
        
        // Calculate download duration
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Get file info
            double filesize;
            curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &filesize);
            
            if (filesize > 0 && time_taken > 0) {
                // Calculate speed in Mbps (Megabits per second)
                double speed_mbps = (filesize * 8) / (time_taken * 1000000);
                printf("Download Speed: %.2f Mbps\n", speed_mbps);
            } else {
                printf("Couldn't retrieve file size or time taken.\n");
            }
        }
        // Cleanup
        curl_easy_cleanup(curl);
    }
    
    fclose(fp);
    
    // Remove the temporary test file
    remove("testfile.tmp");
}

// Main function
int main() {
    // URL to test the download speed (you may change it)
    const char *test_url = "http://speed.hetzner.de/1MB.bin";
  
    printf("Starting internet speed test...\n");
    test_internet_speed(test_url);

    return 0;
}