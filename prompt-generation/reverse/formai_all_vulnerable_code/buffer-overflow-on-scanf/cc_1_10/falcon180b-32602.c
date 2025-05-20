//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int choice;
    char name[20];
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", &name);
    
    srand(time(NULL));
    int randomNumber = rand() % 8 + 1;
    
    switch(randomNumber) {
        case 1:
            printf("\nYour fortune:\n");
            printf("You will find love within the next year.\n");
            break;
        case 2:
            printf("\nYour fortune:\n");
            printf("You will have good luck in your career.\n");
            break;
        case 3:
            printf("\nYour fortune:\n");
            printf("You will have a successful business venture.\n");
            break;
        case 4:
            printf("\nYour fortune:\n");
            printf("You will have a new addition to your family.\n");
            break;
        case 5:
            printf("\nYour fortune:\n");
            printf("You will travel to a foreign country.\n");
            break;
        case 6:
            printf("\nYour fortune:\n");
            printf("You will have a financial windfall.\n");
            break;
        case 7:
            printf("\nYour fortune:\n");
            printf("You will have a pleasant surprise.\n");
            break;
        case 8:
            printf("\nYour fortune:\n");
            printf("You will have a peaceful and happy life.\n");
            break;
    }
    
    printf("\nThank you for using the Automated Fortune Teller. Goodbye, %s!\n", name);
    
    return 0;
}