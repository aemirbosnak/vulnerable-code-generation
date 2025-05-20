//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: systematic
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORD_SIZE 20
#define MAX_WORDS 1000

struct word_node {
    char word[MAX_WORD_SIZE];
    int count;
};

void read_words(struct word_node *words) {
    FILE *file;
    char ch;
    int i = 0;
    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[strlen(words[i].word)] = tolower(ch);
            words[i].word[strlen(words[i].word) + 1] = '\0';
            i++;
        }
    }
    fclose(file);
}

void count_words(struct word_node *words, char *text) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            for (j = 0; j < i; j++) {
                if (strcmp(words[j].word, text) == 0) {
                    words[j].count++;
                    break;
                }
            }
        }
    }
}

void print_words(struct word_node *words) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    struct word_node words[MAX_WORDS];
    char text[1000];
    printf("Enter text to check:\n");
    scanf("%[^\n]", text);
    read_words(words);
    count_words(words, text);
    print_words(words);
    return 0;
}