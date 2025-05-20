//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randNum, fortuneNum;
    char option;

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Do you want me to predict your future? (y/n): ");
    scanf("%c", &option);

    srand(time(NULL));  // initialize random number generator

    while (option == 'y' || option == 'Y') {
        randNum = rand() % 10;  // generate random number between 0 and 9
        
        switch(randNum) {
            case 0: printf("\nYou will meet your true love within a year.\n");
                    fortuneNum = rand() % 5;  // additional fortune possibility
                    if (fortuneNum == 0) {
                        printf("You will also come into a windfall soon!\n");
                    }
                    break;
            case 1: printf("\nYou will land your dream job in the next month.\n");
                    fortuneNum = rand() % 5;
                    if (fortuneNum == 0) {
                        printf("Your financial success will also bring you great happiness.\n");
                    }
                    break;
            case 2: printf("\nYou will travel to a foreign country soon.\n");
                    fortuneNum = rand() % 5;
                    if (fortuneNum == 0) {
                        printf("You will discover something new about yourself on this trip.\n");
                    }
                    break;
            case 3: printf("\nYour current troubles will soon be resolved.\n");
                    fortuneNum = rand() % 5;
                    if (fortuneNum == 0) {
                        printf("This resolution will bring you a great sense of relief.\n");
                    }
                    break;
            case 4: printf("\nYou will receive unexpected good news today.\n");
                    fortuneNum = rand() % 5;
                    if (fortuneNum == 0) {
                        printf("This news will open new doors for you.\n");
                    }
                    break;
            case 5: printf("\nYou will make a significant positive impact on someone's life soon.\n");
                    fortuneNum = rand() % 5;
                    if (fortuneNum == 0) {
                        printf("This impact will bring you great joy.\n");
                    }
                    break;
            case 6: printf("\nYou will achieve something significant in your career soon.\n");
                    fortuneNum = rand() % 5;
                    if (fortuneNum == 0) {
                        printf("Your hard work will pay off in more ways than one.\n");
                    }
                    break;
            case 7: printf("\nYour creativity and innovation will be recognized by others soon.\n");
                    fortuneNum = rand() % 5;
                    if (fortuneNum == 0) {
                        printf("This recognition will inspire you to keep pushing yourself.\n");
                    }
                    break;
            case 8: printf("\nYou will overcome a personal challenge in the near future.\n");
                    fortuneNum = rand() % 5;
                    if (fortuneNum == 0) {
                        printf("This will be a character-building experience.\n");
                    }
                    break;
            case 9: printf("\nYour family will be a source of great happiness and fulfillment in your life.\n");
                    fortuneNum = rand() % 5;
                    if (fortuneNum == 0) {
                        printf("You will create many wonderful memories with your loved ones.\n");
                    }
                    break;
            default: printf("Invalid input.\n");
                     break;
        }

        printf("\nDo you want me to predict your future again? (y/n): ");  // ask if user wants to try again
        scanf(" %c", &option);
    }

    printf("\nThank you for using the Automated Fortune Teller!\n");

    return 0;
}