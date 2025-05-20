//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *memory;
    size_t size;
} MemoryStruct;

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if (userp->memory == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;
    }
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0;  // Null-terminate the string
    return realsize;
}

void perform_speed_test(const char* url) {
    CURL *curl;
    CURLcode res;
    MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            printf("Response Code: %ld\n", response_code);
            printf("Downloaded %zu bytes in %.2f seconds, Speed: %.2f bytes/second\n",
                   chunk.size, time_taken, chunk.size / time_taken);
        }

        curl_easy_cleanup(curl);
    }

    free(chunk.memory);
    curl_global_cleanup();
}

void display_menu() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Choose an option:\n");
    printf("1. Test speed to server A\n");
    printf("2. Test speed to server B\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char *servers[] = {
        "http://speed.hetzner.de/10MB.bin", // Server A (example)
        "http://ipv4.download.thinkbroadband.com/10MB.bin", // Server B (example)
    };

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Testing speed to Server A...\n");
                perform_speed_test(servers[0]);
                break;
            case 2:
                printf("Testing speed to Server B...\n");
                perform_speed_test(servers[1]);
                break;
            case 3:
                printf("Exiting the application. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Please select 1, 2, or 3.\n");
                break;
        }
        printf("\n"); // Add some separation between tests
    }
    return 0;
}