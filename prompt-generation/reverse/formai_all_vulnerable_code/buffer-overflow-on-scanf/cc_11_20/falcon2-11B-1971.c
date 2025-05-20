//Falcon2-11B DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int number = -1;

    printf("Welcome to the Fortune Teller!\n");
    printf("Please enter a number between 1 and 10:\n");
    scanf("%d", &number);

    if (number < 1 || number > 10) {
        printf("Invalid input! Please enter a number between 1 and 10.\n");
        return 1;
    }

    switch (number) {
        case 1:
            printf("Your fortune is: 'You will find love today.'\n");
            break;
        case 2:
            printf("Your fortune is: 'You will have a prosperous day.'\n");
            break;
        case 3:
            printf("Your fortune is: 'Your hard work will pay off.'\n");
            break;
        case 4:
            printf("Your fortune is: 'You will receive good news today.'\n");
            break;
        case 5:
            printf("Your fortune is: 'You will have an adventurous day.'\n");
            break;
        case 6:
            printf("Your fortune is: 'You will receive a surprise gift.'\n");
            break;
        case 7:
            printf("Your fortune is: 'You will have a peaceful day.'\n");
            break;
        case 8:
            printf("Your fortune is: 'You will find a new opportunity today.'\n");
            break;
        case 9:
            printf("Your fortune is: 'You will meet someone special today.'\n");
            break;
        case 10:
            printf("Your fortune is: 'You will have a successful day.'\n");
            break;
        default:
            printf("Invalid input! Please enter a number between 1 and 10.\n");
            return 1;
    }

    printf("Do you want to try again? (y/n): ");
    char answer;
    scanf(" %c", &answer);

    if (answer == 'y') {
        main();
    } else {
        printf("Thank you for using the Fortune Teller! Goodbye!\n");
    }

    return 0;
}