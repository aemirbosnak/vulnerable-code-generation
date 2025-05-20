//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_N 100
#define MAX_P 50

int main() {
    int n, p;
    char name[MAX_N][MAX_P];
    char ghost[MAX_N][MAX_P];
    char color[MAX_N][MAX_P];

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please enter the number of players: ");
    scanf("%d", &n);

    printf("Enter the names of the players (up to %d characters):\n", MAX_P);
    for (int i = 0; i < n; i++) {
        scanf("%s", name[i]);
    }

    printf("Enter the names of the ghosts (up to %d characters):\n", MAX_P);
    for (int i = 0; i < n; i++) {
        scanf("%s", ghost[i]);
    }

    printf("Enter the colors of the ghosts (up to %d characters):\n", MAX_P);
    for (int i = 0; i < n; i++) {
        scanf("%s", color[i]);
    }

    printf("The players are %s.\n", name[0]);
    for (int i = 1; i < n; i++) {
        printf("The player %d is %s.\n", i, name[i]);
    }

    printf("The ghosts are %s.\n", ghost[0]);
    for (int i = 1; i < n; i++) {
        printf("The ghost %d is %s.\n", i, ghost[i]);
    }

    printf("The colors of the ghosts are %s.\n", color[0]);
    for (int i = 1; i < n; i++) {
        printf("The ghost %d is %s.\n", i, color[i]);
    }

    return 0;
}