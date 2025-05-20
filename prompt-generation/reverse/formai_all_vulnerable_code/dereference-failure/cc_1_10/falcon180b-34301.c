//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 512
#define MAX_RESPONSE_LEN 1024

// Function for writing data to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

// Function for handling response data
size_t handle_response(char *ptr, size_t size, size_t nmemb, void *userp) {
    FILE *file = (FILE *)userp;
    return fwrite(ptr, size, nmemb, file);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <URL> <output file>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    FILE *output_file;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        char url[MAX_URL_LEN];
        strcpy(url, argv[1]);

        output_file = fopen(argv[2], "w");
        if (!output_file) {
            printf("Error: Could not open output file.\n");
            return 1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_response);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, output_file);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        fclose(output_file);
    }

    curl_global_cleanup();
    return 0;
}