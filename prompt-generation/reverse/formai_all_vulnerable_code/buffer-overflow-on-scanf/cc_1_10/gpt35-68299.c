//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Error Handling Program!\n");
    printf("This program will demonstrate some unique and exciting ways to handle errors in C.\n");
    printf("Are you ready? Let's get started!\n\n");

    // We're going to create an array that will store some numbers
    int nums[5];

    printf("Please enter 5 numbers, pressing enter after each one:\n");
    // Let's loop through and get the users input for each number
    for(int i = 0; i < 5; i++) {
        // We'll use scanf to store the user's input in the array
        if(scanf("%d", &nums[i]) != 1) {
            // Oh no! Looks like the user didn't enter a number
            printf("You didn't enter a number, try again!\n");
            // Let's clear the input buffer to get rid of any invalid characters that may have been entered
            while(getchar() != '\n');
            // We need to decrement the variable i so the loop starts from the beginning for this iteration
            i--;
        }
    }

    printf("\nGreat! You entered the following numbers: ");
    // Let's loop through and print out the numbers the user entered
    for(int i = 0; i < 5; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Now let's perform some calculations using these numbers
    int sum = 0, product = 1;
    for(int i = 0; i < 5; i++) {
        // Let's check if the current number is negative – we can't calculate the square root of a negative number!
        if(nums[i] < 0) {
            // Looks like a negative number was found, let's throw an error and exit the program
            printf("\nERROR: You can't calculate the square root of a negative number.\n");
            printf("Sorry, the program will now exit.\n");
            exit(0);
        }
        // Let's calculate the sum and product
        sum += nums[i];
        product *= nums[i];
    }

    printf("\nFantastic! The sum of these numbers is: %d\n", sum);
    printf("The product of these numbers is: %d\n", product);

    // Finally, let's check if the sum is greater than the product – just for fun!
    if(sum > product) {
        // Looks like a mistake was made, let's throw a warning
        printf("\nWARNING: The sum of the numbers is greater than their product.\n");
        printf("Please take note of this!\n");
    }

    printf("\nThank you for trying out this Error Handling Program!\n");
    printf("I hope you had fun and learned something new today.\n");

    return 0;
}