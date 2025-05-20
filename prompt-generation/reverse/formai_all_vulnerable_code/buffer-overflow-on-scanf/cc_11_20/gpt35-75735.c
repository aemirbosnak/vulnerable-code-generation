//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int yearBorn = 0, age = 0, favNum = 0, luckyNum = 0, predictedSum = 0;

    printf("Greetings! I am the Automated Fortune Teller, Sherlock Holmes Edition. ");
    printf("Please answer a few questions for me to predict your future.\n\n");

    printf("What year were you born in? ");
    scanf("%d", &yearBorn);

    age = 2021 - yearBorn;

    printf("What is your favorite number? ");
    scanf("%d", &favNum);

    printf("Now, pick a lucky number from 1 to 10. ");
    scanf("%d", &luckyNum);

    printf("\nLet me calculate your future...\n\n");

    //Different possible outcomes depending on luckyNum
    switch(luckyNum) {
        case 1: 
            predictedSum = age + favNum + 7;
            printf("You will live a long and happy life with a total of %d years.\n", predictedSum);
            break;
        case 2:
            predictedSum = age + favNum + 13;
            printf("You will experience a major life change in %d years.\n", predictedSum);
            break;
        case 3:
            predictedSum = age + favNum + 22;
            printf("You will come into a significant amount of wealth in %d years.\n", predictedSum);
            break;
        case 4:
            predictedSum = age + favNum + 9;
            printf("You will find true love and settle down in %d years.\n", predictedSum);
            break;
        case 5:
            predictedSum = age + favNum + 17;
            printf("You will travel to far-off lands and have many adventures in %d years.\n", predictedSum);
            break;
        case 6:
            predictedSum = age + favNum + 4;
            printf("You will experience a great loss in %d years, but will come out stronger.\n", predictedSum);
            break;
        case 7:
            predictedSum = age + favNum + 11;
            printf("You will achieve great success in your career in %d years.\n", predictedSum);
            break;
        case 8:
            predictedSum = age + favNum + 3;
            printf("You will face a major challenge in %d years, but will overcome it.\n", predictedSum);
            break;
        case 9:
            predictedSum = age + favNum + 19;
            printf("You will find your calling in life and pursue it with passion in %d years.\n", predictedSum);
            break;
        case 10:
            predictedSum = age + favNum + 14;
            printf("You will enter into a period of great creativity and productivity in %d years.\n", predictedSum);
            break;
        default:
            printf("Invalid lucky number. Please try again.\n");
            break;
    }

    return 0;
}