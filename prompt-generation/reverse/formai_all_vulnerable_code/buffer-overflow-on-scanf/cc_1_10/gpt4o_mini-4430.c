//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

void to_uppercase(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

void to_lowercase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void replace_substring(char *str, const char *old, const char *new) {
    char buffer[MAX_LENGTH];
    char *pos;

    // Find the position of the old substring
    while ((pos = strstr(str, old)) != NULL) {
        // Copy characters from the beginning of the str to pos
        strncpy(buffer, str, pos - str);
        buffer[pos - str] = '\0';
        
        // Append the new substring
        strcat(buffer, new);

        // Append the remaining part after the old substring
        strcat(buffer, pos + strlen(old));
        
        // Copy back to str
        strcpy(str, buffer);
    }
}

void count_words_and_lines(char *str, int *line_count, int *word_count) {
    *line_count = 1;
    *word_count = 0;
    
    char *token = strtok(str, " \n");
    while (token != NULL) {
        (*word_count)++;
        token = strtok(NULL, " \n");
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            (*line_count)++;
        }
    }
}

void print_statistics(char *text, int lines, int words) {
    printf("Statistics:\n");
    printf("Total Lines: %d\n", lines);
    printf("Total Words: %d\n", words);
}

void menu() {
    printf("Text Processing Program\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Convert to Lowercase\n");
    printf("3. Replace Substring\n");
    printf("4. Count Words and Lines\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

int main() {
    char text[MAX_LINES * MAX_LENGTH];
    int option, line_count, word_count;
    char search_str[MAX_LENGTH], replace_str[MAX_LENGTH];

    printf("Enter text (finished with an empty line):\n");
    
    // Read text
    int i = 0;
    while (i < MAX_LINES) {
        fgets(text + i * MAX_LENGTH, MAX_LENGTH, stdin);
        if (strcmp(text + i * MAX_LENGTH, "\n") == 0) break; // Stop on an empty line
        i++;
    }
    text[i * MAX_LENGTH] = '\0'; // Null terminate the string.

    while (1) {
        menu();
        scanf("%d", &option);
        getchar(); // Consume the newline character after option input

        switch (option) {
            case 1: // Convert to Uppercase
                to_uppercase(text);
                printf("Converted to Uppercase:\n%s", text);
                break;

            case 2: // Convert to Lowercase
                to_lowercase(text);
                printf("Converted to Lowercase:\n%s", text);
                break;

            case 3: // Replace Substring
                printf("Enter the substring to replace: ");
                fgets(search_str, MAX_LENGTH, stdin);
                search_str[strcspn(search_str, "\n")] = 0; // Remove trailing newline

                printf("Enter the new substring: ");
                fgets(replace_str, MAX_LENGTH, stdin);
                replace_str[strcspn(replace_str, "\n")] = 0; // Remove trailing newline

                replace_substring(text, search_str, replace_str);
                printf("Modified Text:\n%s", text);
                break;

            case 4: // Count Words and Lines
                count_words_and_lines(text, &line_count, &word_count);
                print_statistics(text, line_count, word_count);
                break;

            case 5: // Exit
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid option! Please select again.\n");
                break;
        }
    }
    return 0;
}