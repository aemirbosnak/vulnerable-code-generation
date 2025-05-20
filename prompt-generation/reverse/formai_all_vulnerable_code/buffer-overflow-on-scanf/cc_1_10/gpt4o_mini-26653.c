//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void getStringInput(char* str, int length);
void printMenu();
void reverseString(char* str);
void concatenateStrings(char* str1, char* str2, char* result);
int searchSubstring(const char* str, const char* substr);
void toUpperCase(char* str);
void toLowerCase(char* str);

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char result[MAX_LENGTH * 2];
    int choice;

    getStringInput(str1, MAX_LENGTH);
    
    while (1) {
        printMenu();
        printf("Enter your choice (1-5, 0 to exit): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                reverseString(str1);
                printf("Reversed string: %s\n", str1);
                break;
            case 2:
                printf("Enter the second string to concatenate: ");
                getStringInput(str2, MAX_LENGTH);
                concatenateStrings(str1, str2, result);
                printf("Concatenated string: %s\n", result);
                break;
            case 3:
                printf("Enter substring to search: ");
                getStringInput(str2, MAX_LENGTH);
                int index = searchSubstring(str1, str2);
                if (index != -1) {
                    printf("Substring '%s' found at index %d.\n", str2, index);
                } else {
                    printf("Substring '%s' not found.\n", str2);
                }
                break;
            case 4:
                toUpperCase(str1);
                printf("Uppercase string: %s\n", str1);
                break;
            case 5:
                toLowerCase(str1);
                printf("Lowercase string: %s\n", str1);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Functions Implementation

void getStringInput(char* str, int length) {
    getchar();  // Clear newline character from input buffer
    printf("Enter a string (max %d characters): ", length - 1);
    fgets(str, length, stdin);
    str[strcspn(str, "\n")] = 0;  // Remove trailing newline
}

void printMenu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Reverse String\n");
    printf("2. Concatenate Strings\n");
    printf("3. Search Substring\n");
    printf("4. Convert to Uppercase\n");
    printf("5. Convert to Lowercase\n");
}

void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void concatenateStrings(char* str1, char* str2, char* result) {
    strcpy(result, str1);
    strcat(result, str2);
}

int searchSubstring(const char* str, const char* substr) {
    char* pos = strstr(str, substr);
    if (pos) {
        return pos - str;  // Return index
    }
    return -1;  // Not found
}

void toUpperCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}