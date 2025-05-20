//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_SIZE 1000
#define MAX_WORDS 100
#define WORD_SIZE 20

// Function to check if a given character is an alphabet or not
int is_alphabet(char c) {
    return (isalpha(c) || (isdigit(c) && (c >= '1' && c <= '9')));
}

// Function to extract words from an email
void extract_words(char email[], char words[][WORD_SIZE], int *num_words) {
    int i = 0, j = 0, word_index = 0;
    char word[WORD_SIZE];

    while (email[i] != '\0') {
        if (is_alphabet(email[i])) {
            word[j] = tolower(email[i]);
            j++;
        } else {
            if (j > 0) {
                word[j] = '\0';
                strcpy(words[word_index], word);
                word_index++;
                if (word_index >= MAX_WORDS) {
                    break;
                }
                j = 0;
            }
            if (email[i] == ' ') {
                continue;
            }
            i++;
        }
        i++;
    }

    if (j > 0) {
        word[j] = '\0';
        strcpy(words[word_index], word);
        (*num_words)++;
    }
}

// Function to check if a given word is a C keyword or not
int is_c_keyword(char word[]) {
    char keywords[][10] = {"auto", "break", "case", "char", "const", "continue",
                           "default", "do", "double", "else", "enum", "extern",
                           "float", "for", "goto", "if", "int", "long",
                           "register", "return", "short", "signed", "sizeof",
                           "static", "struct", "switch", "typedef", "union",
                           "unsigned", "void", "volatile", "while"};

    int i;
    for (i = 0; i < 30; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to check if an email is a C spam or not
int is_c_spam(char email[]) {
    int num_words = 0;
    char words[MAX_WORDS][WORD_SIZE];

    extract_words(email, words, &num_words);

    int num_c_keywords = 0;

    for (int i = 0; i < num_words; i++) {
        if (is_c_keyword(words[i])) {
            num_c_keywords++;
        }
    }

    if (num_c_keywords > 3) {
        return 1;
    }

    return 0;
}

// Main function
int main() {
    char email[MAX_EMAIL_SIZE];
    printf("Enter an email to check for C spam: ");
    scanf("%s", email);

    if (is_c_spam(email)) {
        printf("This email is a C spam!\n");
    } else {
        printf("This email is not a C spam.\n");
    }

    return 0;
}