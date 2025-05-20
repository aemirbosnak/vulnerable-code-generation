//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int age, lucky_number, birth_date, birth_month, birth_year;

    printf("Welcome to the Automated Fortune Teller! \n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your lucky number: ");
    scanf("%d", &lucky_number);
    printf("Please enter your birth date (1-31): ");
    scanf("%d", &birth_date);
    printf("Please enter your birth month (1-12): ");
    scanf("%d", &birth_month);
    printf("Please enter your birth year: ");
    scanf("%d", &birth_year);

    // Generate a random number for fortune telling
    srand(time(0));
    int random_number = rand() % 10 + 1;

    printf("\nWelcome %s! Here is your automated fortune:\n\n", name);

    switch(random_number) {
        case 1:
            printf("You will receive great news about your career today!\n");
            break;
        case 2:
            printf("Your lucky number %d will bring you financial success.\n", lucky_number);
            break;
        case 3:
            printf("Your health and energy levels will improve soon.\n");
            break;
        case 4:
            printf("Your recent past experiences will help you in your current tasks.\n");
            break;
        case 5:
            printf("Your future looks bright and full of opportunities.\n");
            break;
        case 6:
            printf("You will meet someone special today.\n");
            break;
        case 7:
            printf("You will be able to resolve a long-standing issue today.\n");
            break;
        case 8:
            printf("Your creativity and intelligence will help you overcome obstacles today.\n");
            break;
        case 9:
            printf("You will receive unexpected help from a stranger today.\n");
            break;
        case 10:
            printf("Your positive attitude will lead to future success.\n");
            break;
        default:
            printf("Something went wrong with your fortune telling. Please try again later.\n");
    }

    int age_sum = 0, birth_date_sum = 0, birth_month_sum = 0, birth_year_sum = 0;
    while (age != 0) {
        age_sum += age % 10;
        age /= 10;
    }
    while (birth_date != 0) {
        birth_date_sum += birth_date % 10;
        birth_date /= 10;
    }
    while (birth_month != 0) {
        birth_month_sum += birth_month % 10;
        birth_month /= 10;
    }
    while (birth_year != 0) {
        birth_year_sum += birth_year % 10;
        birth_year /= 10;
    }

    int lucky_sum = lucky_number % 10 + lucky_number / 10;
    int final_sum = age_sum + birth_date_sum + birth_month_sum + birth_year_sum + lucky_sum;

    printf("\n\nBased on your personal information, we have calculated your lucky number: %d\n\n", final_sum);

    return 0;
}