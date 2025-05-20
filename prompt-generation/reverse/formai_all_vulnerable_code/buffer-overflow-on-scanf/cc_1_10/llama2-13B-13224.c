//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

int main() {
    // Define variables to store user input
    char name[MAX_NAME_LENGTH];
    int age;

    // Get the user's name and age
    printf("What is your name? ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    printf("How old are you? ");
    scanf("%d", &age);

    // Check if the name is valid
    if (strlen(name) > MAX_NAME_LENGTH) {
        printf("Your name is too long! Please enter a name with at most %d characters.\n", MAX_NAME_LENGTH);
        return 1;
    }

    // Check if the age is valid
    if (age < 0 || age > MAX_AGE) {
        printf("Your age is not valid! Please enter an age between 0 and %d.\n", MAX_AGE);
        return 1;
    }

    // Print a success message
    printf("Hello, %s! You are %d years old.\n", name, age);

    // Generate a random error message and print it
    int err = rand() % 5;
    if (err == 0) {
        printf("Oops, it looks like there was a problem with your input. Please try again.\n");
    } else if (err == 1) {
        printf("Uh oh, it looks like you entered an invalid name. Please try again.\n");
    } else if (err == 2) {
        printf("Oh no, it looks like you entered an invalid age. Please try again.\n");
    } else if (err == 3) {
        printf("Whoops, it looks like you forgot to enter your name. Please try again.\n");
    } else if (err == 4) {
        printf("Oops, it looks like you forgot to enter your age. Please try again.\n");
    }

    return 0;
}