//Falcon-180B DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

typedef struct {
    char name[20];
    int score;
} Player;

void shuffle(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        j = rand() % n;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int numPlayers;
    int round;

    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    for (int i = 0; i < MAX_ROUNDS; i++) {
        int scores[MAX_PLAYERS] = {0};

        printf("\nRound %d\n", i + 1);

        for (int j = 0; j < numPlayers; j++) {
            printf("Player %s, enter your score: ", players[j].name);
            scanf("%d", &scores[j]);
        }

        quickSort(scores, 0, numPlayers - 1);

        for (int j = 0; j < numPlayers; j++) {
            players[j].score += scores[j];
        }

        printf("\nScores after round %d:\n", i + 1);
        for (int j = 0; j < numPlayers; j++) {
            printf("Player %s: %d\n", players[j].name, players[j].score);
        }
    }

    return 0;
}