//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 256

void to_uppercase(char *str) {
    while (*str) {
        *str = toupper((unsigned char) *str);
        str++;
    }
}

void to_lowercase(char *str) {
    while (*str) {
        *str = tolower((unsigned char) *str);
        str++;
    }
}

void reverse_string(char *str, char *reversed) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        reversed[i] = str[n - 1 - i];
    }
    reversed[n] = '\0'; // Null-terminate the reversed string
}

void concatenate_strings(char *dest, const char *src) {
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0'; // Null-terminate the concatenated string
}

char* find_substring(const char *haystack, const char *needle) {
    return strstr(haystack, needle);
}

int count_vowels(const char *str) {
    int count = 0;
    while (*str) {
        if (strchr("aeiouAEIOU", *str)) {
            count++;
        }
        str++;
    }
    return count;
}

void print_menu() {
    printf("String Manipulation Menu:\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Convert to Lowercase\n");
    printf("3. Reverse String\n");
    printf("4. Concatenate Strings\n");
    printf("5. Find Substring\n");
    printf("6. Count Vowels\n");
    printf("0. Exit\n");
}

int main() {
    char input[MAX_STRING_LENGTH];
    char input2[MAX_STRING_LENGTH];
    char reversed[MAX_STRING_LENGTH];
    int choice;

    while (1) {
        print_menu();
        printf("Choose an option (0 to exit): ");
        scanf("%d", &choice);
        getchar(); // to consume newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline
                to_uppercase(input);
                printf("Uppercase: %s\n", input);
                break;

            case 2:
                printf("Enter a string: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline
                to_lowercase(input);
                printf("Lowercase: %s\n", input);
                break;

            case 3:
                printf("Enter a string: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline
                reverse_string(input, reversed);
                printf("Reversed: %s\n", reversed);
                break;

            case 4:
                printf("Enter first string: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline
                printf("Enter second string: ");
                fgets(input2, sizeof(input2), stdin);
                input2[strcspn(input2, "\n")] = 0; // Remove newline
                concatenate_strings(input, input2);
                printf("Concatenated: %s\n", input);
                break;

            case 5:
                printf("Enter haystack string: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline
                printf("Enter needle string: ");
                fgets(input2, sizeof(input2), stdin);
                input2[strcspn(input2, "\n")] = 0; // Remove newline
                char *result = find_substring(input, input2);
                if (result) {
                    printf("Substring found at position: %ld\n", result - input);
                } else {
                    printf("Substring not found!\n");
                }
                break;

            case 6:
                printf("Enter a string: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline
                int vowel_count = count_vowels(input);
                printf("Number of vowels: %d\n", vowel_count);
                break;

            case 0:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0; // To satisfy the main function return type
}