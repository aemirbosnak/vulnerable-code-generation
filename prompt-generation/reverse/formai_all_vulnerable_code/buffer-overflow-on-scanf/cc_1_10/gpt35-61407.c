//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 200

// This function sanitizes the input url
void sanitize(char* url) {
    char sanitized_url[MAX_URL_LENGTH] = {0};
    int j = 0;
    for (int i = 0; url[i] != '\0'; i++) {
        if (isalnum(url[i])) {
            sanitized_url[j++] = url[i];
        } else if (url[i] == '.') {
            if (j == 0 || sanitized_url[j-1] == '.') {
                continue;
            } else {
                sanitized_url[j++] = url[i];
            }
        } else if (url[i] == '/') {
            if (j == 0 || sanitized_url[j-1] == '/') {
                continue;
            } else {
                sanitized_url[j++] = url[i];
            }
        } else if (url[i] == '-') {
            if (j == 0) {
                continue;
            } else {
                sanitized_url[j++] = url[i];
            }
        }
    }
    strcpy(url, sanitized_url);
}

// This function is used to send the input url to other players
void send_url(char* url, int player_id) {
    printf("Player %d entered the url %s\n", player_id, url);
}

// This function receives the input url from other players
void receive_url(char* url, int player_id) {
    printf("Player %d's turn: Enter the url:\n", player_id);
    scanf("%s", url);
    sanitize(url);
}

int main() {
    char url[MAX_URL_LENGTH] = {0};

    // Player 1 enters the first url
    receive_url(url, 1);
    
    while (1) {
        // Player 2 sends the url to player 1
        send_url(url, 2);
        
        // Player 1 enters the next url
        receive_url(url, 1);
        
        // Player 1 wins if the url is "http://www.google.com"
        if (strcmp(url, "http://www.google.com") == 0) {
            printf("Player 1 wins!\n");
            break;
        }
        
        // Player 1 sends the url to player 2
        send_url(url, 1);
        
        // Player 2 enters the next url
        receive_url(url, 2);
        
        // Player 2 wins if the url is "http://www.google.com"
        if (strcmp(url, "http://www.google.com") == 0) {
            printf("Player 2 wins!\n");
            break;
        }
    }
    
    return 0;
}