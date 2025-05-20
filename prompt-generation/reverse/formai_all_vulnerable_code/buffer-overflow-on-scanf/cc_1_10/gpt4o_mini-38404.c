//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 100

void to_uppercase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void concat_strings(char *dest, const char *src) {
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

void custom_string_copy(char *dest, const char *src) {
    while ((*dest++ = *src++));
}

void print_menu() {
    printf("\n*** Retro C String Manipulation Menu ***\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Reverse String\n");
    printf("3. Concatenate Strings\n");
    printf("4. Custom String Copy\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");
}

int main() {
    char str1[MAX_STR_LEN];
    char str2[MAX_STR_LEN];
    char result[MAX_STR_LEN];
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);
        getchar();  // Consume the newline character
        
        switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(str1, MAX_STR_LEN, stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove newline
                to_uppercase(str1);
                printf("Uppercase: %s\n", str1);
                break;
            case 2:
                printf("Enter a string: ");
                fgets(str1, MAX_STR_LEN, stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove newline
                reverse_string(str1);
                printf("Reversed: %s\n", str1);
                break;
            case 3:
                printf("Enter first string: ");
                fgets(str1, MAX_STR_LEN, stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove newline
                printf("Enter second string: ");
                fgets(str2, MAX_STR_LEN, stdin);
                str2[strcspn(str2, "\n")] = '\0'; // Remove newline
                custom_string_copy(result, str1);
                concat_strings(result, str2);
                printf("Concatenated: %s\n", result);
                break;
            case 4:
                printf("Enter source string: ");
                fgets(str1, MAX_STR_LEN, stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove newline
                custom_string_copy(result, str1);
                printf("Copied String: %s\n", result);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}