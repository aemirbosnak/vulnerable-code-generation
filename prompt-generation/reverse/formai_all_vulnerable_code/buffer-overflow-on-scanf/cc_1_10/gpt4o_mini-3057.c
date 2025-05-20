//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// Function prototypes
void reverseString(char *str);
void toUppercase(char *str);
void toLowercase(char *str);
int countVowels(const char *str);
void replaceSpacesWithUnderscore(char *str);
void printMenu();
void executeOption(int option, char *str);

int main() {
    char inputString[MAX_STR_LEN];
    
    // Taking input string from the user
    printf("Enter a string (max length %d): ", MAX_STR_LEN-1);
    fgets(inputString, MAX_STR_LEN, stdin);
    
    // Remove newline character if present
    inputString[strcspn(inputString, "\n")] = 0;

    int option;
    
    // Display menu and execute options until user chooses to exit
    do {
        printMenu();
        printf("Choose an option (1-5, 0 to exit): ");
        scanf("%d", &option);
        getchar(); // Clear newline from buffer
        
        if (option >= 1 && option <= 5) {
            executeOption(option, inputString);
        } else if (option != 0) {
            printf("Invalid option. Please choose again.\n");
        }
    } while (option != 0);
    
    printf("Exiting the program. Goodbye!\n");
    return 0;
}

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("Reversed string: %s\n", str);
}

// Function to convert a string to uppercase
void toUppercase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
    printf("Uppercase string: %s\n", str);
}

// Function to convert a string to lowercase
void toLowercase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    printf("Lowercase string: %s\n", str);
}

// Function to count vowels in a string
int countVowels(const char *str) {
    int count = 0;
    for(int i = 0; str[i]; i++) {
        char ch = tolower(str[i]);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

// Function to replace spaces with underscores
void replaceSpacesWithUnderscore(char *str) {
    for(int i = 0; str[i]; i++) {
        if(str[i] == ' ') {
            str[i] = '_';
        }
    }
    printf("String with underscores: %s\n", str);
}

// Function to print the menu
void printMenu() {
    printf("\n--- String Manipulation Menu ---\n");
    printf("1. Reverse the string\n");
    printf("2. Convert to uppercase\n");
    printf("3. Convert to lowercase\n");
    printf("4. Count vowels\n");
    printf("5. Replace spaces with underscores\n");
}

// Function to execute the selected option
void executeOption(int option, char *str) {
    // Create a copy of the original string to preserve it for each operation
    char strCopy[MAX_STR_LEN];
    strncpy(strCopy, str, MAX_STR_LEN);

    switch(option) {
        case 1:
            reverseString(strCopy);
            break;
        case 2:
            toUppercase(strCopy);
            break;
        case 3:
            toLowercase(strCopy);
            break;
        case 4:
            printf("Number of vowels: %d\n", countVowels(str));
            break;
        case 5:
            replaceSpacesWithUnderscore(strCopy);
            break;
        default:
            printf("This option does not exist.\n");
    }
}