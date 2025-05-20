//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_FACES 20

void displayHistogram(int rolls[], int rollCount);
void rollDice(int numDice, int numFaces, int *results);
void displayStatistics(int rollValue[], int rollCount);
void playDiceGame();

int main() {
    srand(time(NULL)); // Seed for random number generation
    printf("Welcome to the Dice Roller Game!\n");
    playDiceGame();
    return 0;
}

void playDiceGame() {
    int numDice;
    int numFaces;
    char choice;
    int rollValue[MAX_DICE] = {0};
    int rollCount = 0;

    do {
        printf("\nEnter the number of dice you want to roll (1-%d): ", MAX_DICE);
        scanf("%d", &numDice);
        while(numDice < 1 || numDice > MAX_DICE) {
            printf("Invalid number of dice. Please enter a value between 1 and %d: ", MAX_DICE);
            scanf("%d", &numDice);
        }

        printf("Enter the number of faces on the dice (6, 8, 10, 12, 20): ");
        scanf("%d", &numFaces);
        while(numFaces != 6 && numFaces != 8 && numFaces != 10 && numFaces != 12 && numFaces != 20) {
            printf("Invalid number of faces. Please enter one of these values: 6, 8, 10, 12, or 20: ");
            scanf("%d", &numFaces);
        }

        rollDice(numDice, numFaces, rollValue);
        rollCount += numDice;

        printf("You rolled: ");
        for(int i = 0; i < numDice; i++) {
            printf("%d ", rollValue[i]);
        }
        printf("\n");

        displayStatistics(rollValue, rollCount);
        displayHistogram(rollValue, rollCount);

        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');

    printf("Thank you for playing!\n");
}

void rollDice(int numDice, int numFaces, int *results) {
    for(int i = 0; i < numDice; i++) {
        results[i] = (rand() % numFaces) + 1; // Random number between 1 and numFaces
    }
}

void displayStatistics(int rollValue[], int rollCount) {
    int total = 0;
    for(int i = 0; i < rollCount; i++) {
        total += rollValue[i];
    }

    double average = (double)total / rollCount;
    printf("Total rolls: %d, Average roll: %.2f\n", rollCount, average);
}

void displayHistogram(int rolls[], int rollCount) {
    int histogram[MAX_FACES + 1] = {0};

    for(int i = 0; i < rollCount; i++) {
        if(rolls[i] <= MAX_FACES) {
            histogram[rolls[i]]++;
        }
    }

    printf("Rolls Histogram:\n");
    for(int i = 1; i <= MAX_FACES; i++) {
        if(histogram[i] > 0) {
            printf("%2d: ", i);
            for(int j = 0; j < histogram[i]; j++) {
                printf("*");
            }
            printf(" (%d)\n", histogram[i]);
        }
    }
}