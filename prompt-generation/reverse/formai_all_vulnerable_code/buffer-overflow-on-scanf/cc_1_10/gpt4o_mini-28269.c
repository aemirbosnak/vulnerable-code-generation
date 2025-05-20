//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverseString(char *str);
int countVowels(const char *str);
void toUpperCase(char *str);
void toLowerCase(char *str);
int getLength(const char *str);
void displayMenu();
void clearBuffer();

int main() {
    char inputString[MAX_LENGTH];
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6, 0 to exit): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the input buffer

        if (choice == 0) {
            printf("Exiting the program.\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Enter a string: ");
        fgets(inputString, MAX_LENGTH, stdin);
        inputString[strcspn(inputString, "\n")] = '\0'; // Remove newline character

        switch (choice) {
            case 1: 
                printf("Original String: %s\n", inputString);
                reverseString(inputString);
                printf("Reversed String: %s\n", inputString);
                break;
            case 2: 
                printf("Number of vowels in the string: %d\n", countVowels(inputString));
                break;
            case 3: 
                toUpperCase(inputString);
                printf("Uppercase String: %s\n", inputString);
                break;
            case 4: 
                toLowerCase(inputString);
                printf("Lowercase String: %s\n", inputString);
                break;
            case 5: 
                printf("Length of the string: %d\n", getLength(inputString));
                break;
            case 6: 
                printf("Original String: %s\n", inputString);
                printf("String in title case: ");
                for (char *p = inputString; *p; p++) {
                    if (p == inputString || *(p - 1) == ' ') {
                        putchar(toupper(*p));
                    } else {
                        putchar(tolower(*p));
                    }
                }
                putchar('\n');
                break;
        }
        printf("\n");
    }

    return 0;
}

void reverseString(char *str) {
    int length = strlen(str);
    char temp;
    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int countVowels(const char *str) {
    int count = 0;
    for (const char *p = str; *p; p++) {
        char lower = tolower(*p);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
            count++;
        }
    }
    return count;
}

void toUpperCase(char *str) {
    for (char *p = str; *p; p++) {
        *p = toupper(*p);
    }
}

void toLowerCase(char *str) {
    for (char *p = str; *p; p++) {
        *p = tolower(*p);
    }
}

int getLength(const char *str) {
    return strlen(str);
}

void displayMenu() {
    printf("String Manipulation Menu:\n");
    printf("1. Reverse the string\n");
    printf("2. Count the vowels in the string\n");
    printf("3. Convert string to uppercase\n");
    printf("4. Convert string to lowercase\n");
    printf("5. Get the length of the string\n");
    printf("6. Convert string to title case\n");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}