//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

// Callback for writing data to stdout
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(strlen(url) + 1);
    int i = 0, j = 0;
    for (i = 0; url[i]!= '\0'; i++) {
        if (isalnum(url[i])) {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    CURL* curl;
    CURLcode res;
    char* url;

    // Initialize curl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    // Set callback for writing data to stdout
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    // Prompt user for URL
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize URL
    char* sanitized_url = sanitize_url(url);

    // Set URL for curl to retrieve
    curl_easy_setopt(curl, CURLOPT_URL, sanitized_url);

    // Execute curl and get result
    res = curl_easy_perform(curl);

    // Print result to stdout
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    } else {
        printf("Result:\n%s", sanitized_url);
    }

    // Cleanup curl and memory
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    free(sanitized_url);
    free(url);

    return 0;
}