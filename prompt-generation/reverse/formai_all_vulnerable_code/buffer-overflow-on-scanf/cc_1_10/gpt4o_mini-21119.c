//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print "Style 1" ASCII art
void printStyle1(const char *text) {
    printf("Style 1:\n");
    for (int i = 0; i < strlen(text); i++) {
        printf("  %c  \n", text[i]);
        printf(" %c%c%c \n", text[i], text[i], text[i]);
        printf("  %c  \n", text[i]);
    }
}

// Function to print "Style 2" ASCII art
void printStyle2(const char *text) {
    printf("Style 2:\n");
    for (int i = 0; i < strlen(text); i++) {
        printf(" .--. \n");
        printf(" |%c %c| \n", text[i], text[i]);
        printf(" '.__.' \n");
    }
}

// Function to print "Style 3" ASCII art
void printStyle3(const char *text) {
    printf("Style 3:\n");
    for (int i = 0; i < strlen(text); i++) {
        printf("  _  \n");
        printf(" |%c| \n", text[i]);
        printf(" |_|  \n");
    }
}

// Function to print "Style 4" ASCII art
void printStyle4(const char *text) {
    printf("Style 4:\n");
    for (int i = 0; i < strlen(text); i++) {
        printf("  #  \n");
        printf(" /%c\\ \n", text[i]);
        printf(" \\_/ \n");
    }
}

// Function to print "Shape-changing" menu
void printMenu() {
    printf("Choose your ASCII art style:\n");
    printf("1. Style 1\n");
    printf("2. Style 2\n");
    printf("3. Style 3\n");
    printf("4. Style 4\n");
}

int main() {
    char input[100];
    int choice;

    printf("Enter text to convert to ASCII art: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    printMenu();
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printStyle1(input);
            break;
        case 2:
            printStyle2(input);
            break;
        case 3:
            printStyle3(input);
            break;
        case 4:
            printStyle4(input);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}