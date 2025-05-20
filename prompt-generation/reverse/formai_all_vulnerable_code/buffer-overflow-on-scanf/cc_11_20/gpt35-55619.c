//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int fortuneNumber = rand() % 5;

    switch(fortuneNumber) {
        case 0:
            printf("I see success in your future!\n");
            break;
        case 1:
            printf("Beware of those who try to deceive you.\n");
            break;
        case 2:
            printf("Love is in the air for you!\n");
            break;
        case 3:
            printf("Your hard work will pay off soon.\n");
            break;
        case 4:
            printf("You will travel to a far-off land in the near future.\n");
            break;
        default:
            printf("Error: Invalid fortune number.\n");
            break;
    }

    printf("Do you want to ask another question? (Y/N)\n");

    char answer;
    scanf("%s", &answer);

    while(answer == 'Y' || answer == 'y') {

        fortuneNumber = rand() % 5;

        switch(fortuneNumber) {
            case 0:
                printf("I see success in your future!\n");
                break;
            case 1:
                printf("Beware of those who try to deceive you.\n");
                break;
            case 2:
                printf("Love is in the air for you!\n");
                break;
            case 3:
                printf("Your hard work will pay off soon.\n");
                break;
            case 4:
                printf("You will travel to a far-off land in the near future.\n");
                break;
            default:
                printf("Error: Invalid fortune number.\n");
                break;
        }

        printf("Do you want to ask another question? (Y/N)\n");
        scanf("%s", &answer);
    }

    printf("Thank you for using the Automated Fortune Teller! Goodbye.\n");

    return 0;
}