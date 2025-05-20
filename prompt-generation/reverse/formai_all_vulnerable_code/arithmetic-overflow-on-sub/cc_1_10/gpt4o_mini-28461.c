//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024 * 1024 // 1 MB buffer size
#define TEST_URL "http://ipv4.download.thinkbroadband.com/1MB.zip" // URL for testing

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, struct MemoryStruct *data) {
    size_t realsize = size * nmemb;
    data->memory = realloc(data->memory, data->size + realsize + 1);
    if (data->memory == NULL) {
        printf("Not enough memory!\n");
        return 0;
    }
    memcpy(&(data->memory[data->size]), ptr, realsize);
    data->size += realsize;
    data->memory[data->size] = 0;
    return realsize;
}

double test_download_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk = {NULL, 0};
    struct timeval start, end;

    curl = curl_easy_init();
    if(curl) {
        gettimeofday(&start, NULL);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        res = curl_easy_perform(curl);
        gettimeofday(&end, NULL);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code == 200) {
                double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
                double speed_mbps = (chunk.size * 8) / (time_taken * 1024 * 1024); // Convert to Mbps
                printf("Download speed: %.2f Mbps\n", speed_mbps);
            } else {
                printf("Failed to download file, response code: %ld\n", response_code);
            }
        }

        free(chunk.memory);
        curl_easy_cleanup(curl);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int iterations = 3;
    if (argc > 1) {
        iterations = atoi(argv[1]);
    }

    printf("Starting Internet Speed Test...\n");

    for (int i = 0; i < iterations; i++) {
        printf("\nTest #%d:\n", i + 1);
        test_download_speed(TEST_URL);
        sleep(1); // Avoid overwhelming the test server
    }

    printf("\nSpeed test completed.\n");
    return 0;
}