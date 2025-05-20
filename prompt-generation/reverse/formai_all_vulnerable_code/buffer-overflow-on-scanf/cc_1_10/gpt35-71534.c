//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));   //setting seed for random numbers
    int luckyNum = rand() % 100 + 1;   //generating lucky number between 1 and 100
    char name[20];    //to hold user's name
    int age;    //to hold user's age
    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Please enter your name: ");
    scanf("%s", name);    //taking user's name as input
    printf("Please enter your age: ");
    scanf("%d", &age);    //taking user's age as input
    printf("Hello %s, let's see what fate has in store for you.\n\n", name);
    printf("Your lucky number for today is %d. Remember it well!\n\n", luckyNum);
    printf("Let's see what your future holds:\n\n");

    switch(luckyNum) {    //fortune telling based on lucky number
        case 1:
            printf("You will come into money very soon. Keep an eye out for opportunities.\n");
            break;
        case 2:
            printf("You will meet your true love very soon. Keep an open mind.\n");
            break;
        case 3:
            printf("Your career is about to take off. Keep pushing yourself.\n");
            break;
        case 4:
            printf("Be careful of making hasty decisions. Think before you act.\n");
            break;
        case 5:
            printf("You will embark on an exciting journey soon. Embrace it.\n");
            break;
        case 6:
            printf("You will experience a major loss soon. Stay strong.\n");
            break;
        case 7:
            printf("You will receive unexpected news that will change your life dramatically. Be prepared.\n");
            break;
        case 8:
            printf("You will find inner peace and happiness soon. Keep looking.\n");
            break;
        case 9:
            printf("You will face a difficult challenge soon. Stay focused and never give up.\n");
            break;
        default:
            printf("Something great is about to happen. Be ready for it.\n");
            break;
    }

    printf("\nThank you for using the Automated Fortune Teller. Good luck!\n");
    return 0;
}