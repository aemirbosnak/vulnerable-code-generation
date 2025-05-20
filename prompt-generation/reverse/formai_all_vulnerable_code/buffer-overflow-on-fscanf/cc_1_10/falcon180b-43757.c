//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void loadWords(char* filename, WordCount words[]) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[j].word, word);
            words[j].count = 0;
            j++;
        }
        words[j - 1].count++;
    }

    fclose(fp);
}

int isSpam(char* email, WordCount words[]) {
    int spamCount = 0;
    char* token = strtok(email, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].word) == 0) {
                spamCount++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("%s not found in word list\n", token);
        }
        token = strtok(NULL, " ");
    }

    if (spamCount >= 3) {
        return 1;
    }

    return 0;
}

int main() {
    WordCount words[MAX_WORDS];
    loadWords("wordlist.txt", words);

    char email[1000];
    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);

    int isSpamEmail = isSpam(email, words);

    if (isSpamEmail) {
        printf("Email is spam\n");
    } else {
        printf("Email is not spam\n");
    }

    return 0;
}