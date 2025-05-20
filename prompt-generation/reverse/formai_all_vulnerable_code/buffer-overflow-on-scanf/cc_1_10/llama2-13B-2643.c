//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024

// Function to reverse a string
void reverse_string(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to print a string in reverse
void print_reverse(char *str) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        printf("%c", str[strlen(str) - i - 1]);
    }
}

int main() {
    char str[MAX_LENGTH];
    int choice;

    printf("Welcome to the Text Processing Extravaganza! \n");

    // Menu to choose the text processing operation
    printf("Choose an operation (1 for reverse, 2 for print in reverse): ");
    scanf("%d", &choice);

    // Get the input string
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Perform the chosen operation
    if (choice == 1) {
        reverse_string(str);
        printf("Reversed string: %s\n", str);
    } else if (choice == 2) {
        print_reverse(str);
        printf("Printed in reverse: %s\n", str);
    }

    return 0;
}