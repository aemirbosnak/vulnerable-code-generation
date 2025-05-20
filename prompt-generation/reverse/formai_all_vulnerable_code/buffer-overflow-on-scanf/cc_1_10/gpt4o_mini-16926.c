//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to convert string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to convert string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to count vowels in a string
int countVowels(const char *str) {
    int count = 0;
    char vowels[] = "AEIOUaeiou";
    for (int i = 0; str[i]; i++) {
        if (strchr(vowels, str[i])) {
            count++;
        }
    }
    return count;
}

// Function to display menu
void displayMenu() {
    printf("\nWelcome to the Fun String Manipulation Game!\n");
    printf("Please choose an option:\n");
    printf("1. Reverse the string\n");
    printf("2. Convert to uppercase\n");
    printf("3. Convert to lowercase\n");
    printf("4. Count vowels\n");
    printf("5. Exit\n");
}

int main() {
    char str[MAX_LENGTH];
    int choice = 0;
    
    printf("Enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                reverseString(str);
                printf("Reversed string: %s\n", str);
                break;
            case 2:
                toUpperCase(str);
                printf("Uppercase string: %s\n", str);
                break;
            case 3:
                toLowerCase(str);
                printf("Lowercase string: %s\n", str);
                break;
            case 4:
                printf("Number of vowels in the string: %d\n", countVowels(str));
                break;
            case 5:
                printf("Exiting the game. Thank you for playing!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}