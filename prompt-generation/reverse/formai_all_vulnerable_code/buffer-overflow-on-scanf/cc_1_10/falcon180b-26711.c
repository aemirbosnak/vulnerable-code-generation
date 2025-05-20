//Falcon-180B DATASET v1.0 Category: Text processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void process_text(char *text, int word_count, WordCount *word_counts) {
    int i = 0, j = 0, k = 0;
    char word[MAX_WORD_LEN];
    while (i < strlen(text)) {
        if (isalpha(text[i])) {
            word[j++] = tolower(text[i]);
        } else {
            if (j > 0) {
                word[j] = '\0';
                k = 0;
                while (k < word_count) {
                    if (strcmp(word, word_counts[k].word) == 0) {
                        word_counts[k].count++;
                        break;
                    }
                    k++;
                }
                if (k == word_count) {
                    strcpy(word_counts[word_count - 1].word, word);
                    word_counts[word_count - 1].count = 1;
                    word_count++;
                }
                j = 0;
            }
        }
        i++;
    }
}

void print_word_counts(WordCount *word_counts, int word_count) {
    int i;
    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char text[1000];
    int word_count = 0;
    WordCount word_counts[100];
    printf("Enter a text: ");
    scanf("%[^\n]", text);
    process_text(text, word_count, word_counts);
    print_word_counts(word_counts, word_count);
    return 0;
}