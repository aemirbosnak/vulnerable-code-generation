//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Function to get user input
int get_user_input(char *name, int *age) {
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    printf("Enter your age: ");
    int age_input;
    scanf("%d", &age_input);

    *age = age_input;

    if (age_input < 0 || age_input > MAX_AGE) {
        printf("Invalid age. Please enter a valid age between 0 and %d\n", MAX_AGE);
        return 1;
    }

    return 0;
}

int main() {
    char name[MAX_NAME_LENGTH];
    int age;

    // Check if user input is valid
    if (get_user_input(name, &age) != 0) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    printf("Hello, %s! You are %d years old.\n", name, age);

    // Simulate a time travel scenario
    if (age > 50) {
        printf("You have been transported to the year %d. Welcome to the future!",
            (age / 2) * 2);
    } else {
        printf("You have been transported to the year %d. Better pack a time machine!",
            (age / 2) * 2);
    }

    return 0;
}