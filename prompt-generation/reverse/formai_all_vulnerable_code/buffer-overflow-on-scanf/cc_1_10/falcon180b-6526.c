//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int is_spam(char* email) {
    int spam_words_count = 0;
    FILE* spam_words_file = fopen("spam_words.txt", "r");
    if (spam_words_file == NULL) {
        printf("Error: Unable to open spam_words.txt file.\n");
        return -1;
    }
    char spam_word[MAX_WORD_LEN];
    while (fscanf(spam_words_file, "%s", spam_word)!= EOF) {
        int i;
        for (i = 0; i < strlen(email); i++) {
            if (tolower(email[i]) == tolower(spam_word[0])) {
                if (strlen(spam_word) > 1) {
                    if (strncmp(email + i, spam_word + 1, strlen(spam_word) - 1) == 0) {
                        spam_words_count++;
                        break;
                    }
                } else {
                    spam_words_count++;
                    break;
                }
            }
        }
    }
    fclose(spam_words_file);
    return spam_words_count;
}

int main() {
    int i, j, num_emails, num_spam_emails;
    char** emails = NULL;
    char* email;
    printf("Enter the number of emails: ");
    scanf("%d", &num_emails);
    emails = (char**)malloc(num_emails * sizeof(char*));
    for (i = 0; i < num_emails; i++) {
        emails[i] = (char*)malloc(MAX_WORD_LEN * sizeof(char));
        printf("Enter email %d: ", i+1);
        scanf("%s", emails[i]);
    }
    num_spam_emails = 0;
    for (i = 0; i < num_emails; i++) {
        if (is_spam(emails[i]) > 0) {
            num_spam_emails++;
        }
    }
    printf("Number of spam emails: %d\n", num_spam_emails);
    for (i = 0; i < num_emails; i++) {
        free(emails[i]);
    }
    free(emails);
    return 0;
}