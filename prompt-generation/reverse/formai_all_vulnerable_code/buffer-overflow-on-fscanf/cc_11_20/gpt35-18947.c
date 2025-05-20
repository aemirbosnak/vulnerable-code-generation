//FormAI DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_SPAM_WORDS 50
#define MAX_WORD_LENGTH 50

char spam_words[MAX_SPAM_WORDS][MAX_WORD_LENGTH] = {"buy", "discount", "win", "free", "viagra", "loan", "cash", "offer", "limited", "urgent"};
int spam_counters[MAX_SPAM_WORDS];

int main() {
    char emails[MAX_EMAILS][MAX_WORD_LENGTH];
    int email_index = 0;
    char word[MAX_WORD_LENGTH];
    int word_index = 0;
    int is_spam = 0;

    // Read emails from file
    FILE *file;
    file = fopen("emails.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    while (fscanf(file, "%s", emails[email_index]) != EOF) {
        email_index++;
    }
    fclose(file);

    // Check each email for spam words
    for (int i = 0; i < email_index; i++) {
        printf("Email %d: %s\n", i+1, emails[i]);

        word_index = 0;
        is_spam = 0;
        for (int j = 0; j < strlen(emails[i]); j++) {
            if (emails[i][j] == ' ' || emails[i][j] == '\n' || emails[i][j] == '\r' || emails[i][j] == '\t') {
                // End of word
                word[word_index] = '\0';
                for (int k = 0; k < MAX_SPAM_WORDS; k++) {
                    if (strcmp(word, spam_words[k]) == 0) {
                        spam_counters[k]++;
                        is_spam = 1;
                    }
                }
                word_index = 0;
            } else {
                word[word_index] = emails[i][j];
                word_index++;
            }
        }

        if (is_spam) {
            printf("This email is considered spam.\n");
        } else {
            printf("This email is not considered spam.\n");
        }
    }

    // Print spam word counters
    printf("\nSpam word counters:\n");
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        printf("%s: %d\n", spam_words[i], spam_counters[i]);
    }

    return 0;
}