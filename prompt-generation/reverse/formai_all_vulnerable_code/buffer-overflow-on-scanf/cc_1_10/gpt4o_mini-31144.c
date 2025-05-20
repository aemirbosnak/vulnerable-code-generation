//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Example C Browser Plugin for URL Shortening

typedef struct UrlMapping {
    char longUrl[256];
    char shortUrl[64];
    struct UrlMapping* next;
} UrlMapping;

UrlMapping* head = NULL;

void addMapping(const char* longUrl) {
    static int urlCounter = 1;  // Simple counter for creating short URLs
    UrlMapping* newMapping = (UrlMapping*)malloc(sizeof(UrlMapping));
    if (newMapping == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    strncpy(newMapping->longUrl, longUrl, sizeof(newMapping->longUrl) - 1);
    snprintf(newMapping->shortUrl, sizeof(newMapping->shortUrl), "short.ly/%d", urlCounter++);
    newMapping->next = head;
    head = newMapping;

    printf("Mapping created: Long URL: %s | Short URL: %s\n", longUrl, newMapping->shortUrl);
}

const char* getShortUrl(const char* longUrl) {
    UrlMapping* current = head;
    while (current != NULL) {
        if (strcmp(current->longUrl, longUrl) == 0) {
            return current->shortUrl;
        }
        current = current->next;
    }
    return NULL;
}

void displayMappings() {
    UrlMapping* current = head;
    printf("Current URL Mappings:\n");
    while (current != NULL) {
        printf("Long URL: %s | Short URL: %s\n", current->longUrl, current->shortUrl);
        current = current->next;
    }
}

void freeMappings() {
    UrlMapping* current = head;
    UrlMapping* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

void showMenu() {
    printf("\nURL Shortener Plugin Menu:\n");
    printf("1. Add new URL mapping\n");
    printf("2. Retrieve short URL\n");
    printf("3. Display all mappings\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char longUrl[256];

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar();  // Clear the newline character left in input buffer

        switch (choice) {
            case 1:
                printf("Enter the long URL: ");
                fgets(longUrl, sizeof(longUrl), stdin);
                longUrl[strcspn(longUrl, "\n")] = 0;  // Remove newline character
                addMapping(longUrl);
                break;

            case 2:
                printf("Enter the long URL to retrieve short URL: ");
                fgets(longUrl, sizeof(longUrl), stdin);
                longUrl[strcspn(longUrl, "\n")] = 0;  // Remove newline character
                const char* shortUrl = getShortUrl(longUrl);
                if (shortUrl) {
                    printf("Short URL: %s\n", shortUrl);
                } else {
                    printf("No mapping found for the provided long URL.\n");
                }
                break;

            case 3:
                displayMappings();
                break;

            case 4:
                freeMappings();
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice, please select again.\n");
        }
    }

    return 0;
}