//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 1000
#define LOWERCASE 1
#define UPPERCASE 0

// Function to capitalize or uncapitalize the given string based on the provided mode
void case_converter(char str[], int mode) {
    int i = 0;
    if (mode == UPPERCASE) {
        while (str[i] != '\0') {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 32;
            }
            i++;
        }
    } else {
        while (str[i] != '\0') {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            }
            i++;
        }
    }
}

// Function to reverse the given string
void str_reverse(char str[]) {
    int len, i;
    char temp;
    len = strlen(str) - 1;
    for (i = 0; i < len; i++, len--) {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
    }
}

// Function to remove the vowels from the given string
void avoid_vowels(char str[]) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        while (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            for (j = i; str[j] != '\0'; j++) {
                str[j] = str[j + 1];
            }
            str[j] = '\0';
        }
    }
}

int main() {
    int choice, mode;
    char str[MAX_STR_LEN];
    printf("Enter a string (max %d characters): ", MAX_STR_LEN);
    fgets(str, MAX_STR_LEN, stdin);
    // Removing trailing newline from fgets output
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    do {
        printf("\nWhat do you want to do with this string?\n");
        printf("1. Capitalize all letters\n");
        printf("2. Uncapitalize all letters\n");
        printf("3. Reverse the string\n");
        printf("4. Remove the vowels from the string\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                mode = UPPERCASE;
                case_converter(str, mode);
                printf("New String: %s\n", str);
                break;
            case 2:
                mode = LOWERCASE;
                case_converter(str, mode);
                printf("New String: %s\n", str);
                break;
            case 3:
                str_reverse(str);
                printf("New String: %s\n", str);
                break;
            case 4:
                avoid_vowels(str);
                printf("New String: %s\n", str);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}