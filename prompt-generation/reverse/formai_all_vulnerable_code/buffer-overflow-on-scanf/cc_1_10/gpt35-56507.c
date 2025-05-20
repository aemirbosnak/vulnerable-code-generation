//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
    int birth_year, lucky_number, fav_number, random_num;
    char first_pet, first_name;
    int fortune_num;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please answer the following questions to receive your fortune:\n");
    
    printf("What is your birth year? ");
    scanf("%d", &birth_year);

    printf("What is your lucky number? ");
    scanf("%d", &lucky_number);

    printf("What is your favorite number? ");
    scanf("%d", &fav_number);

    printf("What is the first letter of your first pet's name? ");
    scanf(" %c", &first_pet);

    printf("What is the first letter of your first name? ");
    scanf(" %c", &first_name);

    // Generate random number between 1 and 10
    srand(time(NULL));
    random_num = rand() % 10 + 1;

    fortune_num = ((birth_year * lucky_number) / fav_number) + (random_num * first_pet - first_name);

    printf("\n");
    printf("Your fortune number is %d.\n", fortune_num);

    if (fortune_num < 100) {
        printf("You will have a rough day today. Be careful.\n");
    }
    else if (fortune_num >= 100 && fortune_num < 200) {
        printf("You will meet someone special today. Keep your eyes open!\n");
    }
    else if (fortune_num >= 200 && fortune_num < 300) {
        printf("Your hard work will pay off very soon! Keep pushing forward!\n");
    }
    else {
        printf("Uh oh... a financial crisis may be approaching. Be wary of your spending.\n");
    }

    printf("\n");
    printf("Thank you for using the Automated Fortune Teller. Good luck today!\n");

    return 0;
}