//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://www.google.com"
#define BUFFER_SIZE 1024

typedef struct {
    char *data;
    size_t size;
} MemoryBuffer;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, MemoryBuffer *userp) {
    size_t total_size = size * nmemb;
    userp->data = realloc(userp->data, userp->size + total_size + 1);
    if (userp->data == NULL) {
        printf("Not enough memory to store the data!\n");
        return 0;
    }
    memcpy(&(userp->data[userp->size]), contents, total_size);
    userp->size += total_size;
    userp->data[userp->size] = 0;  // Null-terminate the string
    return total_size;
}

void perform_speed_test() {
    CURL *curl;
    CURLcode res;
    MemoryBuffer chunk = {0};
    double download_speed;

    printf("🚀 Starting your Internet Speed Test! Hang tight... 🌐\n");

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, (void *)&download_speed);

        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        if(res != CURLE_OK) {
            printf("Error during the speed test: %s\n", curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &download_speed);
            printf("✅ Test complete! You downloaded the data at a speed of: %.2f KB/s\n", download_speed / 1024);
            printf("⏱️  Time taken for the test: %.2f seconds\n", time_taken);
            printf("📦 Total data downloaded: %zu bytes\n", chunk.size);
        }

        free(chunk.data);
        curl_easy_cleanup(curl);
    } else {
        printf("🚨 Failed to initialize CURL!\n");
    }
    curl_global_cleanup();
}

int main(int argc, char *argv[]) {
    printf("🎉 Welcome to the Internet Speed Test Application! 🎉\n");
    printf("📝 Ensure you have a stable internet connection before we begin!\n");
    char user_input[10];
    
    printf("🔍 Do you want to proceed with the speed test? (yes/no): ");
    fgets(user_input, 10, stdin);
    user_input[strcspn(user_input, "\n")] = '\0'; // Remove newline character

    if (strcmp(user_input, "yes") == 0) {
        perform_speed_test();
    } else {
        printf("🚫 Test aborted. Have a great day! 🌈\n");
    }
    
    return 0;
}