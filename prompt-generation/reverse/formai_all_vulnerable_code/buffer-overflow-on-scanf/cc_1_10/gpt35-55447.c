//FormAI DATASET v1.0 Category: Table Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
int play_game(void);
void print_rules(void);

int main(void) {
    char play_again;
    srand((unsigned) time(NULL));
    printf("Welcome to the C Table Game!\n");
    do {
        play_game();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');
    printf("Thank you for playing the C Table Game!\n");
    return 0;
}

int roll_dice(void) {
    return (rand() % 6) + 1;
}

int play_game(void) {
    int point = 0, roll, sum;
    char play;
    printf("\n===========\nLet's Play!\n===========\n");
    if (point == 0) {
        do {
            sum = roll_dice() + roll_dice();
            printf("You rolled: %d\n", sum);
            if (sum == 7 || sum == 11) {
                printf("Congratulations! You win!\n");
                return 1;
            } else if (sum == 2 || sum == 3 || sum == 12) {
                printf("Sorry, you lose.\n");
                return 0;
            } else {
                point = sum;
                printf("Your point is: %d\n", point);
            }
        } while (point == sum);
    }
    do {
        roll = roll_dice() + roll_dice();
        printf("You rolled: %d\n", roll);
        if (roll == point) {
            printf("Congratulations! You win!\n");
            return 1;
        } else if (roll == 7) {
            printf("Sorry, you lose.\n");
            return 0;
        }
    } while (1);
}

void print_rules(void) {
    printf("=====================================\n");
    printf("Welcome to the C Table Game!\n");
    printf("=====================================\n");
    printf("Rules:\n");
    printf("1. The shooter rolls two dice.\n");
    printf("2. If the first roll is a 7 or 11, the shooter wins.\n");
    printf("3. If the first roll is a 2, 3, or 12, the shooter loses.\n");
    printf("4. If the first roll is anything else, that number becomes the shooter's point.\n");
    printf("5. The shooter continues to roll the dice until either the point is rolled again (win) or a 7 is rolled (lose).\n");
    printf("=====================================\n");
}