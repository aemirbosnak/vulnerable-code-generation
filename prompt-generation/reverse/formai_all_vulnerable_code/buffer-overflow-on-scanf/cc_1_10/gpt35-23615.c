//FormAI DATASET v1.0 Category: Browser Plugin ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Define the maximum length of a URL */
#define MAX_URL_LENGTH 256

/* Define the structure for storing the URLs */
typedef struct BrowserPlugin{
    char* url;
    struct BrowserPlugin* next;
} BrowserPlugin;

BrowserPlugin* head = NULL;

/* Function to add the current URL to the linked list */
void add_url_to_list(char url[]) {
    BrowserPlugin* new_url;
    new_url = (BrowserPlugin*) malloc(sizeof(BrowserPlugin));
    if (new_url == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }

    /* Allocate memory for the URL string and copy it */
    new_url->url = (char*) malloc((strlen(url) + 1) * sizeof(char));
    if (new_url->url == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
    strcpy(new_url->url, url);

    /* Add the new URL to the head of the linked list */
    new_url->next = head;
    head = new_url;
}

/* Function to print the URLs stored in the linked list */
void print_urls() {
    BrowserPlugin* current_url = head;
    while (current_url != NULL) {
        printf("%s\n", current_url->url);
        current_url = current_url->next;
    }
}

/* Function to check if a string is a valid URL */
int is_valid_url(char url[]) {
    /* Check if the string starts with "http://" or "https://" */
    if (strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0) {
        /* Check if the string contains only valid characters */
        for (int i = 0; i < strlen(url); i++) {
            if (!isalnum(url[i]) && url[i] != '.' && url[i] != '/' && url[i] != ':' && url[i] != '-') {
                return 0;
            }
        }
        return 1;
    }
    else {
        return 0;
    }
}

/* Main function */
int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL:\n");
    scanf("%s", url);

    /* Check if the URL is valid */
    if (is_valid_url(url)) {
        /* Add the URL to the linked list */
        add_url_to_list(url);
        /* Print the URLs stored in the linked list */
        printf("List of URLs:\n");
        print_urls();
    }
    else {
        printf("Invalid URL.\n");
    }

    return 0;
}