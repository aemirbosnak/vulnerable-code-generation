//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int age;
    int lucky_num;
    int current_year;
    int birth_year;
    int sum = 0;
    int prediction;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    fgets(name, 20, stdin);
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your lucky number: ");
    scanf("%d", &lucky_num);
    printf("Please enter the current year: ");
    scanf("%d", &current_year);
    printf("Please enter your birth year: ");
    scanf("%d", &birth_year);

    sum = sum_digits(birth_year);

    prediction = ((age + sum) * (lucky_num % 10)) % 100;

    printf("\nHello %s, your fortune for the year %d is:\n", name, current_year);
    switch(prediction) {
        case 0:
            printf("It looks like this will be a neutral year for you.\n");
            break;
        case 1:
            printf("This year will bring you unexpected blessings.\n");
            break;
        case 2:
            printf("You will need to put in hard work and determination to achieve your goals this year.\n");
            break;
        case 3:
            printf("This year will bring good fortune for your financial situation.\n");
            break;
        case 4:
            printf("You will meet someone special this year, or your current relationship will deepen.\n");
            break;
        case 5:
            printf("A major change is coming this year, be ready to adapt.\n");
            break;
        case 6:
            printf("Your health will be a priority this year, make sure to take care of yourself.\n");
            break;
        case 7:
            printf("This year will bring opportunities for travel and adventure.\n");
            break;
        case 8:
            printf("Your creativity and artistry will be at an all-time high this year, take advantage of it.\n");
            break;
        case 9:
            printf("You will need to work on your communication skills this year to avoid misunderstandings.\n");
            break;
        default:
            printf("Sorry, I could not predict your fortune for this year. Please try again.\n");
    }

    return 0;
}

int sum_digits(int num) {
    int sum = 0;
    while(num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}