//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

void list_files(CURL *curl) {
    CURLcode res;

    // Set the URL for FTP LIST
    curl_easy_setopt(curl, CURLOPT_URL, "ftp://your.ftp.server/");
    
    // To use proper credentials
    curl_easy_setopt(curl, CURLOPT_USERPWD, "username:password");

    // Enable verbose for debugging
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    // Make a LIST request
    res = curl_easy_perform(curl);

    // Check for errors
    if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
}

void download_file(CURL *curl, const char *remote_filename, const char *local_filename) {
    FILE *fp;
    CURLcode res;

    // Open local file for writing
    fp = fopen(local_filename, "wb");
    if (!fp) {
        perror("Cannot open file");
        return;
    }

    // Set the URL for the remote file
    char url[BUFFER_SIZE];
    snprintf(url, sizeof(url), "ftp://your.ftp.server/%s", remote_filename);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    
    // Set file pointer for download
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    // Set FTP credentials
    curl_easy_setopt(curl, CURLOPT_USERPWD, "username:password");

    // Enable verbose for debugging
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    // Make the download request
    res = curl_easy_perform(curl);

    // Check for errors
    if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }

    // Clean up
    fclose(fp);
}

int main() {
    CURL *curl;
    CURLcode res;

    // Initialize cURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        int choice;
        char remote_file[BUFFER_SIZE];
        char local_file[BUFFER_SIZE];

        while (1) {
            printf("\nFTP Client Menu:\n");
            printf("1. List files\n");
            printf("2. Download file\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    list_files(curl);
                    break;
                case 2:
                    printf("Enter the name of the remote file to download: ");
                    scanf("%s", remote_file);
                    printf("Enter the name for the local file: ");
                    scanf("%s", local_file);
                    download_file(curl, remote_file, local_file);
                    break;
                case 3:
                    curl_easy_cleanup(curl);
                    curl_global_cleanup();
                    return 0;
                default:
                    printf("Invalid choice, please try again.\n");
            }
        }
    }

    // Cleanup
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}