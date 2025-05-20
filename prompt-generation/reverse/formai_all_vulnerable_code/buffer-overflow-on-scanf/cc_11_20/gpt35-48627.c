//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n, i;
    char response;

    printf("Welcome to the Automated Fortune Teller! \n");

    do {
        printf("Please enter a number between 1 and 10: ");
        scanf("%d", &n);

        if (n < 1 || n > 10) {
            printf("Invalid input. Please try again. \n");
            continue;
        }

        srand(time(NULL));
        i = rand() % 7;

        switch(i) {
            case 0:
                printf("Your future looks bright. \n");
                break;
            case 1:
                printf("You will experience unexpected joy. \n");
                break;
            case 2:
                printf("A new opportunity will arise soon. \n");
                break;
            case 3:
                printf("Take risks, it will pay off in the end. \n");
                break;
            case 4:
                printf("Your hard work will pay off in the future. \n");
                break;
            case 5:
                printf("Your love life will improve. \n");
                break;
            case 6:
                printf("Be cautious of betrayal from a friend. \n");
                break;
        }

        printf("Would you like another fortune? (Y/N) ");
        scanf(" %c", &response);

    } while (response == 'y' || response == 'Y');

    printf("Thank you for using the Automated Fortune Teller! \n");

    return 0;
}