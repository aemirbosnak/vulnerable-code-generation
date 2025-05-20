//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 200
#define MAX_PLAYERS 4

int num_players = 0;
char sanitized_urls[MAX_PLAYERS][MAX_URL_LENGTH];

void sanitize_url(char* url, char* sanitized_url) {
    int i, j = 0;
    int len = strlen(url);
    for(i=0;i<len;i++) {
        if(url[i] == '<')
            sanitized_url[j++] = '&';
        else if(url[i] == '>')
            sanitized_url[j++] = '#';
        else
            sanitized_url[j++] = url[i];
    }
    sanitized_url[j] = '\0';
}

void player_move(int player_num) {
    char url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];

    printf("Player %d, Enter the URL: ", player_num+1);
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0';

    sanitize_url(url, sanitized_url);
    strcpy(sanitized_urls[player_num], sanitized_url);
}

int main() {
    int i;

    printf("Welcome to URL Sanitizer Multiplayer Game!\n");

    printf("Enter number of players (2-4): ");
    scanf("%d", &num_players);
    getchar(); //to flush the newline character from buffer

    for(i=0;i<num_players;i++)
        player_move(i);

    // Print the sanitized URLs for each player
    printf("\nSanitized URLs\n");
    for(i=0;i<num_players;i++)
        printf("Player %d: %s\n", i+1, sanitized_urls[i]);

    return 0;
}