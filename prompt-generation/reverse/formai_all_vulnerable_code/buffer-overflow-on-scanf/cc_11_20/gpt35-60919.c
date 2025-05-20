//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int rand_num, num_of_records;
    srand(time(NULL));

    printf("Welcome to the Brave Automated Fortune Teller! Please enter the number of records you wish to generate: ");
    scanf("%d", &num_of_records);

    for (int i = 0; i < num_of_records; i++) {
        rand_num = rand() % 10;

        // Switch statement for the fortune
        switch (rand_num) {
            case 0:
                printf("Bravery is not the absence of fear, but the triumph over it.\n");
                break;
            case 1:
                printf("The future belongs to those who believe in the beauty of their dreams.\n");
                break;
            case 2:
                printf("It does not matter how slowly you go as long as you do not stop.\n");
                break;
            case 3:
                printf("Believe you can and you're halfway there.\n");
                break;
            case 4:
                printf("In order to succeed, we must first believe that we can.\n");
                break;
            case 5:
                printf("If you want to live a happy life, tie it to a goal, not to people or things.\n");
                break;
            case 6:
                printf("Success is not final, failure is not fatal: it is the courage to continue that counts.\n");
                break;
            case 7:
                printf("Try not to become a man of success. Rather become a man of value.\n");
                break;
            case 8:
                printf("You miss 100% of the shots you don’t take.\n");
                break;
            case 9:
                printf("I can't change the direction of the wind, but I can adjust my sails to always reach my destination.\n");
                break;
        }
    }

    printf("Thanks for using the Brave Automated Fortune Teller! May the odds be ever in your favour.\n");

    return 0;
}