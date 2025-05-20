//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multiplayer
// Multiplayer C Metadata Extractor Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

struct player {
    char name[MAX_NAME_LENGTH];
    int age;
    float rating;
};

struct metadata {
    int num_players;
    struct player players[MAX_PLAYERS];
};

struct metadata extract_metadata(char* file_name) {
    struct metadata mdata;
    FILE* fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Error: could not open file!\n");
        exit(1);
    }

    fscanf(fp, "%d", &(mdata.num_players));

    for (int i = 0; i < mdata.num_players; i++) {
        fscanf(fp, "%s %d %f", mdata.players[i].name, &(mdata.players[i].age), &(mdata.players[i].rating));
    }

    fclose(fp);
    return mdata;
}

void print_metadata(struct metadata mdata) {
    printf("Number of Players: %d\n", mdata.num_players);

    for (int i = 0; i < mdata.num_players; i++) {
        printf("Player %d: %s, Age: %d, Rating: %.2f\n", i+1, mdata.players[i].name, mdata.players[i].age, mdata.players[i].rating);
    }
}

int main() {
    char file_name[20];
    printf("Enter file name: ");
    scanf("%s", file_name);

    struct metadata mdata = extract_metadata(file_name);
    print_metadata(mdata);
    
    return 0;
}