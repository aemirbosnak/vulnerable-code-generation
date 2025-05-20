//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void reverseString(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int isPalindrome(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

void countCharacterOccurrences(char str[]) {
    int count[256] = {0}; // Assuming ASCII
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }

    printf("\nCharacter Occurrences:\n");
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("'%c': %d\n", i, count[i]);
        }
    }
}

void toUpperCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void displayMenu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Reverse String\n");
    printf("2. Check for Palindrome\n");
    printf("3. Count Character Occurrences\n");
    printf("4. Convert to Upper Case\n");
    printf("5. Convert to Lower Case\n");
    printf("6. Exit\n");
}

int main() {
    char input[MAX_LENGTH];
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        
        if (choice == 6) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        
        printf("Enter a string: ");
        scanf(" %[^\n]", input);  // Read string with spaces
        
        switch (choice) {
            case 1:
                printf("Original String: %s\n", input);
                reverseString(input);
                printf("Reversed String: %s\n", input);
                break;
            case 2:
                printf("Original String: %s\n", input);
                if (isPalindrome(input)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
                }
                break;
            case 3:
                printf("Original String: %s\n", input);
                countCharacterOccurrences(input);
                break;
            case 4:
                printf("Original String: %s\n", input);
                toUpperCase(input);
                printf("Upper Case String: %s\n", input);
                break;
            case 5:
                printf("Original String: %s\n", input);
                toLowerCase(input);
                printf("Lower Case String: %s\n", input);
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}