//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256
#define MAX_WORDS 50

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

void split_into_words(const char *str, char words[MAX_WORDS][BUFFER_SIZE], int *word_count) {
    const char *delimiter = " \n";
    char *token;
    char *copy = strdup(str);
    token = strtok(copy, delimiter);
    *word_count = 0;

    while (token != NULL && *word_count < MAX_WORDS) {
        strncpy(words[*word_count], token, BUFFER_SIZE - 1);
        words[*word_count][BUFFER_SIZE - 1] = '\0';  // Ensure null termination
        (*word_count)++;
        token = strtok(NULL, delimiter);
    }
    
    free(copy);
}

void print_words(const char words[MAX_WORDS][BUFFER_SIZE], int word_count) {
    printf("Words extracted:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%d: %s\n", i + 1, words[i]);
    }
}

void caesar_cipher(char *str, int shift) {
    for (int i = 0; str[i]; ++i) {
        char base = isupper(str[i]) ? 'A' : 'a';
        if (isalpha(str[i])) {
            str[i] = (str[i] - base + shift) % 26 + base;
        }
    }
}

int main() {
    char input[BUFFER_SIZE];
    char words[MAX_WORDS][BUFFER_SIZE];
    int word_count = 0;
    int choice = 0;

    printf("Enter a string: ");
    fgets(input, BUFFER_SIZE, stdin);

    while (choice != 5) {
        printf("\nChoose an option:\n");
        printf("1. Convert to uppercase\n");
        printf("2. Reverse string\n");
        printf("3. Split into words\n");
        printf("4. Apply Caesar Cipher\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character after choice

        switch (choice) {
            case 1:
                to_uppercase(input);
                printf("Uppercase string: %s\n", input);
                break;
            case 2:
                reverse_string(input);
                printf("Reversed string: %s\n", input);
                break;
            case 3:
                split_into_words(input, words, &word_count);
                print_words(words, word_count);
                break;
            case 4: {
                int shift;
                printf("Enter shift value for Caesar Cipher: ");
                scanf("%d", &shift);
                caesar_cipher(input, shift);
                printf("Ciphered string: %s\n", input);
                break;
            }
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}