//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void displayMenu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Reverse the string\n");
    printf("2. Convert to uppercase\n");
    printf("3. Convert to lowercase\n");
    printf("4. Find substring\n");
    printf("5. Concatenate another string\n");
    printf("6. Exit\n");
    printf("Choose an option (1-6): ");
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

void findSubstring(char *str, char *substr) {
    if (strstr(str, substr) != NULL) {
        printf("Substring '%s' found in '%s'\n", substr, str);
    } else {
        printf("Substring '%s' not found in '%s'\n", substr, str);
    }
}

void concatenateStrings(char *str1, char *str2) {
    strcat(str1, str2);
}

int main() {
    char mainString[MAX_LEN];
    char inputString[MAX_LEN];
    int option;

    printf("Enter the main string (max %d characters): ", MAX_LEN - 1);
    fgets(mainString, MAX_LEN, stdin);
    mainString[strcspn(mainString, "\n")] = '\0'; // Remove newline character

    do {
        displayMenu();
        scanf("%d", &option);
        getchar(); // Consume newline character after scanf

        switch (option) {
            case 1:
                reverseString(mainString);
                printf("Reversed string: %s\n", mainString);
                break;
            case 2:
                toUpperCase(mainString);
                printf("Uppercase string: %s\n", mainString);
                break;
            case 3:
                toLowerCase(mainString);
                printf("Lowercase string: %s\n", mainString);
                break;
            case 4:
                printf("Enter substring to find: ");
                fgets(inputString, MAX_LEN, stdin);
                inputString[strcspn(inputString, "\n")] = '\0'; // Remove newline
                findSubstring(mainString, inputString);
                break;
            case 5:
                printf("Enter string to concatenate: ");
                fgets(inputString, MAX_LEN, stdin);
                inputString[strcspn(inputString, "\n")] = '\0'; // Remove newline
                if (strlen(mainString) + strlen(inputString) < MAX_LEN) {
                    concatenateStrings(mainString, inputString);
                    printf("Concatenated string: %s\n", mainString);
                } else {
                    printf("Error: Resulting string exceeds maximum length.\n");
                }
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please choose a number between 1 and 6.\n");
                break;
        }
    } while (option != 6);

    return 0;
}