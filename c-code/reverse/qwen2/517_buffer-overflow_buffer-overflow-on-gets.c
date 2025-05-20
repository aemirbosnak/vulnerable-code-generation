#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 50

typedef struct {
    char *word;
    int count;
} Word;

typedef struct {
    char *sentence;
    double tfidf;
} Sentence;

int main() {
    char text[MAX_SENTENCES][MAX_WORDS];
    int num_sentences = 0;

    printf("Enter text (type 'exit' to finish):\n");
    while (num_sentences < MAX_SENTENCES) {
        fgets(text[num_sentences], MAX_WORDS, stdin);
        if (strcmp(text[num_sentences], "exit\n") == 0) break;
        num_sentences++;
    }

    // Tokenize and calculate TF-IDF here...

    return 0;
}
