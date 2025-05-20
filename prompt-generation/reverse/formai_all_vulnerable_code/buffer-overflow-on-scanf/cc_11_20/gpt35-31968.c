//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int choice;
    srand(time(0)); //initializing random seed
    
    printf("\t\t***Welcome to the Automated Fortune Teller***\n\n");
    printf("Please choose a number between 1-3: \n");
    printf("1. Health\n2. Wealth\n3. Love\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("\n\nYou have chosen Health!\n");
            int health = rand() % 5 + 1;
            switch(health) {
                case 1:
                    printf("You will have good health in the upcoming days.\n");
                    break;
                case 2:
                    printf("Your health will take a turn for the better soon.\n");
                    break;
                case 3:
                    printf("You are already on the path to good health and will continue on this path.\n");
                    break;
                case 4:
                    printf("Your health may take a hit, but you will recover quickly.\n");
                    break;
                case 5:
                    printf("You must take care of yourself as there is a possibility of an illness.\n");
                    break;
                default:
                    printf("Invalid output.\n");
            }
            break;
        case 2:
            printf("\n\nYou have chosen Wealth!\n");
            int wealth = rand() % 5 + 1;
            switch(wealth) {
                case 1:
                    printf("Financial success is within reach, keep up the hard work.\n");
                    break;
                case 2:
                    printf("Money may be tight for a while, but everything will work out in the end.\n");
                    break;
                case 3:
                    printf("A business opportunity will present itself soon and you should take it.\n");
                    break;
                case 4:
                    printf("You should take a risk and invest in a new project, it will pay off.\n");
                    break;
                case 5:
                    printf("Be cautious with your finances as there is a possibility of a loss.\n");
                    break;
                default:
                    printf("Invalid output.\n");
            }
            break;
        case 3:
            printf("\n\nYou have chosen Love!\n");
            int love = rand() % 5 + 1;
            switch(love) {
                case 1:
                    printf("A new love interest is on the horizon and things will work out between you two.\n");
                    break;
                case 2:
                    printf("Your current relationship may hit a rough patch, but communication and honesty will help you both.\n");
                    break;
                case 3:
                    printf("You may have to make a tough decision in your love life, but trust your gut and make the right choice.\n");
                    break;
                case 4:
                    printf("You will have a special moment with your partner that will strengthen your bond.\n");
                    break;
                case 5:
                    printf("The timing may not be right for a relationship, focus on self-love and personal growth.\n");
                    break;
                default:
                    printf("Invalid output.\n");
            }
            break;
        default:
            printf("Invalid input.\n");
            break;
    }
    printf("\n\n\t\tThank you for using the Automated Fortune Teller!\n");
    return 0;
}