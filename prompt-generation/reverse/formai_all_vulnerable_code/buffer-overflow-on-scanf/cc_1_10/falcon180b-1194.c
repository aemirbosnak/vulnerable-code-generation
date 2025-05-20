//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct word {
    char *word;
    int score;
};

int is_spam(char *email) {
    FILE *f;
    char line[MAX_WORD_LENGTH];
    struct word *words[MAX_WORDS];
    int num_words = 0;

    f = fopen("spam_words.txt", "r");

    if (f == NULL) {
        printf("Error: Could not open spam_words.txt\n");
        return 0;
    }

    while (fgets(line, MAX_WORD_LENGTH, f)!= NULL) {
        if (num_words >= MAX_WORDS) {
            break;
        }
        words[num_words] = malloc(sizeof(struct word));
        words[num_words]->word = strdup(line);
        words[num_words]->score = 0;
        num_words++;
    }

    fclose(f);

    char *token;
    char *email_lower = strdup(email);
    for (int i = 0; i < strlen(email_lower); i++) {
        email_lower[i] = tolower(email_lower[i]);
    }
    token = strtok(email_lower, " ");
    while (token!= NULL) {
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(token, words[i]->word) == 0) {
                words[i]->score++;
                found = 1;
                break;
            }
        }
        if (!found) {
            for (int i = 0; i < num_words; i++) {
                if (words[i]->score == 0) {
                    strcpy(words[i]->word, token);
                    words[i]->score = 1;
                    break;
                }
            }
        }
        token = strtok(NULL, " ");
    }

    int total_score = 0;
    for (int i = 0; i < num_words; i++) {
        total_score += words[i]->score;
    }

    if (total_score >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char email[MAX_WORD_LENGTH];

    printf("Enter an email address: ");
    scanf("%s", email);

    if (is_spam(email)) {
        printf("The email is spam\n");
    } else {
        printf("The email is not spam\n");
    }

    return 0;
}