//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage();
int getRandomNumber(int min, int max);

int main(void)
{
    int randomNumber, typingSpeed = 0;
    char userConfirmation;
    clock_t startTime, endTime;

    srand(time(NULL));
    welcomeMessage();

    do{
        printf("\nTo start the typing speed test, please type the following: ");
        randomNumber = getRandomNumber(1000, 9999);
        printf("%d\n", randomNumber);

        startTime = clock();

        int userNumber = 0;
        scanf("%d", &userNumber);

        endTime = clock();

        if(userNumber == randomNumber)
        {
            typingSpeed = (int) (endTime - startTime) / CLOCKS_PER_SEC;
            printf("\nYour typing speed is: %d seconds per character.\n", typingSpeed);
        }
        else
        {
            printf("\nYou typed the wrong number. Please try again.\n");
        }

        printf("\nDo you want to take the test again? (y/n)\n");
        scanf(" %c", &userConfirmation);

    }while(userConfirmation == 'y' || userConfirmation == 'Y');

    printf("\nThank you for taking the typing speed test!\n");

    return 0;
}

void welcomeMessage()
{
    printf("Welcome to C Typing Speed Test Program!\n");
    printf("This program will help you determine your typing speed.\n");
    printf("You will be provided with a random 4-digit number to type, and the program will measure your typing time.\n");
    printf("Press enter to start the program.\n");
    getchar();
}

int getRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}