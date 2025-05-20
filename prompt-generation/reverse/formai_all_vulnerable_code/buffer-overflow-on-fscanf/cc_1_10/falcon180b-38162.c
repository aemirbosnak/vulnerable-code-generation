//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MIN_WORD_LENGTH 3
#define NUM_WORDS 1000

typedef struct word_t {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

Word words[NUM_WORDS];
int num_words = 0;

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void load_words() {
    FILE *file = fopen("words.txt", "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (i == num_words) {
            strcpy(words[num_words].word, word);
            words[num_words].frequency = 1;
            num_words++;
        }
    }
    fclose(file);
    qsort(words, num_words, sizeof(Word), compare_words);
}

int is_spam(char *message) {
    int i, j, k, spam_score = 0;
    char word[MAX_WORD_LENGTH];
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            j = 0;
            while (isalpha(message[i+j])) {
                j++;
            }
            strncpy(word, &message[i], j);
            word[j] = '\0';
            for (k = 0; k < num_words; k++) {
                if (strcmp(word, words[k].word) == 0) {
                    spam_score += words[k].frequency;
                    break;
                }
            }
        }
    }
    return spam_score;
}

int main() {
    load_words();
    char message[1000];
    printf("Enter message: ");
    fgets(message, 1000, stdin);
    int spam_score = is_spam(message);
    if (spam_score >= 5) {
        printf("Message is spam.\n");
    } else {
        printf("Message is not spam.\n");
    }
    return 0;
}