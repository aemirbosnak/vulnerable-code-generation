//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 50
#define MAX_DICTIONARY_SIZE 1000

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} Dictionary;

int is_spam(char* email_text) {
    FILE* dictionary_file = fopen("dictionary.txt", "r");
    Dictionary dictionary[MAX_DICTIONARY_SIZE];
    int dictionary_size = 0;

    if (dictionary_file == NULL) {
        printf("Error: unable to open dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_SIZE];
    while (fscanf(dictionary_file, "%s", line)!= EOF) {
        strcpy(dictionary[dictionary_size].word, line);
        dictionary[dictionary_size].count = 0;
        dictionary_size++;
    }

    fclose(dictionary_file);

    int spam_count = 0;
    char word[MAX_WORD_SIZE];
    char* token = strtok(email_text, " ");

    while (token!= NULL) {
        if (strlen(token) > MAX_WORD_SIZE) {
            printf("Error: word too long.\n");
            exit(1);
        }

        strcpy(word, token);
        int i;
        for (i = 0; i < dictionary_size; i++) {
            if (strcmp(word, dictionary[i].word) == 0) {
                dictionary[i].count++;
                spam_count++;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    if (spam_count >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char email_text[1000];
    printf("Enter email text: ");
    fgets(email_text, 1000, stdin);

    int is_spam_result = is_spam(email_text);

    if (is_spam_result == 1) {
        printf("Email is spam.\n");
    } else {
        printf("Email is not spam.\n");
    }

    return 0;
}