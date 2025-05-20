//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define TRUE 1
#define FALSE 0

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int position;
} Word;

int compare(const void *a, const void *b) {
    Word *word1 = (Word *) a;
    Word *word2 = (Word *) b;
    return strcmp(word1->word, word2->word);
}

int search(char *text, char *keyword) {
    int length_text = strlen(text);
    int length_keyword = strlen(keyword);
    Word *words = (Word *) malloc(MAX_WORDS * sizeof(Word));
    int num_words = 0;
    char *token = strtok(text, " ");
    while (token!= NULL && num_words < MAX_WORDS) {
        if (strlen(token) > MAX_WORD_LENGTH) {
            token = strtok(NULL, " ");
            continue;
        }
        strcpy(words[num_words].word, token);
        words[num_words].length = strlen(token);
        words[num_words].position = 0;
        num_words++;
        token = strtok(NULL, " ");
    }
    qsort(words, num_words, sizeof(Word), compare);
    int i = 0;
    while (i < num_words) {
        int j = 0;
        while (j < length_keyword && isalnum(keyword[j])) {
            if (tolower(keyword[j])!= tolower(words[i].word[j])) {
                break;
            }
            j++;
        }
        if (j == length_keyword) {
            return TRUE;
        }
        i++;
    }
    return FALSE;
}

int main() {
    char text[MAX_WORD_LENGTH * 1000];
    char keyword[MAX_WORD_LENGTH];
    printf("Enter a text:\n");
    fgets(text, sizeof(text), stdin);
    printf("Enter a keyword:\n");
    fgets(keyword, sizeof(keyword), stdin);
    int result = search(text, keyword);
    if (result == TRUE) {
        printf("Keyword found!\n");
    } else {
        printf("Keyword not found.\n");
    }
    return 0;
}