//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MIN_WORD_LEN 3
#define MAX_EMAIL_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int is_spam;
} Word;

typedef struct {
    char email[MAX_EMAIL_LEN];
    int is_spam;
} Email;

void load_words(Word words[], int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words from file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s", words[i].word)!= EOF) {
        i++;
        if (i >= num_words) {
            break;
        }
    }

    fclose(file);
}

int is_spam(Email email, Word words[], int num_words) {
    int total_score = 0;

    char *token = strtok(email.email, "@");
    while (token!= NULL) {
        int word_index = 0;
        while (word_index < num_words) {
            if (strcmp(token, words[word_index].word) == 0) {
                total_score += 10;
                break;
            }
            word_index++;
        }
        token = strtok(NULL, " ");
    }

    return total_score >= 50;
}

int main() {
    Word words[100];
    Email email;

    load_words(words, 100);

    printf("Enter an email address to check for spam:\n");
    scanf("%s", email.email);

    if (is_spam(email, words, 100)) {
        printf("The email is spam.\n");
    } else {
        printf("The email is not spam.\n");
    }

    return 0;
}