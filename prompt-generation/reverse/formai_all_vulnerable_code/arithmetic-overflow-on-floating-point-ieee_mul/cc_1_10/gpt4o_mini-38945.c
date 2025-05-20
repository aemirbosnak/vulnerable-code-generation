//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://ipv4.download.thinkbroadband.com/5MB.zip"

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

double measure_download_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char temp_filename[] = "download.tmp";
    double speed;
    
    curl = curl_easy_init();
    if(curl) {
        fp = fopen(temp_filename, "wb");
        if(fp == NULL) {
            fprintf(stderr, "Could not open file for writing\n");
            return -1.0;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);

        time_t start_time = time(NULL);
        res = curl_easy_perform(curl);
        time_t end_time = time(NULL);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            fclose(fp);
            curl_easy_cleanup(curl);
            return -1.0;
        }

        fclose(fp);
        curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);
        curl_easy_cleanup(curl);
        
        // Clean up the temporary file
        remove(temp_filename);
        
        double elapsed_time = difftime(end_time, start_time);
        if(elapsed_time > 0) {
            printf("Download completed in %.f seconds.\n", elapsed_time);
        }

        return speed; // Return speed in bytes per second
    }
    return -1.0;
}

void display_speed(double speed) {
    if(speed < 0) {
        printf("Speed measurement failed.\n");
        return;
    }
    
    printf("Download speed: %.2f bytes/second\n", speed);
    
    // Convert speed to Mbps for better readability
    double speed_mbps = (speed * 8) / (1024 * 1024);
    printf("Download speed: %.2f Mbps\n", speed_mbps);
}

int main() {
    double speed;

    printf("Starting internet speed test...\n");
    speed = measure_download_speed(URL);
    display_speed(speed);

    return 0;
}