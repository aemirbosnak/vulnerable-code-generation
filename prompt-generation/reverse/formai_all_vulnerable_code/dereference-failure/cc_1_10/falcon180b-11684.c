//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_URL_LENGTH 2048

// Function to check if a character is valid in a URL
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~') {
        return 1;
    }
    return 0;
}

// Function to sanitize a URL
void sanitize_url(char *url) {
    int i, j;
    char *dest = malloc(MAX_URL_LENGTH);
    memset(dest, 0, MAX_URL_LENGTH);
    j = 0;
    for (i = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            dest[j++] = tolower(url[i]);
        }
    }
    dest[j] = '\0';
    strcpy(url, dest);
    free(dest);
}

// Function to be executed by each thread
void *sanitize_url_thread(void *param) {
    char *url = (char *)param;
    sanitize_url(url);
    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];
    char *urls[MAX_THREADS] = {
        "https://www.example.com/path/to/page.html",
        "https://www.example.com/path/to/another_page.html",
        "https://www.example.com/path/to/yet_another_page.html",
        "https://www.example.com/path/to/even_more_pages.html",
        "https://www.example.com/path/to/still_more_pages.html",
        "https://www.example.com/path/to/even_more_pages.html",
        "https://www.example.com/path/to/still_more_pages.html",
        "https://www.example.com/path/to/even_more_pages.html",
        "https://www.example.com/path/to/still_more_pages.html",
        "https://www.example.com/path/to/even_more_pages.html"
    };

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, sanitize_url_thread, (void *)urls[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}