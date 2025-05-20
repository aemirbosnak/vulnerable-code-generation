//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

void displayMenu() {
    printf("\n==============================\n");
    printf("       String Manipulation     \n");
    printf("==============================\n");
    printf("1. Reverse a String\n");
    printf("2. Convert to Uppercase\n");
    printf("3. Find Length of a String\n");
    printf("4. Concatenate Two Strings\n");
    printf("5. Exit\n");
    printf("==============================\n");
    printf("Choose an option (1-5): ");
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("Reversed String: %s\n", str);
}

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
    printf("Uppercase String: %s\n", str);
}

int getStringLength(char *str) {
    return strlen(str);
}

void concatenateStrings(char *str1, char *str2) {
    char result[MAX_LEN * 2];  // Ensure enough space for concatenated string
    strncpy(result, str1, MAX_LEN);
    strncat(result, str2, MAX_LEN - strlen(result) - 1);  // Prevent buffer overflow
    printf("Concatenated String: %s\n", result);
}

int main() {
    int choice;
    char str[MAX_LEN];
    char str2[MAX_LEN];

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // Consume newline character left by scanf
        
        switch (choice) {
            case 1:
                printf("Enter a string to reverse: ");
                fgets(str, MAX_LEN, stdin);
                str[strcspn(str, "\n")] = 0;  // Remove newline character
                reverseString(str);
                break;

            case 2:
                printf("Enter a string to convert to uppercase: ");
                fgets(str, MAX_LEN, stdin);
                str[strcspn(str, "\n")] = 0; // Remove newline character
                toUpperCase(str);
                break;

            case 3:
                printf("Enter a string to find its length: ");
                fgets(str, MAX_LEN, stdin);
                str[strcspn(str, "\n")] = 0; // Remove newline character
                printf("Length of the string: %d\n", getStringLength(str));
                break;

            case 4:
                printf("Enter first string: ");
                fgets(str, MAX_LEN, stdin);
                str[strcspn(str, "\n")] = 0; // Remove newline character

                printf("Enter second string: ");
                fgets(str2, MAX_LEN, stdin);
                str2[strcspn(str2, "\n")] = 0; // Remove newline character
                
                concatenateStrings(str, str2);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please choose a valid option.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}