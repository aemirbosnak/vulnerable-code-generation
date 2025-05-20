//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

void to_upper_case(char *str);
void to_lower_case(char *str);
void reverse_string(char *str);
void replace_spaces(char *str, char replacement);
void show_menu();
void execute_choice(int choice, char *str);

int main() {
    char input[MAX_STRING_LENGTH];
    int choice;

    printf("Welcome to the Retro C String Manipulation Program!\n");
    printf("Please enter a string (max 99 characters, as the last one is a null terminator): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character
    input[strcspn(input, "\n")] = 0;

    do {
        show_menu();
        printf("Choose an option (1 - 6): ");
        scanf("%d", &choice);
        getchar(); // consume the newline character

        if (choice > 0 && choice < 6) {
            execute_choice(choice, input);
            printf("Current string: \"%s\"\n\n", input);
        } else if (choice != 6) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    printf("Thank you for using the string manipulation program! Goodbye!\n");
    return 0;
}

void show_menu() {
    printf("Menu:\n");
    printf("1. Convert to Upper Case\n");
    printf("2. Convert to Lower Case\n");
    printf("3. Reverse String\n");
    printf("4. Replace Spaces\n");
    printf("5. Display String Length\n");
    printf("6. Exit\n");
}

void to_upper_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char) str[i]);
    }
}

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

void reverse_string(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void replace_spaces(char *str, char replacement) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            str[i] = replacement;
        }
    }
}

void execute_choice(int choice, char *str) {
    char replacement_char;
    int length;

    switch (choice) {
        case 1:
            to_upper_case(str);
            printf("Converted to Upper Case.\n");
            break;
        case 2:
            to_lower_case(str);
            printf("Converted to Lower Case.\n");
            break;
        case 3:
            reverse_string(str);
            printf("String Reversed.\n");
            break;
        case 4:
            printf("Enter a character to replace spaces with: ");
            replacement_char = getchar();
            replace_spaces(str, replacement_char);
            printf("Spaces replaced with '%c'.\n", replacement_char);
            break;
        case 5:
            length = strlen(str);
            printf("The length of the string is: %d characters.\n", length);
            break;
        default:
            printf("Exiting...\n");
            break;
    }
}