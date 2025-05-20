//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

void printFortune(int num) {
    switch (num) {
        case 1:
            printf("You will have a great fortune this year!\n");
            break;
        case 2:
            printf("Your hard work will pay off soon!\n");
            break;
        case 3:
            printf("You will meet someone special soon!\n");
            break;
        case 4:
            printf("Be careful with your finances this month.\n");
            break;
        case 5:
            printf("Your creativity will bring you success!\n");
            break;
        default:
            printf("Sorry, I cannot predict your fortune.\n");
            break;
    }
}

int main(void) {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will predict your future based on a random number.\n\n");

    char name[50];
    printf("Please enter your name: ");
    scanf("%s", name);

    int luckyNumber;
    printf("Please enter your lucky number (between 1 - 10): ");
    scanf("%d", &luckyNumber);

    printf("\nThank you, %s. Let's see what the future holds for you.\n", name);

    int fortuneNum = getRandomNumber(1, 5); // Generate a random number between 1 - 5

    if (fortuneNum == luckyNumber) {
        printf("Wow, your lucky number matches your fortune number!\n");
    }

    printf("Your fortune number is: %d\n", fortuneNum);
    printFortune(fortuneNum); // Print the corresponding fortune based on number

    printf("\nThank you for using the Automated Fortune Teller. Goodbye!\n");

    return 0;
}