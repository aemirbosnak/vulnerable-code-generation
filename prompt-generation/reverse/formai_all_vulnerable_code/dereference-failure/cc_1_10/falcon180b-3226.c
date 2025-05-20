//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100
#define MAX_NUMBER_LENGTH 20
#define MAX_DATE_LENGTH 20

// Function prototypes
char *get_word(char *sentence);
int is_number(char *str);
int is_date(char *str);
void print_date(char *date);

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];
    char number[MAX_NUMBER_LENGTH];
    char date[MAX_DATE_LENGTH];

    // Prompt user for input
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Get first word
    char *ptr = strtok(sentence, " ");
    if (ptr == NULL) {
        printf("Invalid input.\n");
        return 1;
    }
    strcpy(word, ptr);

    // Check if word is a number
    if (is_number(word)) {
        printf("The input is a number.\n");
    } else if (is_date(word)) {
        printf("The input is a date.\n");
        strcpy(date, word);
        print_date(date);
    } else {
        printf("The input is a word.\n");
    }

    return 0;
}

char *get_word(char *sentence) {
    char *ptr = strtok(sentence, " ");
    if (ptr == NULL) {
        return NULL;
    }
    return ptr;
}

int is_number(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int is_date(char *str) {
    int len = strlen(str);
    if (len!= 10) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if ((i == 2 || i == 5) && str[i]!= '-') {
            return 0;
        }
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void print_date(char *date) {
    printf("The date is: ");
    for (int i = 0; i < strlen(date); i++) {
        if (date[i] == '-') {
            printf("/");
        } else {
            printf("%c", date[i]);
        }
    }
    printf("\n");
}