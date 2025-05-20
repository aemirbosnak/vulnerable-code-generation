//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int numPlayers, i, j;
    char *units[10];
    char input[100];
    char commonUnit[10];
    char *tempUnit;

    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    for (i = 0; i < numPlayers; i++) {
        printf("Player %d, enter your input: ", i + 1);
        scanf("%s", input);

        if (strlen(input) < 2) {
            printf("Invalid input\n");
            continue;
        }

        if (strlen(input) > 2) {
            tempUnit = strtok(input, " ");
            units[i] = strdup(tempUnit);
            tempUnit = strtok(NULL, " ");
            units[i] = strdup(tempUnit);
        } else {
            units[i] = strdup(input);
        }
    }

    for (i = 0; i < numPlayers; i++) {
        for (j = 0; j < numPlayers; j++) {
            if (strcmp(units[i], units[j]) == 0) {
                printf("Units %s and %s are the same\n", units[i], units[j]);
            }
        }
    }

    printf("Enter the common unit: ");
    scanf("%s", commonUnit);

    for (i = 0; i < numPlayers; i++) {
        printf("Player %d, convert your input to %s:\n", i + 1, commonUnit);
        scanf("%s", input);

        if (strlen(input) < 2) {
            printf("Invalid input\n");
            continue;
        }

        if (strlen(input) > 2) {
            tempUnit = strtok(input, " ");
            units[i] = strdup(tempUnit);
            tempUnit = strtok(NULL, " ");
            units[i] = strdup(tempUnit);
        } else {
            units[i] = strdup(input);
        }
    }

    for (i = 0; i < numPlayers; i++) {
        for (j = 0; j < numPlayers; j++) {
            if (strcmp(units[i], units[j]) == 0) {
                printf("Units %s and %s are the same\n", units[i], units[j]);
            }
        }
    }

    for (i = 0; i < numPlayers; i++) {
        printf("Player %d, the converted input is: %s\n", i + 1, units[i]);
    }

    return 0;
}