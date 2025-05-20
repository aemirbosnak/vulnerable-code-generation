//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a custom error code for our program
#define MY_ERROR 999

int main() {
    // Initialize some variables
    int age = 0;
    char name[50];
    float height = 0.0f;

    // Ask the user for their name and age
    printf("Hello there! What's your name? ");
    fgets(name, 50, stdin);
    printf("And how old are you? ");
    scanf("%d", &age);

    // Check if the user entered a valid name
    if (strlen(name) < 1) {
        // If the name is empty, print an error message
        printf("Oops, it looks like you forgot to enter your name! Try again:\n");
        return MY_ERROR;
    }

    // Check if the user entered a valid age
    if (age < 0 || age > 100) {
        // If the age is out of range, print an error message
        printf("Hmm, that's not a valid age. Age must be between 0 and 100 inclusive:\n");
        return MY_ERROR;
    }

    // Now we'll pretend to calculate the person's height based on their age
    // (this will actually just print a random height)
    height = (age / 10) * 3.2f + 60;

    // Print the person's name, age, and height
    printf("Hello %s, you are %d years old and %.2f meters tall!\n", name, age, height);

    // If the user enters a negative age, print an error message
    if (age < 0) {
        printf("Oops, you can't be negative years old! Try again:\n");
        return MY_ERROR;
    }

    // If the user enters a fractional age, print an error message
    if (age % 1 != 0) {
        printf("Hmm, that's not a valid age. Age must be an integer:\n");
        return MY_ERROR;
    }

    // If the user enters a name that's too long, print an error message
    if (strlen(name) > 50) {
        printf("Whoa, that's a long name! Try again with a shorter name:\n");
        return MY_ERROR;
    }

    // If the user enters a name that's too short, print an error message
    if (strlen(name) < 1) {
        printf("Oops, it looks like you forgot to enter a name! Try again:\n");
        return MY_ERROR;
    }

    return 0; // success!
}