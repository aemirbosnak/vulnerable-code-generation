//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <curl/curl.h>

#define URL_TEST "http://www.google.com"
#define BUFFER_SIZE 1024
#define MAX_TRIALS 5

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if (userp->memory == NULL) {
        printf("Not enough memory!\n");
        return 0;
    }
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0;
    return realsize;
}

void perform_speed_test(int trials) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    double total_time = 0.0;

    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    printf("Starting Internet Speed Test... Get ready!\n");

    for (int i = 0; i < trials; i++) {
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, URL_TEST);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
            
            struct timeval start, end;
            gettimeofday(&start, NULL);

            res = curl_easy_perform(curl);
            gettimeofday(&end, NULL);

            double elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0; // sec to ms
            elapsed_time += (end.tv_usec - start.tv_usec) / 1000.0; // us to ms
            total_time += elapsed_time;

            if (res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            } else {
                printf("Test #%d: Downloaded %zu bytes in %.2f ms\n", i + 1, chunk.size, elapsed_time);
            }
            chunk.size = 0; // Reset for the next trial
            free(chunk.memory);
            chunk.memory = malloc(1);
            curl_easy_cleanup(curl);
        }
        sleep(1); // Pause for a moment before the next trial
    }

    curl_global_cleanup();

    double average_time = total_time / trials;
    printf("\n--- Average Speed Test Results ---\n");
    printf("Total Tests: %d\n", trials);
    printf("Average Time per test: %.2f ms\n", average_time);
    printf("Thank you for testing your Internet Speed with us! Stay connected and happy browsing!\n");
}

int main() {
    int trials = 0;

    printf("Welcome to the Happy Internet Speed Test Application!\n");
    printf("Let's determine how fast your internet is!\n");
    printf("You can choose how many tests to run (max %d): ", MAX_TRIALS);
    
    while (trials <= 0 || trials > MAX_TRIALS) {
        scanf("%d", &trials);
        if (trials <= 0 || trials > MAX_TRIALS) {
            printf("Please enter a valid number of trials (1 to %d): ", MAX_TRIALS);
        }
    }

    perform_speed_test(trials);
    
    printf("Exiting the Happy Internet Speed Test Application. Have a great day!\n");
    return 0;
}