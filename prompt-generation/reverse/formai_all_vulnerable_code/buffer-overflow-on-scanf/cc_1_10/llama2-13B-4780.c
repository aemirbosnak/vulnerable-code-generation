//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

int main() {
    int age, name_len;
    char name[MAX_NAME_LENGTH];
    struct tm *time_info;

    // Ask the user for their name and age
    printf("Hello! Please enter your name and age: ");
    scanf("%19s%d", name, &age);

    // Check if the name is too long
    name_len = strlen(name);
    if (name_len > MAX_NAME_LENGTH) {
        printf("Oops! Your name is too long. Please enter a shorter name.\n");
        return 1;
    }

    // Check if the age is valid
    if (age < 0 || age > MAX_AGE) {
        printf("Error: Age must be a positive integer between 0 and %d.\n", MAX_AGE);
        return 2;
    }

    // Convert the age to seconds
    time_info = localtime(&age);
    if (time_info == NULL) {
        printf("Error: Unable to convert age to seconds.\n");
        return 3;
    }

    // Print the user's name and age in a fun way
    printf("Hello %s! You are %d years old.\n", name, age);

    // Print a fun message based on the user's age
    if (age < 18) {
        printf("You are still a young whippersnapper!");
    } else if (age < 30) {
        printf("You are in your prime!");
    } else if (age < 50) {
        printf("You are getting older, but still pretty cool.");
    } else {
        printf("You are a wise and venerable elder.");
    }

    return 0;
}