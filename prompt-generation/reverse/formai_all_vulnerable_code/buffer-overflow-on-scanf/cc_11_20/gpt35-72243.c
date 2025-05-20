//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int birthYear, age, luckyNum, randomNum, predictionNum;

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your birth year (YYYY): ");
    scanf("%d", &birthYear);
    age = 2021 - birthYear;
    printf("Please enter your lucky number (1-10): ");
    scanf("%d", &luckyNum);

    printf("\n\nCalculating your fortune...\n\n");

    srand(time(NULL));
    randomNum = rand() % 10 + 1;

    predictionNum = (luckyNum + randomNum) % 10;

    printf("Dear %s, your fortune for today is:\n", name);

    switch (predictionNum) {
    case 0:
        printf("You will have a great day today!\n");
        break;
    case 1:
        printf("You will get a promotion at work!\n");
        break;
    case 2:
        printf("You will meet someone special today!\n");
        break;
    case 3:
        printf("You will receive good news by the end of the day!\n");
        break;
    case 4:
        printf("You will find a solution to a problem that has been bothering you!\n");
        break;
    case 5:
        printf("You will have a stroke of luck at a casino or lottery!\n");
        break;
    case 6:
        printf("You will travel to a foreign country soon!\n");
        break;
    case 7:
        printf("You will be successful in an important project!\n");
        break;
    case 8:
        printf("You will make a new friend today!\n");
        break;
    case 9:
        printf("You will have a romantic date tonight!\n");
        break;
    }

    printf("\n\nThank you for using the Automated Fortune Teller!\n");

    return 0;
}