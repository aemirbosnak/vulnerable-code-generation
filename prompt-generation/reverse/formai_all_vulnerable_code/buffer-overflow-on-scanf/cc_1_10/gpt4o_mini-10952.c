//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

struct SpeedData {
    size_t size;
    double speed;
};

size_t write_callback(void *ptr, size_t size, size_t nmemb, struct SpeedData *data) {
    data->size += size * nmemb;
    return size * nmemb;
}

void perform_speed_test(const char *url) {
    CURL *curl;
    CURLcode res;
    struct SpeedData data = {0, 0};
    double total_time;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

        // Start timing
        clock_t start = clock();
        
        res = curl_easy_perform(curl);
        
        // End timing
        clock_t end = clock();
        total_time = (double)(end - start) / CLOCKS_PER_SEC;

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            data.speed = (data.size / total_time) / 1024; // Speed in KB/s
            printf("Downloaded %zu bytes in %.2f seconds.\n", data.size, total_time);
            printf("Download Speed: %.2f KB/s\n", data.speed);
        }
        
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

void display_menu() {
    printf("Internet Speed Test Application\n");
    printf("1. Test Download Speed\n");
    printf("2. Test Upload Speed (dummy test)\n");
    printf("3. Exit\n");
}

void upload_test(const char *url) {
    CURL *curl;
    CURLcode res;
    struct SpeedData data = {0, 0};
    double total_time;
    const char *test_data = "This is a test data string.";

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, test_data);

        // Start timing
        clock_t start = clock();

        res = curl_easy_perform(curl);

        // End timing
        clock_t end = clock();
        total_time = (double)(end - start) / CLOCKS_PER_SEC;

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            data.size = strlen(test_data);
            data.speed = (data.size / total_time) / 1024; // Speed in KB/s
            printf("Uploaded %zu bytes in %.2f seconds.\n", data.size, total_time);
            printf("Upload Speed: %.2f KB/s\n", data.speed);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main() {
    int choice;
    char *url = "https://example.com/file"; // Change this URL for real download speed test
    char *upload_url = "https://httpbin.org/post"; // Dummy URL for upload test

    while(1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                perform_speed_test(url);
                break;
            case 2:
                upload_test(upload_url);
                break;
            case 3:
                printf("Exiting the application.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    return 0;
}