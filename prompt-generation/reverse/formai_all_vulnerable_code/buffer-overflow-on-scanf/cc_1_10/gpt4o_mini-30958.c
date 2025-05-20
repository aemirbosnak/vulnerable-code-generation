//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCORE 100
#define NUM_BUCKETS 10

typedef struct Player {
    char name[50];
    int score;
} Player;

typedef struct Bucket {
    Player players[NUM_BUCKETS];
    int count;
} Bucket;

// Function to initialize buckets
void initializeBuckets(Bucket buckets[NUM_BUCKETS]) {
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i].count = 0;
    }
}

// Function to calculate the bucket index
int getBucketIndex(int score) {
    return score / (MAX_SCORE / NUM_BUCKETS);
}

// Function to add a player to a bucket
void addPlayerToBucket(Bucket *bucket, Player player) {
    if (bucket->count < NUM_BUCKETS) {
        bucket->players[bucket->count] = player;
        bucket->count++;
    } else {
        printf("Bucket is full!\n");
    }
}

// Function to sort players within a bucket
void insertionSort(Player players[], int n) {
    for (int i = 1; i < n; i++) {
        Player key = players[i];
        int j = i - 1;
        while (j >= 0 && players[j].score > key.score) {
            players[j + 1] = players[j];
            j--;
        }
        players[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(Player players[], int n, Bucket buckets[NUM_BUCKETS]) {
    // Step 1: Initialize buckets
    initializeBuckets(buckets);

    // Step 2: Distribute players into buckets
    for (int i = 0; i < n; i++) {
        int index = getBucketIndex(players[i].score);
        addPlayerToBucket(&buckets[index], players[i]);
    }

    // Step 3: Sort individual buckets and gather the results
    int k = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        if (buckets[i].count > 0) {
            insertionSort(buckets[i].players, buckets[i].count);
            for (int j = 0; j < buckets[i].count; j++) {
                players[k++] = buckets[i].players[j];
            }
        }
    }
}

// Function to print players
void printPlayers(Player players[], int n) {
    printf("Players sorted by scores:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Score: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    int numPlayers;

    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);
    
    Player *players = malloc(numPlayers * sizeof(Player));
    
    if (players == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input player names and scores
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        printf("Enter score for player %d (0-%d): ", i + 1, MAX_SCORE);
        scanf("%d", &players[i].score);
        while (players[i].score < 0 || players[i].score > MAX_SCORE) {
            printf("Invalid score. Please enter a score between 0 and %d: ", MAX_SCORE);
            scanf("%d", &players[i].score);
        }
    }

    Bucket buckets[NUM_BUCKETS];
    bucketSort(players, numPlayers, buckets);

    // Print sorted players
    printPlayers(players, numPlayers);

    // Free allocated memory
    free(players);
    return 0;
}