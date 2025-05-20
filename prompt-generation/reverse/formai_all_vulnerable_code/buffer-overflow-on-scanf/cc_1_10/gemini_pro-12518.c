//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 2048
#define MAX_QUERY_STRING_LENGTH 1024

static bool is_url_valid(const char *url) {
    if (url == NULL || strlen(url) == 0) {
        return false;
    }

    // Check if the URL has a valid scheme.
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        return false;
    }

    // Check if the URL has a valid host.
    char *host_end = strchr(url, '/');
    if (host_end == NULL) {
        return false;
    }

    // Check if the URL has a valid path.
    char *path_end = strchr(host_end, '?');
    if (path_end == NULL) {
        path_end = host_end + strlen(host_end);
    }

    // Check if the URL has a valid query string.
    char *query_string = path_end + 1;
    if (strlen(query_string) > MAX_QUERY_STRING_LENGTH) {
        return false;
    }

    // Check if the URL has any invalid characters.
    for (char *p = url; *p != '\0'; p++) {
        if (!isalnum(*p) && *p != '-' && *p != '_' && *p != '.' && *p != '/' && *p != '?' && *p != '&' && *p != '=') {
            return false;
        }
    }

    return true;
}

static char *sanitize_url(const char *url) {
    if (!is_url_valid(url)) {
        return NULL;
    }

    // Allocate memory for the sanitized URL.
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        return NULL;
    }

    // Copy the scheme and host to the sanitized URL.
    char *host_end = strchr(url, '/');
    strncpy(sanitized_url, url, host_end - url);

    // Copy the path to the sanitized URL.
    char *path_end = strchr(host_end, '?');
    if (path_end == NULL) {
        path_end = host_end + strlen(host_end);
    }
    strncat(sanitized_url, host_end, path_end - host_end);

    // Copy the query string to the sanitized URL.
    char *query_string = path_end + 1;
    if (strlen(query_string) > MAX_QUERY_STRING_LENGTH) {
        return NULL;
    }
    strncat(sanitized_url, query_string, MAX_QUERY_STRING_LENGTH);

    return sanitized_url;
}

int main(void) {
    // Initialize the CURL library.
    curl_global_init(CURL_GLOBAL_ALL);

    // Get the URL from the user.
    char url[MAX_URL_LENGTH];
    printf("Enter the URL to be sanitized: ");
    scanf("%s", url);

    // Sanitize the URL.
    char *sanitized_url = sanitize_url(url);
    if (sanitized_url == NULL) {
        printf("Invalid URL.\n");
        return 1;
    }

    // Create a CURL handle.
    CURL *curl = curl_easy_init();
    if (curl == NULL) {
        printf("Failed to create CURL handle.\n");
        return 1;
    }

    // Set the URL to be fetched.
    curl_easy_setopt(curl, CURLOPT_URL, sanitized_url);

    // Set the user agent.
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.49.1");

    // Set the timeout.
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30);

    // Perform the request.
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        printf("Failed to perform request: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 1;
    }

    // Get the response code.
    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    // Print the response code.
    printf("Response code: %ld\n", response_code);

    // Clean up the CURL handle.
    curl_easy_cleanup(curl);

    // Free the sanitized URL.
    free(sanitized_url);

    // Clean up the CURL library.
    curl_global_cleanup();

    return 0;
}