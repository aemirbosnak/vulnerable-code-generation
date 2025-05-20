//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLL_COUNT 5

int main(void) {
    char const * const roll_message = "Rolling the dice...\n";
    char const * const roll_results[ROLL_COUNT] = {
        "Snake Eyes! You rolled doubles on the first dice.\n",
        "You rolled a Double Three! The third dice showed up three times!\n",
        "You rolled a Four of a Kind! All dice showed the same number: %d\n",
        "You rolled a Full House! Two sets of doubles and three singles.\n",
        "You rolled a Small Straight! Consecutive numbers in a single roll.\n",
        "You rolled a Large Straight! Five dice showing consecutive numbers.\n",
        "You rolled a Yacht! Five dice showing the same number.\n"
    };

    int dice[ROLL_COUNT];
    int i, j, random_number;

    srand(time(NULL));

    printf("%s", roll_message);

    for (i = 0; i < ROLL_COUNT; i++) {
        dice[i] = rand() % 6 + 1;

        for (j = 0; j < i; j++) {
            if (dice[i] == dice[j]) {
                printf("%s", roll_results[0]);
                goto next_roll;
            }
        }

        switch (dice[i]) {
            case 1:
                printf("%s", roll_results[0]);
                goto next_roll;
            case 2:
                if (i == ROLL_COUNT - 1) {
                    printf("%s", roll_results[6]);
                    goto next_roll;
                }
                break;
            case 3:
                if (i > 0 && dice[i - 1] == dice[i]) {
                    printf("%s", roll_results[1]);
                    goto next_roll;
                }
                break;
            case 4:
                if (i > 0 && (dice[i - 1] == dice[i] || i < ROLL_COUNT - 1 && dice[i + 1] == dice[i])) {
                    sprintf(roll_results[3], "You rolled a Full House! Two sets of doubles and %d singles.\n", dice[i - 1] + dice[i + 1] - 2 * dice[i]);
                    printf("%s", roll_results[3]);
                    goto next_roll;
                }
                if (i == ROLL_COUNT - 1) {
                    printf("%s", roll_results[6]);
                    goto next_roll;
                }
                break;
            case 5:
                if (i > 0 && dice[i - 1] == dice[i]) {
                    printf("%s", roll_results[1]);
                    goto next_roll;
                }
                if (i < ROLL_COUNT - 1 && dice[i + 1] == dice[i]) {
                    printf("%s", roll_results[2]);
                    goto next_roll;
                }
                break;
            default:
                if (i < ROLL_COUNT - 1 && dice[i + 1] == dice[i] + 1) {
                    if (i == 0) {
                        printf("%s", roll_results[5]);
                        goto next_roll;
                    }
                    int previous_number = dice[i - 1];
                    int next_number = dice[i + 1];

                    if (previous_number < dice[i] && next_number > dice[i]) {
                        int consecutive_numbers_count = 1;
                        int current_number = dice[i];

                        for (int k = i + 1; k < ROLL_COUNT && dice[k] == current_number + 1; k++) {
                            consecutive_numbers_count++;
                        }

                        if (consecutive_numbers_count >= 4) {
                            printf("%s", roll_results[4]);
                            goto next_roll;
                        }
                    }
                }
                break;
        }

next_roll: {}
    }

    return 0;
}