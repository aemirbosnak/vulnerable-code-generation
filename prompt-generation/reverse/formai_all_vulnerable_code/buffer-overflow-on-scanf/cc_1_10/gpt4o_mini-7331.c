//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1024
#define MAX_SENTENCES 100
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char sentence[MAX_TEXT_SIZE];
    double score;
} Sentence;

void to_lowercase(char *str) {
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

int split_sentences(const char *text, Sentence sentences[]) {
    int count = 0;
    char *token = strtok((char *)text, ".!?");
    while(token != NULL) {
        strcpy(sentences[count].sentence, token);
        sentences[count].score = 0;
        count++;
        token = strtok(NULL, ".!?");
    }
    return count;
}

void tokenize_sentence(char *sentence, char words[MAX_WORDS][MAX_WORD_LENGTH], int *word_count) {
    char *token = strtok(sentence, " ,;:\"()[]{}");
    *word_count = 0;
    while(token != NULL) {
        strcpy(words[(*word_count)++], token);
        token = strtok(NULL, " ,;:\"()[]{}");
    }
}

double calculate_tf(const char *word, const Sentence *sentences, int sentence_count) {
    int word_count = 0;
    for(int i = 0; i < sentence_count; i++) {
        char temp_sentence[MAX_TEXT_SIZE];
        strcpy(temp_sentence, sentences[i].sentence);
        char *temp_word = strtok(temp_sentence, " ,;:\"()[]{}");
        while(temp_word != NULL) {
            if(strcmp(word, temp_word) == 0) {
                word_count++;
            }
            temp_word = strtok(NULL, " ,;:\"()[]{}");
        }
    }
    return (double)word_count;
}

double calculate_idf(const char *word, const Sentence *sentences, int sentence_count) {
    int doc_count = 0;
    for(int i = 0; i < sentence_count; i++) {
        if(strstr(sentences[i].sentence, word) != NULL) {
            doc_count++;
        }
    }
    return doc_count > 0 ? log((double)sentence_count / (doc_count + 1)) : 0;
}

void calculate_sentence_scores(Sentence *sentences, int sentence_count) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    for(int i = 0; i < sentence_count; i++) {
        int word_count;
        tokenize_sentence(sentences[i].sentence, words, &word_count);
        for(int j = 0; j < word_count; j++) {
            double tf = calculate_tf(words[j], sentences, sentence_count);
            double idf = calculate_idf(words[j], sentences, sentence_count);
            sentences[i].score += tf * idf;
        }
    }
}

int compare_sentences(const void *a, const void *b) {
    Sentence *sentenceA = (Sentence *)a;
    Sentence *sentenceB = (Sentence *)b;
    return (sentenceB->score > sentenceA->score) - (sentenceB->score < sentenceA->score);
}

void summarize_text(const char *text, int n) {
    Sentence sentences[MAX_SENTENCES];
    int sentence_count = split_sentences(text, sentences);

    calculate_sentence_scores(sentences, sentence_count);
    qsort(sentences, sentence_count, sizeof(Sentence), compare_sentences);

    printf("Summary:\n");
    for(int i = 0; i < n && i < sentence_count; i++) {
        printf("%s.\n", sentences[i].sentence);
    }
}

int main() {
    char text[MAX_TEXT_SIZE];
    int n;

    printf("Enter the text to be summarized (end with EOF - Ctrl+D):\n");
    fread(text, 1, MAX_TEXT_SIZE, stdin);

    printf("Enter number of sentences for summary: ");
    scanf("%d", &n);

    summarize_text(text, n);

    return 0;
}