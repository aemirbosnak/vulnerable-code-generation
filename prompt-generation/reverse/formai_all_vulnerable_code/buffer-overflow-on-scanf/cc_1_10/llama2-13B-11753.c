//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 120

int main() {
    int age, name_length;
    char name[MAX_NAME_LENGTH];

    // Get the user's name and age
    printf("What is your name? ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name_length = strlen(name);
    printf("How old are you? ");
    scanf("%d", &age);

    // Check if the name is too long
    if (name_length > MAX_NAME_LENGTH) {
        printf("Error: Name too long! Please enter a name with at most %d characters.\n", MAX_NAME_LENGTH);
        return 1;
    }

    // Check if the age is negative
    if (age < 0) {
        printf("Error: Age must be non-negative! Please enter a valid age.\n");
        return 2;
    }

    // Check if the age is over 120 years old
    if (age > MAX_AGE) {
        printf("Error: You are too old! The maximum age allowed is %d years.\n", MAX_AGE);
        return 3;
    }

    // Print a success message if everything is valid
    printf("Hello, %s! You are %d years old.\n", name, age);

    // Generate a random number between 1 and 10
    int random_number = rand() % 10 + 1;

    // Print a message based on the random number
    switch (random_number) {
        case 1:
            printf("You are a lucky person!\n");
            break;
        case 2:
            printf("You are a bit unlucky today.\n");
            break;
        case 3:
            printf("You are so unlucky that you might as well go home and cry.\n");
            break;
        default:
            printf("You are a normal person with a random number of %d.\n", random_number);
            break;
    }

    return 0;
}