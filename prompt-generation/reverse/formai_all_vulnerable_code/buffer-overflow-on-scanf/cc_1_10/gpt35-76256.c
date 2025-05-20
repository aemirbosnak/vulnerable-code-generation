//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_LEN 1000

typedef struct {
    char compressed[MAX_LEN];
    int length;
} compressed_data_t;

typedef struct {
    char original[MAX_LEN];
    int length;
} data_t;

void compress(data_t* input, compressed_data_t* output) {
    int len = input->length;
    char* original = input->original;

    int i, j, count = 1;
    char prev = original[0];
    char* compressed = output->compressed;

    for (i = 1, j = 0; i < len; i++) {
        if (original[i] == prev) {
            count++;
        } else {
            compressed[j++] = prev;
            compressed[j++] = count + '0';
            count = 1;
            prev = original[i];
        }
    }
    compressed[j++] = prev;
    compressed[j++] = count + '0';
    compressed[j] = '\0';

    output->length = j;
}

void print_compressed_data(compressed_data_t data) {
    printf("Compressed data: %s\n", data.compressed);
}

void print_original_data(data_t data) {
    printf("Original data: %s\n", data.original);
}

int main() {
    int num_players, i, j;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    compressed_data_t compressed_data[MAX_PLAYERS];
    data_t original_data[MAX_PLAYERS];

    for (i = 0; i < num_players; i++) {
        printf("Enter data for player %d: ", i+1);
        scanf("%s", original_data[i].original);
        original_data[i].length = strlen(original_data[i].original);

        compress(&original_data[i], &compressed_data[i]);
    }

    printf("Compressed data for all players:\n");

    for (i = 0; i < num_players; i++) {
        print_compressed_data(compressed_data[i]);
    }

    printf("\n");

    printf("Original data for all players:\n");

    for (i = 0; i < num_players; i++) {
        print_original_data(original_data[i]);
    }

    return 0;
}