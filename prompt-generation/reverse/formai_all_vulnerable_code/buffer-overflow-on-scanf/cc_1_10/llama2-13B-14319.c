//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to print a happy face
void print_happy(char *str) {
    printf(":) %s\n", str);
}

// Function to reverse a string
void reverse_str(char *str) {
    int i, j, temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[MAX_LEN];
    int choice;

    // Welcome message
    printf("Welcome to the Happy String Manipulation Program!\n");

    // Ask user for input string
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);

    // Print the input string with a happy face
    print_happy(str);

    // Ask user for choice
    printf("Do you want to reverse the string? (y/n): ");
    scanf("%d", &choice);

    // Reverse the string if user chooses yes
    if (choice == 1) {
        reverse_str(str);
        print_happy(str);
    }

    // Exit program
    printf("Thanks for using the Happy String Manipulation Program! :)\n");
    return 0;
}