//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *ebook = fopen("ebook.txt", "r");
    if (ebook == NULL) {
        printf("Error opening ebook file\n");
        exit(1);
    }

    WordCount word_counts[MAX_WORDS] = {0};
    int num_words = 0;

    char word[MAX_WORD_LENGTH];
    char *token;
    while (fscanf(ebook, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // remove newline character
        token = strtok(word, ",.!?;:");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Too many words in ebook\n");
                    exit(1);
                }
                strcpy(word_counts[num_words].word, token);
                word_counts[num_words].count = 1;
                num_words++;
            }
            token = strtok(NULL, ",.!?;:");
        }
    }

    fclose(ebook);

    printf("Word counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}