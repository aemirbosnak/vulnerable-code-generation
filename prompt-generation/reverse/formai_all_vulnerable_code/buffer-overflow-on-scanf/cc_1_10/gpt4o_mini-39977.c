//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

// Declaration of struct to hold player details
typedef struct {
    char name[20];
    int card[SIZE][SIZE];
    int marked[SIZE][SIZE];
} Player;

// Function to initialize player's Bingo card
void initializeCard(Player* player) {
    int nums[75] = {0};
    int count = 0;

    while (count < SIZE * SIZE) {
        int num = rand() % 75 + 1;
        if (nums[num - 1] == 0) {
            nums[num - 1] = 1;
            player->card[count / SIZE][count % SIZE] = num;
            player->marked[count / SIZE][count % SIZE] = 0; // Not marked initially
            count++;
        }
    }
}

// Function to print Bingo card
void printCard(Player* player) {
    printf("Alas! Behold the Bingo Card of %s:\n", player->name);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (player->marked[i][j])
                printf("[X] ");
            else
                printf("[%d] ", player->card[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to draw a number
int drawNumber(int* drawnNumbers) {
    int num;
    do {
        num = rand() % 75 + 1;
    } while (drawnNumbers[num - 1]);
    drawnNumbers[num - 1] = 1; // Mark number as drawn
    return num;
}

// Function to check if player has won
int checkWin(Player* player) {
    for (int i = 0; i < SIZE; i++) {
        int rowWin = 1;
        for (int j = 0; j < SIZE; j++) {
            if (!player->marked[i][j]) {
                rowWin = 0;
                break;
            }
        }
        if (rowWin) return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        int colWin = 1;
        for (int j = 0; j < SIZE; j++) {
            if (!player->marked[j][i]) {
                colWin = 0;
                break;
            }
        }
        if (colWin) return 1;
    }
    return 0; // No win
}

int main() {
    // Initialization
    srand(time(0));
    Player romeo, juliet;
    int drawnNumbers[75] = {0};
    char playAgain;

    // Player Setup
    printf("Enter the name of the fair Romeo: ");
    scanf("%s", romeo.name);
    initializeCard(&romeo);

    printf("And who might be the enchanting Juliet? ");
    scanf("%s", juliet.name);
    initializeCard(&juliet);

    do {
        int number;
        printf("\n\nThe wheel of fate begins to spin...\n");
        number = drawNumber(drawnNumbers);
        printf("A number is drawn from the depths of chance: %d\n", number);
        
        // Mark numbers on both cards
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if (romeo.card[i][j] == number) {
                    romeo.marked[i][j] = 1; // Marked
                }
                if (juliet.card[i][j] == number) {
                    juliet.marked[i][j] = 1; // Marked
                }
            }
        }

        // Prints the cards
        printCard(&romeo);
        printCard(&juliet);

        // Check for victory
        if (checkWin(&romeo)) {
            printf("Hark! %s hath claimed victory!\n", romeo.name);
            break;
        }
        if (checkWin(&juliet)) {
            printf("Lo and behold! %s triumphs in this fate!\n", juliet.name);
            break;
        }

        printf("Shall we draw another number? (Y/N): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'Y' || playAgain == 'y');

    printf("The game hath ended, as all stories must.\n");
    return 0;
}