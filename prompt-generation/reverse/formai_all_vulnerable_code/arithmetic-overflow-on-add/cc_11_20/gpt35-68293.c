//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int birthMonth, birthDay, birthYear, luckyNum, num1, num2, num3, num4, num5;
    int fortuneNum, total, luckyIndex, i;
    char fortuneText[200];

    printf("Welcome to the Automated Fortune Teller! Please enter your name: ");
    scanf("%s", name);

    printf("\nHello %s! Let's start with your birth date.\n", name);

    printf("Please enter your birth month (1-12): ");
    scanf("%i", &birthMonth);
    printf("Please enter your birth day (1-31): ");
    scanf("%i", &birthDay);
    printf("Please enter your birth year (e.g. 1990): ");
    scanf("%i", &birthYear);

    printf("\nNext, I need your lucky number: ");
    scanf("%i", &luckyNum);

    printf("\nExcellent! Now I need 5 more numbers between 1 and 99.\n\n");
    printf("Number 1: ");
    scanf("%i", &num1);
    printf("Number 2: ");
    scanf("%i", &num2);
    printf("Number 3: ");
    scanf("%i", &num3);
    printf("Number 4: ");
    scanf("%i", &num4);
    printf("Number 5: ");
    scanf("%i", &num5);

    srand(time(NULL));

    fortuneNum = rand() % 100 + 1;

    // Calculate the total of the user's birth date
    total = birthMonth + birthDay + birthYear;

    // Calculate the lucky index
    luckyIndex = rand() % 6;

    // Generate the fortune text based on the lucky index
    switch (luckyIndex) {
        case 0:
            sprintf(fortuneText, "%s, you will %s day become very wealthy.", name, fortuneNum > 50 ? "one" : "some");
            break;
        case 1:
            sprintf(fortuneText, "%s, your lucky number is %i. This number will bring you %s.", name, luckyNum, fortuneNum > 50 ? "happiness" : "success");
            break;
        case 2:
            sprintf(fortuneText, "%s, your lucky numbers are %i, %i, %i, %i, %i. Keep these numbers in mind for the future.", name, num1, num2, num3, num4, num5);
            break;
        case 3:
            sprintf(fortuneText, "Beware, %s! Your fortune is %i. This number brings %s.", name, fortuneNum, fortuneNum > 50 ? "danger" : "misfortune");
            break;
        case 4:
            sprintf(fortuneText, "%s, your total birth date is %i. This number represents %s.", name, total, fortuneNum > 50 ? "wisdom" : "enlightenment");
            break;
        case 5:
            sprintf(fortuneText, "%s, you will %s day meet the love of your life.", name, fortuneNum > 50 ? "soon" : "eventually");
            break;
    }

    printf("\n\nYour fortune for today is:\n%s\n\n", fortuneText);

    printf("Thank you for using the Automated Fortune Teller. Goodbye!");

    return 0;
}