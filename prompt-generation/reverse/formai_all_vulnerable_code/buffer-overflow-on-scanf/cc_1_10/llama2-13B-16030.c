//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 120

// Function to get user input
int get_name(char *name) {
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    return 0;
}

// Function to check if the age is valid
int check_age(int age) {
    if (age < 0 || age > MAX_AGE) {
        printf("Invalid age. Must be between 0 and %d\n", MAX_AGE);
        return 1;
    }
    return 0;
}

int main() {
    char name[MAX_NAME_LENGTH];
    int age;

    // Get the user's name
    if (get_name(name)) {
        printf("Error: Unable to get name\n");
        return 1;
    }

    // Get the user's age
    printf("Enter your age: ");
    if (scanf("%d", &age) != 1) {
        printf("Error: Unable to get age\n");
        return 1;
    }

    // Check if the age is valid
    if (check_age(age)) {
        printf("Error: Age must be between 0 and %d\n", MAX_AGE);
        return 1;
    }

    // Print a success message
    printf("Hello, %s! You are %d years old.\n", name, age);

    return 0;
}