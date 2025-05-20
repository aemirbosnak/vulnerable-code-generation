//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Function to get user input
int get_name_and_age(char *name, int *age) {
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    printf("Enter your age: ");
    scanf("%d", age);

    // Check for invalid input
    if (name[0] == '\n' || *age < 0 || *age > MAX_AGE) {
        printf("Invalid input! Please try again.\n");
        return 1;
    }

    return 0;
}

int main() {
    int age;
    char name[MAX_NAME_LENGTH];

    // Try to get user input
    if (get_name_and_age(name, &age) == 1) {
        // If invalid input, print a funny message and try again
        printf("It looks like you've been eaten by a grumpy dinosaur! Better luck next time.\n");
        return 1;
    }

    // If valid input, print a happy message and continue
    printf("Hello, %s! You are %d years old.\n", name, age);

    // Simulate a time travel scenario
    printf("You have been transported back in time to the age of the dinosaurs!\n");
    sleep(5);

    // If the user is still alive, print a final message
    if (age > 0) {
        printf("You survived the dinosaur age! Congratulations, you are now a certified time traveler.\n");
    } else {
        printf("You were eaten by a dinosaur. Better luck next time.\n");
    }

    return 0;
}