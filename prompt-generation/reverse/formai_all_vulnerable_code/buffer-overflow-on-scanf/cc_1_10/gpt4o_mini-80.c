//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

void toUpperCase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void findAndReplace(char *str, const char *find, const char *replace) {
    char buffer[MAX_LENGTH];
    char *pos;
    int findLen = strlen(find);
    int replaceLen = strlen(replace);
    
    while ((pos = strstr(str, find)) != NULL) {
        strncpy(buffer, str, pos - str);
        buffer[pos - str] = '\0';
        sprintf(buffer + (pos - str), "%s%s", replace, pos + findLen);
        strcpy(str, buffer);
    }
}

void printMenu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Convert to Upper Case\n");
    printf("2. Convert to Lower Case\n");
    printf("3. Reverse a String\n");
    printf("4. Find and Replace\n");
    printf("5. Exit\n");
}

int main() {
    char str[MAX_LENGTH];
    int choice;
    char find[MAX_LENGTH], replace[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character

    do {
        printMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                toUpperCase(str);
                printf("Upper Case: %s\n", str);
                break;
            case 2:
                toLowerCase(str);
                printf("Lower Case: %s\n", str);
                break;
            case 3:
                reverseString(str);
                printf("Reversed String: %s\n", str);
                break;
            case 4:
                printf("Enter the string to find: ");
                fgets(find, sizeof(find), stdin);
                find[strcspn(find, "\n")] = 0; // Remove newline
                printf("Enter the replacement string: ");
                fgets(replace, sizeof(replace), stdin);
                replace[strcspn(replace, "\n")] = 0; // Remove newline
                findAndReplace(str, find, replace);
                printf("Updated String: %s\n", str);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 5);

    return 0;
}