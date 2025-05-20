//FormAI DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

char *to_upper(char *str);
char *to_lower(char *str);
char *reverse(char *str);
char *replace(char *str, char old_char, char new_char);

int main() {
    char input_string[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);
    input_string[strcspn(input_string, "\n")] = '\0'; // remove newline character

    int choice;
    do {
        printf("\n---STRING MANIPULATION MENU---\n");
        printf("1. Convert to uppercase\n");
        printf("2. Convert to lowercase\n");
        printf("3. Reverse the string\n");
        printf("4. Replace a character\n");
        printf("5. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n***Uppercase string***\n");
            printf("%s\n", to_upper(input_string));
        } else if (choice == 2) {
            printf("\n***Lowercase string***\n");
            printf("%s\n", to_lower(input_string));
        } else if (choice == 3) {
            printf("\n***Reversed string***\n");
            printf("%s\n", reverse(input_string));
        } else if (choice == 4) {
            char old_char, new_char;
            printf("Enter the old character to replace: ");
            scanf(" %c", &old_char);
            printf("Enter the new character: ");
            scanf(" %c", &new_char);

            printf("\n***String with replaced characters***\n");
            printf("%s\n", replace(input_string, old_char, new_char));
        } else if (choice == 5) {
            printf("Exiting...");
            exit(0);
        } else {
            printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

char *to_upper(char *str) {
    char *new_str = malloc(MAX_STRING_LENGTH * sizeof(char));
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        new_str[i] = toupper(str[i]);
    }
    new_str[i] = '\0';
    return new_str;
}

char *to_lower(char *str) {
    char *new_str = malloc(MAX_STRING_LENGTH * sizeof(char));
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        new_str[i] = tolower(str[i]);
    }
    new_str[i] = '\0';
    return new_str;
}

char *reverse(char *str) {
    char *new_str = malloc(MAX_STRING_LENGTH * sizeof(char));
    int length = strlen(str);
    int i;
    for (i = 0; i < length; i++) {
        new_str[i] = str[length - 1 - i];
    }
    new_str[i] = '\0';
    return new_str;
}

char *replace(char *str, char old_char, char new_char) {
    char *new_str = malloc(MAX_STRING_LENGTH * sizeof(char));
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == old_char) {
            new_str[i] = new_char;
        } else {
            new_str[i] = str[i];
        }
    }
    new_str[i] = '\0';
    return new_str;
}