//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables
    char name[20];
    int age, num, fortuneNum;
    srand(time(NULL)); // Seed the random generator

    // Start the program
    printf("Welcome to the Automated Fortune Teller Program!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your age: ");
    scanf("%d", &age);

    // Determine the user's lucky number
    if (age <= 25) {
        num = rand() % 5 + 7;
    } else if (age <= 50) {
        num = rand() % 4 + 4;
    } else {
        num = rand() % 3 + 1;
    }

    // Generate the fortune number
    fortuneNum = num * rand() % 101;

    // Display the fortune message
    printf("\n%s, your lucky number is %d and your fortune number is %d!\n", name, num, fortuneNum);

    switch (fortuneNum % 5) {
        case 0:
            printf("You will find peace in your life, and everything will fall into place.\n");
            break;
        case 1:
            printf("Your future looks bright with many opportunities in store for you.\n");
            break;
        case 2:
            printf("Don't be afraid of taking on new challenges, as they will lead you to success.\n");
            break;
        case 3:
            printf("Be patient and trust the process, as everything will work out in your favor.\n");
            break;
        case 4:
            printf("Unexpected changes are coming your way, but they will bring positive outcomes.\n");
            break;
    }

    printf("\nThank you for using Automated Fortune Teller Program! Have a nice day!\n");

    return 0;
}