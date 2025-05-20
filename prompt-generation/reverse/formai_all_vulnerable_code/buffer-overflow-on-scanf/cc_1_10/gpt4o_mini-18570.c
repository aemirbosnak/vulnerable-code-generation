//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void reverseString(char* str);
void toUpperCase(char* str);
void toLowerCase(char* str);
void findSubstring(char* source, char* substring);
void replaceSubstring(char* source, char* target, char* replacement);
void printMenu();
void processChoice(int choice, char* str);

int main() {
    char str[256];
    int choice = 0;

    printf("Enter a string (max 255 characters): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character

    while (choice != 6) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        processChoice(choice, str);
    }

    return 0;
}

void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("Reversed string: %s\n", str);
}

void toUpperCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i];
    }
    printf("Uppercase string: %s\n", str);
}

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
    }
    printf("Lowercase string: %s\n", str);
}

void findSubstring(char* source, char* substring) {
    char* pos = strstr(source, substring);
    if (pos) {
        printf("Substring \"%s\" found at position: %ld\n", substring, pos - source);
    } else {
        printf("Substring \"%s\" not found in the source string.\n", substring);
    }
}

void replaceSubstring(char* source, char* target, char* replacement) {
    char* pos, temp[256];
    int index = 0;
    int targetLen = strlen(target);
    int replacementLen = strlen(replacement);

    while ((pos = strstr(source + index, target)) != NULL) {
        strncpy(temp, source, pos - source);
        temp[pos - source] = '\0';
        strcat(temp, replacement);
        strcat(temp, pos + targetLen);
        strcpy(source, temp);
        index = pos - source + replacementLen;
    }
    printf("String after replacement: %s\n", source);
}

void printMenu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Reverse String\n");
    printf("2. Convert to Uppercase\n");
    printf("3. Convert to Lowercase\n");
    printf("4. Find Substring\n");
    printf("5. Replace Substring\n");
    printf("6. Exit\n");
}

void processChoice(int choice, char* str) {
    char substring[256], target[256], replacement[256];
    switch (choice) {
        case 1:
            reverseString(str);
            break;
        case 2:
            toUpperCase(str);
            break;
        case 3:
            toLowerCase(str);
            break;
        case 4:
            printf("Enter substring to find: ");
            scanf("%s", substring);
            findSubstring(str, substring);
            break;
        case 5:
            printf("Enter substring to replace: ");
            scanf("%s", target);
            printf("Enter replacement substring: ");
            scanf("%s", replacement);
            replaceSubstring(str, target, replacement);
            break;
        case 6:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}