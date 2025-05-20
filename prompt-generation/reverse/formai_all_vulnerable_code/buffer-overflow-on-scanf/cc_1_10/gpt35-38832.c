//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int age, luckyNum, month;
    char color[10];
    
    printf("Welcome to the Automated Fortune Teller Program!\n");
    printf("Please answer the following questions to receive your fortune:\n");
    
    printf("What is your name?\n");
    scanf("%s", name);
    
    printf("What is your age?\n");
    scanf("%d", &age);
    
    printf("What is your lucky number?\n");
    scanf("%d", &luckyNum);
    
    printf("In what month were you born (as a number)?\n");
    scanf("%d", &month);
    
    printf("What is your favorite color?\n");
    scanf("%s", color);
    
    srand(time(0)); // generate random number with seed from current time
    
    int randomNum = rand() % 5; // generate a random number between 0 and 4
    
    printf("\nHello, %s! Here is your fortune for today:\n", name);
    
    switch (randomNum) {
        case 0:
            printf("You will gain unexpected wealth soon.\n");
            break;
        case 1:
            printf("You will meet a new friend who will be very important to you.\n");
            break;
        case 2:
            printf("You will go on a trip and have a wonderful time.\n");
            break;
        case 3:
            printf("Your lucky number, %d, will bring you good fortune in the coming days.\n", luckyNum);
            break;
        case 4:
            printf("Wearing the color %s will bring you luck and happiness today.\n", color);
            break;
        default:
            printf("Oops, something went wrong. Please try again later.\n");
    }
    
    return 0;
}