//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char sign;
    int number;
    int result;

    printf("Would you like to have your fortune told? (Y/N): ");
    scanf("%c", &sign);

    if (sign == 'Y') {
        printf("Please enter a number between 1 and 10: ");
        scanf("%d", &number);

        srand(time(NULL));
        result = rand() % 11 + 1;

        switch (result) {
            case 1:
                printf("Your future is bright, my dear.");
                break;
            case 2:
                printf("You will find love and happiness.");
                break;
            case 3:
                printf("Your wealth will grow rapidly.");
                break;
            case 4:
                printf("You will travel to distant lands.");
                break;
            case 5:
                printf("You will have a long and healthy life.");
                break;
            case 6:
                printf("You will face challenges, but overcome them.");
                break;
            case 7:
                printf("You will have a creative spark and inspire others.");
                break;
            case 8:
                printf("You will find wisdom and knowledge.");
                break;
            case 9:
                printf("You will have a spiritual awakening.");
                break;
            case 10:
                printf("You will achieve your goals and dreams.");
                break;
        }
    } else {
        printf("Thank you for your time. Come back again soon.");
    }

    return 0;
}