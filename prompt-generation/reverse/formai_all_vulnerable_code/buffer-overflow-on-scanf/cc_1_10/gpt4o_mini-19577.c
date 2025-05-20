//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void reverseString(char *str);
void toUpperCase(char *str);
void toLowerCase(char *str);
void removeVowels(char *str);
int findSubstring(const char *str, const char *substr);
void replaceSubstring(char *str, const char *oldSubstr, const char *newSubstr);
void printMenu();
void executeChoice(int choice, char *str);

int main() {
    char str[256];
    int choice;

    printf("Enter a string (max 255 characters): ");
    fgets(str, sizeof(str), stdin);
    // Remove new line character if it exists
    str[strcspn(str, "\n")] = 0; 

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf
        executeChoice(choice, str);
    } while (choice != 6);

    printf("Exiting the program.\n");
    return 0;
}

void printMenu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Reverse String\n");
    printf("2. Convert to Uppercase\n");
    printf("3. Convert to Lowercase\n");
    printf("4. Remove Vowels\n");
    printf("5. Find Substring\n");
    printf("6. Replace Substring\n");
    printf("7. Exit\n");
}

void executeChoice(int choice, char *str) {
    switch (choice) {
        case 1:
            reverseString(str);
            printf("Reversed String: %s\n", str);
            break;
        case 2:
            toUpperCase(str);
            printf("Uppercase String: %s\n", str);
            break;
        case 3:
            toLowerCase(str);
            printf("Lowercase String: %s\n", str);
            break;
        case 4:
            removeVowels(str);
            printf("String without Vowels: %s\n", str);
            break;
        case 5: {
            char substr[100];
            printf("Enter substring to find: ");
            fgets(substr, sizeof(substr), stdin);
            substr[strcspn(substr, "\n")] = 0; // Remove new line character
            int position = findSubstring(str, substr);
            if (position != -1) {
                printf("Substring found at position: %d\n", position);
            } else {
                printf("Substring not found.\n");
            }
            break;
        }
        case 6: {
            char oldSubstr[100], newSubstr[100];
            printf("Enter old substring to replace: ");
            fgets(oldSubstr, sizeof(oldSubstr), stdin);
            oldSubstr[strcspn(oldSubstr, "\n")] = 0; // Remove new line
            printf("Enter new substring: ");
            fgets(newSubstr, sizeof(newSubstr), stdin);
            newSubstr[strcspn(newSubstr, "\n")] = 0; // Remove new line
            replaceSubstring(str, oldSubstr, newSubstr);
            printf("Updated String: %s\n", str);
            break;
        }
        case 7:
            break;
        default:
            printf("Invalid choice, please choose again.\n");
    }
}

// Function to reverse a string
void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

// Function to remove vowels from a string
void removeVowels(char *str) {
    char *ptr = str;
    char *res = (char *)malloc(strlen(str) + 1);
    char *res_ptr = res;

    while (*ptr) {
        if (*ptr != 'a' && *ptr != 'e' && *ptr != 'i' && *ptr != 'o' && *ptr != 'u' &&
            *ptr != 'A' && *ptr != 'E' && *ptr != 'I' && *ptr != 'O' && *ptr != 'U') {
            *res_ptr++ = *ptr;
        }
        ptr++;
    }
    *res_ptr = '\0';
    strcpy(str, res);
    free(res);
}

// Function to find a substring in a string
int findSubstring(const char *str, const char *substr) {
    char *pos = strstr(str, substr);
    if (pos) {
        return pos - str; // Return the position of the substring
    }
    return -1; // Substring not found
}

// Function to replace a substring with another substring
void replaceSubstring(char *str, const char *oldSubstr, const char *newSubstr) {
    char *pos, buffer[256];
    int oldLen = strlen(oldSubstr);
    int newLen = strlen(newSubstr);

    // Temporary buffer to store result
    while ((pos = strstr(str, oldSubstr)) != NULL) {
        // Copy the part before the old substring
        strncpy(buffer, str, pos - str);
        buffer[pos - str] = '\0';

        // Concatenate new substring
        strcat(buffer, newSubstr);
        
        // Concatenate the remaining part of original string
        strcat(buffer, pos + oldLen);

        // Update the original string
        strcpy(str, buffer);
    }
}