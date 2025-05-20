//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int n;
    double result = 0.0;
    int choice;
    int i = 0;
    int sum = 0;
    int count = 0;
    int num[100];
    int random_num;

    srand(time(NULL));

    printf("Welcome to the Arithmetic Game!\n\n");

    while (i < 10) {
        printf("You have %d attempts left.\n", 10 - i);
        printf("Please enter a number between 1 and 100: ");
        scanf("%d", &n);

        if (n < 1 || n > 100) {
            printf("Invalid input. Please try again.\n");
        } else {
            i++;
            printf("You entered: %d\n", n);

            switch (n) {
                case 1:
                    result = 0.0;
                    break;
                case 2:
                    result = 1.0;
                    break;
                case 3:
                    result = 2.0;
                    break;
                case 4:
                    result = 3.0;
                    break;
                case 5:
                    result = 4.0;
                    break;
                case 6:
                    result = 5.0;
                    break;
                case 7:
                    result = 6.0;
                    break;
                case 8:
                    result = 7.0;
                    break;
                case 9:
                    result = 8.0;
                    break;
                case 10:
                    result = 9.0;
                    break;
                default:
                    result = 0.0;
                    break;
            }

            printf("The result is: %.2lf\n", result);

            if (result == 0.0) {
                printf("You lose. Game over.\n");
            } else {
                printf("You win! Would you like to play again? (y/n) ");
                scanf(" %c", &choice);

                if (choice == 'y') {
                    i = 0;
                } else {
                    printf("Thank you for playing.\n");
                    exit(0);
                }
            }
        }
    }

    return 0;
}