//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define MAX_BUFFER_LENGTH 1000000

typedef struct {
   char name[MAX_NAME_LENGTH];
   int score;
} player_t;

player_t players[MAX_PLAYERS];
int num_players;

char buffer[MAX_BUFFER_LENGTH];
int buffer_length;

void compress(char *src, int src_len, char *dst, int *dst_len) {
    int i, j = 0, count;
    char c;

    for(i = 0; i < src_len; i++) {
        c = src[i];
        count = 1;
        while(i < src_len - 1 && src[i] == src[i + 1]) {
            count++;
            i++;
        }
        if(count == 1) {
            dst[j++] = c;
        } else {
            dst[j++] = count + '0';
            dst[j++] = c;
        }
    }
    *dst_len = j;
}

void decompress(char *src, int src_len, char *dst, int *dst_len) {
    int i, j = 0, count;
    char c;

    for(i = 0; i < src_len; i += 2) {
        count = src[i] - '0';
        c = src[i+1];

        while(count--) {
            dst[j++] = c;
        }
    }
    *dst_len = j;
}

int main() {
    int i, j;
    char name[MAX_NAME_LENGTH];

    printf("Enter number of players (2-4): ");
    scanf("%d", &num_players);

    for(i = 0; i < num_players; i++) {
        printf("Enter name of Player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    printf("Enter input string: ");
    scanf("%s", buffer);
    buffer_length = strlen(buffer);

    char compressed_buffer[MAX_BUFFER_LENGTH];
    int compressed_buffer_length;
    compress(buffer, buffer_length, compressed_buffer, &compressed_buffer_length);

    printf("Compressed string: %s\n", compressed_buffer);

    char decompressed_buffer[MAX_BUFFER_LENGTH];
    int decompressed_buffer_length;
    decompress(compressed_buffer, compressed_buffer_length, decompressed_buffer, &decompressed_buffer_length);

    printf("Decompressed string: %s\n", decompressed_buffer);

    for(i = 0; i < num_players; i++) {
        for(j = 0; j < buffer_length; j++) {
            if(buffer[j] == players[i].name[0]) {
                players[i].score++;
            }
        }
        printf("Player %s's score: %d\n", players[i].name, players[i].score);
    }

    return 0;
}