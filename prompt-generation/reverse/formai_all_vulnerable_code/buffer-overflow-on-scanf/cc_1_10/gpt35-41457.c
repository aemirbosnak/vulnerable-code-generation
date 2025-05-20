//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void travel(int* year, char* player) {
    int choice;
    printf("%s, select a year to travel:\n", player);
    printf("1. 1960\n");
    printf("2. 1980\n");
    printf("3. 2000\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            *year = 1960;
            printf("%s has traveled to the year 1960.\n", player);
            break;
        case 2:
            *year = 1980;
            printf("%s has traveled to the year 1980.\n", player);
            break;
        case 3:
            *year = 2000;
            printf("%s has traveled to the year 2000.\n", player);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    int year = rand() % 2000;
    char player1[20], player2[20];
    printf("Enter Player 1 name: ");
    scanf("%s", player1);
    printf("Enter Player 2 name: ");
    scanf("%s", player2);

    while (1) {
        travel(&year, player1);
        printf("%s is now in the year %d.\n", player1, year);
        travel(&year, player2);
        printf("%s is now in the year %d.\n", player2, year);
        if (year == 1960) {
            printf("The game has ended. %s has won!\n", player1);
            break;
        } else if (year == 1980) {
            printf("The game has ended. %s has won!\n", player2);
            break;
        } else if (year == 2000) {
            printf("The game has ended in a tie.\n");
            break;
        }
    }
    return 0;
}