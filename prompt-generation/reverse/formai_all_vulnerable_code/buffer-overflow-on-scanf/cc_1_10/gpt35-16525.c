//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int generateRandomNumber(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    // Seed the random number generator
    srand(time(0));

    printf("Welcome to the Automated Fortune Teller! \n");
    printf("Please think of a number between 1 and 10 and I will try to guess it!\n");

    int userInput;
    printf("Enter your number: ");
    scanf("%d", &userInput);

    int randomNumber = generateRandomNumber(1, 10);
    int attempts = 0;

    while (randomNumber != userInput)
    {
        attempts++;
        switch (generateRandomNumber(1, 4))
        {
        case 1:
            printf("Hm.. I don\'t think your number is %d. Let me try again.\n", randomNumber);
            randomNumber = generateRandomNumber(1, 10);
            break;
        case 2:
            printf("Let me think.. I\'m going to take a guess and say it\'s not %d this time.\n", randomNumber);
            randomNumber = generateRandomNumber(1, 10);
            break;
        case 3:
            printf("I sense that %d is not your number. Let\'s try another one.\n", randomNumber);
            randomNumber = generateRandomNumber(1, 10);
            break;
        case 4:
            printf("It seems my powers of prediction are off.. maintaining my focus and let\'s try another number..\n");
            randomNumber = generateRandomNumber(1, 10);
            break;
        }
    }

    attempts++;
    printf("Congratulations! I have successfully guessed your number %d in %d attempts.\n", userInput, attempts);
    printf("I hope you found the prediction helpful and informative. Goodbye!\n");

    return 0;
}