//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

void reverseString(char *str);
void convertToUpper(char *str);
int countVowels(const char *str);
int findSubstring(const char *str, const char *substr);
void clearBuffer();

int main() {
    char str[MAX_LEN];
    char substr[MAX_LEN];
    int choice;

    while (1) {
        printf("\nString Manipulation Program\n");
        printf("1. Enter a new string\n");
        printf("2. Reverse the string\n");
        printf("3. Convert to uppercase\n");
        printf("4. Count vowels\n");
        printf("5. Find substring\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        clearBuffer();  // Clears the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter a string (max %d characters): ", MAX_LEN - 1);
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = 0; // Remove newline character
                break;
            case 2:
                printf("Original String: %s\n", str);
                reverseString(str);
                printf("Reversed String: %s\n", str);
                break;
            case 3:
                printf("Original String: %s\n", str);
                convertToUpper(str);
                printf("Uppercase String: %s\n", str);
                break;
            case 4:
                printf("The number of vowels in the string: %d\n", countVowels(str));
                break;
            case 5:
                printf("Enter the substring to find: ");
                fgets(substr, sizeof(substr), stdin);
                substr[strcspn(substr, "\n")] = 0; // Remove newline character
                int index = findSubstring(str, substr);
                if (index != -1) {
                    printf("Substring found at index: %d\n", index);
                } else {
                    printf("Substring not found.\n");
                }
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void convertToUpper(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char) str[i]);
    }
}

int countVowels(const char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char ch = tolower((unsigned char) str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

int findSubstring(const char *str, const char *substr) {
    char *pos = strstr(str, substr);
    if (pos == NULL) {
        return -1; // Not found
    }
    return (int)(pos - str); // Return index of the first occurrence
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}