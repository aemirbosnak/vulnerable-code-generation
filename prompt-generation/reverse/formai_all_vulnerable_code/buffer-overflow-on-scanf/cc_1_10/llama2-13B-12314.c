//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 120

// Function to get user input
void get_user_input(char *name, int *age) {
    printf("Please enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // remove the newline character

    printf("Please enter your age: ");
    scanf("%d", age);
}

// Function to print a happy message
void print_happy_message() {
    printf("Hello there, young adventurer! I'm so glad you're here. \n");
    printf("I'm a friendly program, and I'm here to help you with any questions you may have. \n");
    printf("But before we begin, let me just check some things... \n");
}

// Function to handle errors
void handle_errors(char *name, int age) {
    if (name == NULL) {
        printf("Oh dear, it looks like I couldn't quite understand your name. \n");
        printf("Let me try again... Please enter your name: ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0; // remove the newline character
    }

    if (age < 0 || age > MAX_AGE) {
        printf("Oh my, it looks like you've given me an age that's not quite right. \n");
        printf("Let me try again... Please enter your age: ");
        scanf("%d", age);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    int age;

    // Call the function to get user input
    get_user_input(name, &age);

    // Call the function to print a happy message
    print_happy_message();

    // Call the function to handle errors
    handle_errors(name, age);

    printf("Hello, %s! I'm so glad you're here. \n", name);

    return 0;
}