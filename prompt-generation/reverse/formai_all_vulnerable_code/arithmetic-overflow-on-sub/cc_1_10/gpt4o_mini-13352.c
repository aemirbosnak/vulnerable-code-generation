//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if (userp->memory == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;
    }

    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0;
    return realsize;
}

double measure_download_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        struct timeval start, end;

        gettimeofday(&start, NULL);
        res = curl_easy_perform(curl);
        gettimeofday(&end, NULL);

        if (res != CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if (response_code == 200) {
                double duration = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
                double speed_mbps = (chunk.size * 8.0) / (duration * 1024 * 1024);
                printf("Downloaded %zu bytes in %.3f seconds: Speed = %.2f Mbps\n", chunk.size, duration, speed_mbps);
            } else {
                printf("HTTP response code: %ld\n", response_code);
            }
        }

        curl_easy_cleanup(curl);
        free(chunk.memory);
    } else {
        printf("Failed to initialize CURL.\n");
    }

    return 0;
}

void print_instructions() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("This application will measure the download speed from a specified URL.\n");
    printf("Please ensure you have cURL installed and connect to a stable internet.\n");
    printf("The default test URL is: http://speed.hetzner.de/100MB.bin\n");
    printf("You can change it by providing a different URL as a command line argument.\n");
    printf("Press Ctrl+C to exit the application.\n");
}

int main(int argc, char **argv) {
    const char *url = "http://speed.hetzner.de/100MB.bin"; // Default testing URL
    if (argc > 1) {
        url = argv[1];
    }

    print_instructions();
    measure_download_speed(url);

    return 0;
}