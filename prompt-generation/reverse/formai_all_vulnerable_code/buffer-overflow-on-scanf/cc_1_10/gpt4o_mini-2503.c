//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void reverseString(char *str);
void toUpperCase(char *str);
void countVowels(char *str, int *vowelCount);
void substrOccurrences(char *str, char *substr);
void replaceSubstring(char *str, char *target, char *replacement);
void stringManipulationMenu();

int main() {
    stringManipulationMenu();
    return 0;
}

void stringManipulationMenu() {
    char inputString[256];
    char target[50], replacement[50];
    char repeat;
    int choice, vowelCount = 0;
    
    do {
        printf("\n--- String Manipulation Menu ---\n");
        printf("1. Reverse a String\n");
        printf("2. Convert String to Uppercase\n");
        printf("3. Count Vowels in String\n");
        printf("4. Find Substring Occurrences\n");
        printf("5. Replace Substring\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        printf("Enter your string: ");
        fgets(inputString, sizeof(inputString), stdin);
        inputString[strcspn(inputString, "\n")] = 0; // Remove newline character
        
        switch (choice) {
            case 1:
                reverseString(inputString);
                printf("Reversed String: %s\n", inputString);
                break;
            case 2:
                toUpperCase(inputString);
                printf("Uppercase String: %s\n", inputString);
                break;
            case 3:
                countVowels(inputString, &vowelCount);
                printf("Number of Vowels: %d\n", vowelCount);
                break;
            case 4:
                printf("Enter substring to find: ");
                fgets(target, sizeof(target), stdin);
                target[strcspn(target, "\n")] = 0; // Remove newline character
                substrOccurrences(inputString, target);
                break;
            case 5:
                printf("Enter substring to replace: ");
                fgets(target, sizeof(target), stdin);
                target[strcspn(target, "\n")] = 0; // Remove newline character
                printf("Enter replacement string: ");
                fgets(replacement, sizeof(replacement), stdin);
                replacement[strcspn(replacement, "\n")] = 0; // Remove newline character
                replaceSubstring(inputString, target, replacement);
                printf("Modified String: %s\n", inputString);
                break;
            default:
                printf("Invalid Choice! Please try again.\n");
                break;
        }

        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &repeat);
    } while (repeat == 'y' || repeat == 'Y');
}

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }
}

void countVowels(char *str, int *vowelCount) {
    *vowelCount = 0;
    char vowels[] = "aeiouAEIOU";
    for (int i = 0; str[i]; i++) {
        if (strchr(vowels, str[i])) {
            (*vowelCount)++;
        }
    }
}

void substrOccurrences(char *str, char *substr) {
    char *tempStr = str;
    int count = 0;
    while ((tempStr = strstr(tempStr, substr)) != NULL) {
        count++;
        tempStr++;
    }
    printf("Occurrences of '%s': %d\n", substr, count);
}

void replaceSubstring(char *str, char *target, char *replacement) {
    char *pos, temp[256];
    int index = 0;
    int targetLen = strlen(target);
    
    while ((pos = strstr(str, target)) != NULL) {
        // Copy everything before the target
        strncpy(temp, str, pos - str);
        temp[pos - str] = '\0';
        // Append the replacement string
        strcat(temp, replacement);
        // Append the rest of the original string
        strcat(temp, pos + targetLen);
        strcpy(str, temp);
    }
}