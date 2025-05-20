//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int option, num;
    srand(time(0));

    printf("Welcome to the Automated Fortune Teller Program!\n");
    printf("Choose an option:\n");
    printf("1. Get a random fortune\n");
    printf("2. Get a fortune based on your lucky number\n");
    printf("Option: ");
    scanf("%d", &option);
    printf("\n");

    switch(option) {
        case 1:
            num = rand() % 5;

            switch(num) {
                case 0:
                    printf("You will find happiness in your career.\n");
                    break;
                case 1:
                    printf("A new opportunity will present itself in the next few days.\n");
                    break;
                case 2:
                    printf("You will meet someone special soon.\n");
                    break;
                case 3:
                    printf("You will achieve your goals with hard work and determination.\n");
                    break;
                case 4:
                    printf("A new adventure awaits you.\n");
                    break;
            }
            break;
        case 2:
            printf("Enter your lucky number: ");
            scanf("%d", &num);
            printf("\n");

            switch(num) {
                case 1:
                    printf("You will have good luck in your future endeavors.\n");
                    break;
                case 2:
                    printf("Your hard work will pay off soon.\n");
                    break;
                case 3:
                    printf("Unexpected good news is coming your way.\n");
                    break;
                case 4:
                    printf("A new romance will blossom in your life.\n");
                    break;
                case 5:
                    printf("You will be successful in all your endeavors.\n");
                    break;
                default:
                    printf("Sorry, your lucky number is not associated with a fortune in our system.\n");
                    break;
            }
            break;
        default:
            printf("Invalid option selected.\n");
            break;
    }

    return 0;
}