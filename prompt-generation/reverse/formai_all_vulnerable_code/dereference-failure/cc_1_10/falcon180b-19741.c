//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

// Function to sanitize a URL
void sanitize_url(char* url) {
    int i = 0;
    int j = 0;
    char* temp = malloc(strlen(url) + 1);

    // Copy the URL to a temporary string
    strcpy(temp, url);

    // Convert to lowercase
    for (i = 0; temp[i]!= '\0'; i++) {
        temp[i] = tolower(temp[i]);
    }

    // Remove any leading or trailing whitespace
    while (isspace(temp[j])) {
        j++;
    }
    while (isspace(temp[i - 1])) {
        i--;
    }

    // Remove any non-alphanumeric characters
    for (i = j; i <= i - 1; i++) {
        if (!isalnum(temp[i])) {
            temp[i] = '-';
        }
    }

    // Copy the sanitized URL back to the original string
    strcpy(url, temp);

    // Free the temporary string
    free(temp);
}

// Function to download a URL
size_t download_url(void* buffer, size_t size, size_t nmemb, void* userp) {
    FILE* file = (FILE*)userp;
    size_t bytes_written = fwrite(buffer, size, nmemb, file);
    return bytes_written;
}

// Function to download a file from a URL
void download_file(char* url, char* filename) {
    CURL* curl = curl_easy_init();
    FILE* file = fopen(filename, "wb");

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, download_url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    fclose(file);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <URL> <filename>\n", argv[0]);
        return 1;
    }

    // Sanitize the URL
    char* url = argv[1];
    sanitize_url(url);

    // Download the file
    char* filename = argv[2];
    download_file(url, filename);

    printf("File downloaded successfully.\n");
    return 0;
}