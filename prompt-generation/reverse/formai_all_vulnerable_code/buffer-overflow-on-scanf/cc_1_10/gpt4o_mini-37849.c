//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void toUpperCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int countVowels(char str[]) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

void displayMenu() {
    printf("String Manipulation Menu:\n");
    printf("1. Reverse a string\n");
    printf("2. Convert string to uppercase\n");
    printf("3. Count vowels in a string\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
}

int main() {
    char str[MAX_LENGTH];
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        if (choice == 4) {
            printf("Exiting the program.\n");
            break;
        }

        printf("Enter a string: ");
        fgets(str, MAX_LENGTH, stdin);
        str[strcspn(str, "\n")] = '\0'; // Remove the newline character

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
                {
                    int vowels = countVowels(str);
                    printf("Number of vowels: %d\n", vowels);
                }
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
        printf("\n");
    }

    return 0;
}