//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 3

void generate_number(int *number) {
    *number = rand() % 11 + 1;
}

void print_number(int number) {
    printf("Number: %d\n", number);
}

void print_status(int status) {
    switch (status) {
        case 0:
            printf("Invalid input, try again.\n");
            break;
        case 1:
            printf("Correct! The number was even.\n");
            break;
        case 2:
            printf("Correct! The number was odd.\n");
            break;
        case 3:
            printf("Game over. Better luck next time!\n");
            break;
    }
}

int main() {
    int number, player_guess, status;
    int tries = 0;

    srand(time(NULL));

    while (1) {
        generate_number(&number);

        printf("Is the number even or odd? (e/o): ");
        scanf("%c", &player_guess);

        if (player_guess == 'e') {
            if (number % 2 == 0) {
                print_status(1);
                break;
            } else {
                print_status(0);
                tries++;
                if (tries >= MAX_TRIES) {
                    print_status(3);
                    break;
                }
            }
        } else if (player_guess == 'o') {
            if (number % 2 != 0) {
                print_status(2);
                break;
            } else {
                print_status(0);
                tries++;
                if (tries >= MAX_TRIES) {
                    print_status(3);
                    break;
                }
            }
        } else {
            print_status(0);
            tries++;
            if (tries >= MAX_TRIES) {
                print_status(3);
                break;
            }
        }

        print_number(number);
    }

    return 0;
}