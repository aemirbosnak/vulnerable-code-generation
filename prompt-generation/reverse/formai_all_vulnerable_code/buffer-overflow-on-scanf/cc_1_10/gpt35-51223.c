//FormAI DATASET v1.0 Category: Dice Roller ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int roll_dice(void); // function prototype

int main(void)
{
    int total, point;
    int win_count = 0, loss_count = 0;
    char ans;

    srand(time(NULL)); // seed the random number generator

    do {
        total = roll_dice();
        printf("You rolled: %d\n", total);

        switch(total) {
            case 7: case 11:
                printf("You win!\n");
                win_count++;
                break;
            case 2: case 3: case 12:
                printf("You lose!\n");
                loss_count++;
                break;
            default:
                point = total;
                printf("Your point is %d\n", point);
                while(1) {
                    total = roll_dice();
                    printf("You rolled: %d\n", total);
                    if(total == point) {
                        printf("You win!\n");
                        win_count++;
                        break;
                    } else if(total == 7) {
                        printf("You lose!\n");
                        loss_count++;
                        break;
                    }
                }
                break;
        }

        printf("Play again? (y/n): ");
        scanf(" %c", &ans);
    } while(ans == 'y' || ans == 'Y');

    printf("Wins: %d Losses: %d\n", win_count, loss_count);
    printf("Goodbye!\n");

    return 0;
}

int roll_dice(void)
{
    int roll1, roll2;

    roll1 = rand() % 6 + 1;
    roll2 = rand() % 6 + 1;

    return roll1 + roll2;
}