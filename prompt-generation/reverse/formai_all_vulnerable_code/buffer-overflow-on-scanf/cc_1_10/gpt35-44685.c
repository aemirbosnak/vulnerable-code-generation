//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LEN 1024
#define MAX_COMPRESS_LEN 512

char** compress(char* message, int num_players){
    int message_len = (int)strlen(message);
    int i, j;

    // Initialize compressed messages for each player
    char** compressed_msgs = (char**) malloc(num_players * sizeof(char*));
    for (i = 0; i < num_players; i++){
        compressed_msgs[i] = (char*) malloc(sizeof(char) * MAX_COMPRESS_LEN);
        compressed_msgs[i][0] = '\0';
    }

    // Compress message for each player
    for (i = 0; i < num_players; i++){
        for (j = i; j < message_len; j += num_players){
            strncat(compressed_msgs[i], &message[j], 1);
        }
    }

    return compressed_msgs;
}

int main(){
    // Input message
    char message[MAX_STRING_LEN];
    printf("Enter message to compress: ");
    fgets(message, MAX_STRING_LEN, stdin);
    message[strcspn(message, "\n")] = '\0';

    // Input number of players
    int num_players;
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    // Compress message for each player
    char** compressed_msgs = compress(message, num_players);

    // Print out compressed messages for each player
    int i;
    for (i = 0; i < num_players; i++){
        printf("Compressed message for player %d: %s\n", i, compressed_msgs[i]);
    }

    return 0;
}