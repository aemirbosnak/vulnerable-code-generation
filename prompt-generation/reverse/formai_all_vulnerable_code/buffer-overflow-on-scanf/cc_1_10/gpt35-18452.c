//FormAI DATASET v1.0 Category: Browser Plugin ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 100

// Function to check if a string ends with .com or .org
int is_valid_url(char *url) {
    int len = strlen(url);
    if (len < 4) return 0;

    char *last_four = url + len - 4;
    if (strcmp(last_four, ".com") == 0 || strcmp(last_four, ".org") == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a URL is already in the browser history
int is_url_in_history(char **history, int history_size, char *url) {
    for (int i = 0; i < history_size; i++) {
        if (strcmp(history[i], url) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to add a URL to the browser history
void add_url_to_history(char **history, int *history_size, char *url) {
    if (is_url_in_history(history, *history_size, url)) {
        printf("URL already in history\n");
        return;
    }

    if (*history_size == 10) {
        free(history[0]);
        for (int i = 0; i < 9; i++) {
            history[i] = history[i+1];
        }
        *history_size -= 1;
    }

    history[*history_size] = (char *)malloc(MAX_URL_LENGTH * sizeof(char));
    strcpy(history[*history_size], url);
    *history_size += 1;
}

int main() {
    char *history[10];
    int history_size = 0;

    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    if (!is_valid_url(url)) {
        printf("Invalid URL\n");
        return 0;
    }

    add_url_to_history(history, &history_size, url);

    printf("Browser History:\n");
    for (int i = 0; i < history_size; i++) {
        printf("%s\n", history[i]);
    }

    return 0;
}