//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024
#define TEST_URL "http://ipv4.download.thinkbroadband.com/10MB.zip" // Test file for download speed

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

void download_file(const char *url) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char outfilename[FILENAME_MAX] = "download_test_file.zip";

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_FILE, fp);
        
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}

double measure_download_speed(const char *url) {
    struct timeval start, end;
    double elapsed_time;
    
    gettimeofday(&start, NULL);
    download_file(url);
    gettimeofday(&end, NULL);

    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    return elapsed_time;
}

void calculate_speed(double time_in_seconds, size_t file_size) {
    double speed_mbps = (file_size * 8) / (time_in_seconds * 1000000.0);
    printf("Download speed: %.2f Mbps\n", speed_mbps);
}

int main() {
    const char *url = TEST_URL;
    
    printf("Starting download speed test...\n");
    
    // Getting the file size
    CURL *curl;
    CURLcode res;
    double file_size = 0;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            curl_off_t cl;
            res = curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &cl);
            if ((CURLE_OK == res) && (cl >= 0)) {
                file_size = (size_t)cl;
                printf("File size for test: %.2f MB\n", file_size / 1000000.0);
            }
        } else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }

    if (file_size > 0) {
        double download_time = measure_download_speed(url);
        printf("Download completed in %.2f seconds.\n", download_time);
        calculate_speed(download_time, file_size);
    } else {
        fprintf(stderr, "Could not retrieve file size.\n");
    }

    return 0;
}