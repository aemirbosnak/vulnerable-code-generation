#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char *sentence;
    double tf_idf;
} Sentence;

int compare(const void *a, const void *b) {
    return ((Sentence *)b)->tf_idf - ((Sentence *)a)->tf_idf;
}

void summarize_text(char *input, int n) {
    char *sentences[MAX_SENTENCES];
    int num_sentences = 0;
    char *token = strtok(input, ". ");
    while (token != NULL && num_sentences < MAX_SENTENCES) {
        sentences[num_sentences] = strdup(token);
        num_sentences++;
        token = strtok(NULL, ". ");
    }

    Sentence summary[MAX_SENTENCES];
    for (int i = 0; i < num_sentences; i++) {
        summary[i].sentence = sentences[i];
        // Calculate TF-IDF here
        // For simplicity, assume all sentences have equal importance
        summary[i].tf_idf = 1.0;
    }

    qsort(summary, num_sentences, sizeof(Sentence), compare);

    printf("Summary:\n");
    for (int i = 0; i < n && i < num_sentences; i++) {
        printf("%s\n", summary[i].sentence);
    }

    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }
}

int main() {
    char input[10000];
    int n;

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Enter number of sentences in summary: ");
    scanf("%d", &n);
    getchar(); // Consume newline character

    summarize_text(input, n);

    return 0;
}
