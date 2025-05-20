//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORD_LEN 100
#define MAX_SENTENCES 100
#define MAX_WORDS 1000
#define MAX_OUTPUT_LEN 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

typedef struct {
    char sentence[MAX_SENTENCES][MAX_WORD_LEN];
    int num_sentences;
} Sentence;

typedef struct {
    Word *words;
    int num_words;
    Sentence *sentences;
    int num_sentences;
} Article;

void print_article(Article *article) {
    int i, j, k;
    for (i = 0; i < article->num_sentences; i++) {
        for (j = 0; j < article->sentences[i].num_sentences; j++) {
            printf("%s\n", article->sentences[i].sentence[j]);
        }
    }
}

void remove_stop_words(Article *article) {
    int i, j, k;
    for (i = 0; i < article->num_sentences; i++) {
        for (j = 0; j < article->sentences[i].num_sentences; j++) {
            for (k = 0; k < article->sentences[i].num_sentences; k++) {
                if (strstr(article->sentences[i].sentence[j], "stop_words.txt")) {
                    strcpy(article->sentences[i].sentence[j], "");
                }
            }
        }
    }
}

void remove_duplicates(Article *article) {
    int i, j, k;
    for (i = 0; i < article->num_sentences; i++) {
        for (j = 0; j < article->sentences[i].num_sentences; j++) {
            for (k = 0; k < article->sentences[i].num_sentences; k++) {
                if (strcmp(article->sentences[i].sentence[j], article->sentences[i].sentence[k]) == 0) {
                    strcpy(article->sentences[i].sentence[j], "");
                }
            }
        }
    }
}

void remove_rare_words(Article *article) {
    int i, j, k;
    for (i = 0; i < article->num_sentences; i++) {
        for (j = 0; j < article->sentences[i].num_sentences; j++) {
            for (k = 0; k < article->sentences[i].num_sentences; k++) {
                if (article->sentences[i].sentence[j][0] == '\0') {
                    continue;
                }
                if (strstr(article->sentences[i].sentence[j], "stop_words.txt")) {
                    continue;
                }
                if (article->words[i].count < 10) {
                    strcpy(article->sentences[i].sentence[j], "");
                }
            }
        }
    }
}

int main() {
    Article article;
    char filename[MAX_WORD_LEN];
    FILE *file;

    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    fscanf(file, "%d %d\n", &article.num_words, &article.num_sentences);

    article.words = malloc(article.num_words * sizeof(Word));
    article.sentences = malloc(article.num_sentences * sizeof(Sentence));

    for (int i = 0; i < article.num_words; i++) {
        fscanf(file, "%s %d\n", article.words[i].word, &article.words[i].count);
    }

    for (int i = 0; i < article.num_sentences; i++) {
        fscanf(file, "%s\n", article.sentences[i].sentence);
    }

    fclose(file);

    remove_stop_words(&article);
    remove_duplicates(&article);
    remove_rare_words(&article);

    print_article(&article);

    return 0;
}