//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 1000

// Returns sanitized URL or null if not valid
char* sanitize_url(char* url) {
    // Check for null argument
    if(url == NULL) {
        return NULL;
    }

    // Remove whitespace at the beginning and end of the URL
    while(isspace((unsigned char)*url)) {
        url++;
    }
    size_t len = strlen(url);
    while(len > 0 && isspace((unsigned char)url[len-1])) {
        len--;
    }
    url[len] = '\0';

    // Check for empty URL
    if(len == 0) {
        return NULL;
    }

    // Check for valid URL
    if(strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        return NULL;
    }

    // Check for maximum URL length
    if(len > MAX_URL_LENGTH) {
        return NULL;
    }

    return url;
}

// Play the game
int main(int argc, char *argv[]) {
    int players;
    char urls[5][MAX_URL_LENGTH];
    char *sanitized_url;

    printf("Welcome to C URL Sanitizer!\n");
    printf("Enter the number of players (1-5): ");
    scanf("%d", &players);
    if(players < 1 || players > 5) {
        printf("Invalid number of players.\n");
        return 0;
    }

    printf("Game starts now!\n");
    for(int i=0; i<players; i++) {
        printf("Player %d, enter your URL: ", i+1);
        scanf("%s", urls[i]);
        sanitized_url = sanitize_url(urls[i]);

        // Check if URL is valid
        if(sanitized_url) {
            printf("Player %d entered a valid URL.\n", i+1);
            strcpy(urls[i], sanitized_url);
        } else {
            printf("Player %d entered an invalid URL.\n", i+1);
            urls[i][0] = '\0';
        }
    }

    printf("Valid URLs:\n");
    for(int i=0; i<players; i++) {
        if(urls[i][0] != '\0') {
            printf("%s\n", urls[i]);
        }
    }

    return 0;
}