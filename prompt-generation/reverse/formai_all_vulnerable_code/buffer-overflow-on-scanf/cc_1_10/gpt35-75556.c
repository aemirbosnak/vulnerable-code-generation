//FormAI DATASET v1.0 Category: Dice Roller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to the surprise dice roller!\n");
    printf("Are you ready to roll the dice? (y/n): ");

    char answer;
    scanf("%c", &answer);

    if (answer == 'y') {
        printf("\nGreat! Let's roll the dice!\n\n");
    } else if (answer == 'n') {
        printf("\nOh no, that's too bad! Maybe next time then.\n");
        return 0;
    } else {
        printf("\nSorry, I didn't understand that. Let's try again later.\n");
        return 0;
    }

    srand(time(NULL)); // Initialize random seed

    int rolls[6] = {0, 0, 0, 0, 0, 0}; // Initialize array to count dice rolls

    for (int i = 1; i <= 10; i++) {
        int dice = (rand() % 6) + 1; // Randomly generate a number between 1 and 6

        printf("Roll %d: %d\n", i, dice);

        // Increment counter in array
        switch (dice) {
            case 1:
                rolls[0]++;
                break;
            case 2:
                rolls[1]++;
                break;
            case 3:
                rolls[2]++;
                break;
            case 4:
                rolls[3]++;
                break;
            case 5:
                rolls[4]++;
                break;
            case 6:
                rolls[5]++;
                break;
            default:
                break;
        }
    }

    // Display roll frequencies
    printf("\nRoll frequencies:\n");
    printf("1: %d\n", rolls[0]);
    printf("2: %d\n", rolls[1]);
    printf("3: %d\n", rolls[2]);
    printf("4: %d\n", rolls[3]);
    printf("5: %d\n", rolls[4]);
    printf("6: %d\n", rolls[5]);

    printf("\nWow, that was surprising! I hope you had fun rolling the dice.\n");

    return 0;
}