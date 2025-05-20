//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <curl/curl.h>

// Define the maximum number of threads to use
#define MAX_THREADS 10

// Define the maximum number of URLs to monitor
#define MAX_URLS 100

// Define the interval between checks (in seconds)
#define CHECK_INTERVAL 60

// Define the timeout for each check (in seconds)
#define CHECK_TIMEOUT 10

// Define the user agent to use for checks
#define USER_AGENT "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.88 Safari/537.36"

// Structure to store the URL and its status
typedef struct {
    char *url;
    int status;
} url_status;

// Array to store the URLs to monitor
url_status urls[MAX_URLS];

// Mutex to protect the shared array
pthread_mutex_t mutex;

// Function to check the status of a URL
void *check_url(void *arg) {
    // Get the URL from the argument
    char *url = (char *)arg;

    // Initialize the status to 0 (unknown)
    int status = 0;

    // Create a new curl handle
    CURL *curl = curl_easy_init();

    // Set the URL to check
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the user agent
    curl_easy_setopt(curl, CURLOPT_USERAGENT, USER_AGENT);

    // Set the timeout
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, CHECK_TIMEOUT);

    // Perform the request
    CURLcode res = curl_easy_perform(curl);

    // Check if the request was successful
    if (res == CURLE_OK) {
        // Get the status code
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        // Update the status
        if (response_code == 200) {
            status = 1;
        } else {
            status = -1;
        }
    } else {
        // An error occurred
        status = -1;
    }

    // Cleanup the curl handle
    curl_easy_cleanup(curl);

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Update the shared array
    for (int i = 0; i < MAX_URLS; i++) {
        if (strcmp(urls[i].url, url) == 0) {
            urls[i].status = status;
            break;
        }
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Return the status
    return (void *)status;
}

int main() {
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Initialize the curl library
    curl_global_init(CURL_GLOBAL_ALL);

    // Get the number of URLs to monitor from the user
    int num_urls;
    printf("Enter the number of URLs to monitor: ");
    scanf("%d", &num_urls);

    // Get the URLs from the user
    for (int i = 0; i < num_urls; i++) {
        printf("Enter the URL to monitor: ");
        scanf("%s", urls[i].url);
        urls[i].status = 0;
    }

    // Create a thread pool
    pthread_t threads[MAX_THREADS];

    // Start the threads
    for (int i = 0; i < num_urls; i++) {
        pthread_create(&threads[i], NULL, check_url, urls[i].url);
    }

    // Join the threads
    for (int i = 0; i < num_urls; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the status of each URL
    for (int i = 0; i < num_urls; i++) {
        printf("%s: %d\n", urls[i].url, urls[i].status);
    }

    // Cleanup the curl library
    curl_global_cleanup();

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}