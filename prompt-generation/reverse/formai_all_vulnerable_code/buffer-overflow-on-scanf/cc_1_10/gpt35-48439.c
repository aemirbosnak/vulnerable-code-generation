//FormAI DATASET v1.0 Category: String manipulation ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char greeting[100] = "Hello, World!"; // Initializing a string
    char name[20];
    int length;

    printf("Welcome to this cheerful string manipulation program!\n");
    printf("What's your name?\n");
    scanf("%s", name);

    // Concatenating the name to the greeting string
    strcat(greeting, " ");
    strcat(greeting, name);

    // Getting the length of the string
    length = strlen(greeting);

    printf("\n%s\n", greeting);

    printf("The length of your greeting is: %d\n", length);

    // Reversing the string
    printf("\nReversing your greeting...\n");
    for(int i = length - 1; i >= 0; i--) {
        printf("%c", greeting[i]);
    }

    // Converting the string to uppercase
    printf("\n\nConverting your greeting to uppercase...\n");
    for(int i = 0; greeting[i] != '\0'; i++) {
        printf("%c", toupper(greeting[i]));
    }

    // Converting the string to lowercase
    printf("\n\nConverting your greeting to lowercase...\n");
    for(int i = 0; greeting[i] != '\0'; i++) {
        printf("%c", tolower(greeting[i]));
    }

    // Extracting a substring
    printf("\n\nExtracting a substring from your greeting...\n");
    char substring[20];
    printf("Enter the starting position and length: ");
    int start, len;
    scanf("%d %d", &start, &len);
    for(int i = 0; i < len; i++) {
        substring[i] = greeting[start + i];
    }
    substring[len] = '\0';
    printf("The extracted substring is: %s", substring);

    return 0;
}