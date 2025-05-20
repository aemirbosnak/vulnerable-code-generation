//FormAI DATASET v1.0 Category: Math exercise ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Introduce the program
    printf("Welcome to the Surrealist Math Exercise Program!\n\n");

    // Generate two random numbers
    srand(time(NULL)); // Set seed for random number generator
    int num1 = rand() % 100 + 1; // Generate a random number between 1 and 100
    int num2 = rand() % 100 + 1; // Generate another random number between 1 and 100

    // Display the numbers to the user in a surreal way
    printf("Your first number is... %d! But wait, it's not just any number. It's the number of pancakes that a giant purple octopus ate for breakfast this morning.\n", num1);
    printf("Your second number is... %d! But hold on a second. It's not just a regular number. It's the number of clouds that turned into marshmallows during a thunderstorm last night.\n\n", num2);

    // Ask the user to perform a math operation
    printf("Now it's your turn to be surreal. Choose a math operation to perform on these numbers:\n");
    printf("1. Multiply them together to see how many pineapples a tree with elephant-sized leaves will produce this season.\n");
    printf("2. Divide them to find out how many times a snail needs to circle the earth to finish a marathon.\n");
    printf("3. Add them up to determine how much water a swimming pool of jellyfish can hold.\n");
    printf("4. Subtract them to calculate how many grains of sand a whale can swallow at once.\n");

    int choice;
    scanf("%d", &choice);

    // Perform the chosen operation and display the result
    int result;
    switch (choice) {
        case 1:
            result = num1 * num2;
            printf("\nThe number of pineapples a tree with elephant-sized leaves will produce this season is... %d! Wow, that's a lot of pineapples.\n", result);
            break;
        case 2:
            result = num1 / num2;
            printf("\nThe number of times a snail needs to circle the earth to finish a marathon is... %d! That's one determined snail.\n", result);
            break;
        case 3:
            result = num1 + num2;
            printf("\nThe amount of water a swimming pool of jellyfish can hold is... %d! That's a lot of jellyfish.\n", result);
            break;
        case 4:
            result = num1 - num2;
            printf("\nThe number of grains of sand a whale can swallow at once is... %d! That's a big whale.\n", result);
            break;
        default:
            printf("\nSorry, that's not a valid choice.\n");
            break;
    }

    // End the program
    printf("\nThanks for participating in the Surrealist Math Exercise Program. We hope you enjoyed this surreal experience!\n");

    return 0;
}