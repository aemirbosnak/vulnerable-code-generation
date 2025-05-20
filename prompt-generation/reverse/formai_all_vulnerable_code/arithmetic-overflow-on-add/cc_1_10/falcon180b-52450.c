//Falcon-180B DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a given string in reverse order
void reverseString(char* str) {
    int length = strlen(str);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}

// Function to generate a random string of given length
char* generateRandomString(int length) {
    char* str = (char*) malloc(length + 1); // Allocate memory for the string
    if (str == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }
    srand(time(NULL)); // Seed the random number generator with the current time
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a'; // Generate a random lowercase letter
    }
    str[length] = '\0'; // Add a null terminator to the end of the string
    return str;
}

// Recursive function to print a given string in reverse order
void printReverse(char* str, int index) {
    if (index >= strlen(str)) {
        printf("%s\n", str);
        return;
    }
    printReverse(str, index + 1);
    printf("%c", str[index]);
}

int main() {
    int length;
    printf("Enter the length of the string: ");
    scanf("%d", &length);
    char* str = generateRandomString(length);
    printf("Random string: %s\n", str);
    reverseString(str);
    printf("String in reverse order: %s\n", str);
    printf("String in reverse order (recursive): ");
    printReverse(str, 0);
    free(str); // Free the memory allocated for the string
    return 0;
}