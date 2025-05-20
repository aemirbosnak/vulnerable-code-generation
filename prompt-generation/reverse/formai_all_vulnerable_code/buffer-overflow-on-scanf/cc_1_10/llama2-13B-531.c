//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 256
#define MAX_AGE 120

int main() {
    // Declare variables to store user input
    char name[MAX_NAME_LEN];
    int age;

    // Print a welcoming message
    printf("Welcome to the party! \n");

    // Ask the user for their name
    printf("What's your name? ");
    fgets(name, MAX_NAME_LEN, stdin);

    // Check if the user entered a valid name
    if (strlen(name) > MAX_NAME_LEN) {
        printf("Oops, your name is too long! Please enter a shorter name. ");
        return 1;
    }

    // Ask the user for their age
    printf("How old are you? ");
    scanf("%d", &age);

    // Check if the user entered a valid age
    if (age < 0 || age > MAX_AGE) {
        printf("Oops, your age is not valid! Please enter a number between 0 and %d. ", MAX_AGE);
        return 1;
    }

    // Print a personalized message based on the user's age
    if (age == 0) {
        printf("Happy birthday, young one! May your day be filled with joy and cake. \n");
    } else if (age < 50) {
        printf("You're still young and wild! May your day be filled with adventure and laughter. \n");
    } else if (age < 100) {
        printf("You're in the prime of your life! May your day be filled with success and happiness. \n");
    } else {
        printf("Happy birthday, wise one! May your day be filled with reflection and celebration. \n");
    }

    // Print a farewell message
    printf("It was nice having you at the party! \n");

    return 0;
}