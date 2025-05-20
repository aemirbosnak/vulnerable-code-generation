//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define QR_CODE_API "https://api.qrserver.com/v1/create-qr-code/"
#define BUFFER_SIZE 1024

typedef struct {
    char *text;
    char *filename;
} QRCodeRequest;

void *generate_qr_code(void *arg) {
    QRCodeRequest *request = (QRCodeRequest *)arg;

    // Create URL for QR code API
    char url[BUFFER_SIZE];
    snprintf(url, sizeof(url), "%s?data=%s&size=200x200", QR_CODE_API, request->text);

    // Set up CURL request
    CURL *curl;
    CURLcode res;
    FILE *fp;

    curl = curl_easy_init();
    if (curl) {
        // Open file for writing the image
        fp = fopen(request->filename, "wb");
        if (!fp) {
            fprintf(stderr, "Failed to open file: %s\n", request->filename);
            curl_easy_cleanup(curl);
            return NULL;
        }

        // Set CURL options
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

        // Perform the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("QR Code saved as: %s\n", request->filename);
        }

        // Clean up
        fclose(fp);
        curl_easy_cleanup(curl);
    }

    return NULL;
}

void prompt_user_for_input() {
    char text[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    int thread_count;

    printf("Enter the text for the QR code: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character

    printf("Enter the filename to save the QR code (e.g., qr_code.png): ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character

    printf("How many QR Codes would you like to generate simultaneously? ");
    scanf("%d", &thread_count);
    getchar(); // consume the newline character after the integer input

    pthread_t threads[thread_count];
    QRCodeRequest requests[thread_count];

    for (int i = 0; i < thread_count; i++) {
        requests[i].text = strdup(text); // Duplicate text string
        char thread_filename[BUFFER_SIZE];
        snprintf(thread_filename, sizeof(thread_filename), "%s_%d.png", filename, i + 1);
        requests[i].filename = strdup(thread_filename);

        if (pthread_create(&threads[i], NULL, generate_qr_code, (void *)&requests[i]) != 0) {
            fprintf(stderr, "Failed to create thread %d\n", i);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
        free(requests[i].text);
        free(requests[i].filename);
    }
}

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    printf("Welcome to the Asynchronous QR Code Generator!\n");
    prompt_user_for_input();
    curl_global_cleanup();
    return 0;
}