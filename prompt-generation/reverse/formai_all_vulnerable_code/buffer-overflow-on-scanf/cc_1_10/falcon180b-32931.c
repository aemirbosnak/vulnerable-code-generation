//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int roll;
    int sides = 6;
    char choice;
    srand(time(NULL));

    do {
        printf("Welcome to the Dice Roller!\n");
        printf("What kind of dice do you want to roll?\n");
        printf("1. Six-sided\n");
        printf("2. Eight-sided\n");
        printf("3. Ten-sided\n");
        printf("4. Twelve-sided\n");
        printf("5. Twenty-sided\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                sides = 6;
                break;
            case '2':
                sides = 8;
                break;
            case '3':
                sides = 10;
                break;
            case '4':
                sides = 12;
                break;
            case '5':
                sides = 20;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        roll = rand() % sides + 1;
        printf("You rolled a %d on a %d-sided dice!\n", roll, sides);
        printf("Do you want to roll again? (y/n)\n");
        scanf("%c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}