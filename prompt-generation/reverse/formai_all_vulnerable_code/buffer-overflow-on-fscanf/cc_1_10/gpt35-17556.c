//FormAI DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 1000000 //maximum input text size
#define MAX_SUMMARY_LENGTH 500 //maximum summary length
#define MAX_SENTENCE_LENGTH 200 //maximum sentence length
#define MAX_SENTENCES 10000 //maximum number of sentences in input text
#define STOPWORDS_NUM 319 //number of stopwords in the dictionary file

//global variables
char input_text[MAX_TEXT_SIZE];
char output_summary[MAX_SUMMARY_LENGTH];
char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
char stopwords[STOPWORDS_NUM][20];
int sentence_scores[MAX_SENTENCES];
int sentence_lengths[MAX_SENTENCES];
int stopwords_found[MAX_SENTENCES];

void read_input_text() {
    printf("Enter the text you want to summarize (max. %d characters):\n", MAX_TEXT_SIZE);
    fgets(input_text, MAX_TEXT_SIZE, stdin);
}

void read_stopwords() {
    FILE *stopwords_file = fopen("stopwords.txt", "r");
    if (stopwords_file == NULL) {
        printf("Error: cannot open stopwords file.\n");
        exit(1);
    }
    int i = 0;
    char word[20];
    while (fscanf(stopwords_file, "%s", word) != EOF) {
        strcpy(stopwords[i], word);
        i++;
    }
    fclose(stopwords_file);
}

void extract_sentences() {
    int i, j, k;
    i = j = k = 0;
    while (input_text[i] != '\0') {
        if ((input_text[i] == '.') || (input_text[i] == '!') || (input_text[i] == '?')) {
            sentences[j][k] = input_text[i];
            sentences[j][k + 1] = '\0';
            j++;
            k = 0;
            i++;
            while (input_text[i] == ' ') {
                i++;
            }
        }
        else {
            sentences[j][k] = input_text[i];
            k++;
            i++;
        }
    }
}

void remove_stopwords() {
    int i, j, k;
    for (i = 0; i < STOPWORDS_NUM; i++) {
        for (j = 0; j < MAX_SENTENCES; j++) {
            if (strlen(sentences[j]) == 0) {
                break;
            }
            k = 0;
            stopwords_found[j] = 0;
            while (sentences[j][k] != '\0') {
                if (sentences[j][k] == ' ') {
                    char word[20];
                    strncpy(word, sentences[j] + k - strlen(stopwords[i]), strlen(stopwords[i]));
                    word[strlen(stopwords[i])] = '\0';
                    if (strcmp(word, stopwords[i]) == 0) {
                        stopwords_found[j] = 1;
                        break;
                    }
                }
                k++;
            }
        }
    }
    for (i = 0; i < MAX_SENTENCES; i++) {
        if (strlen(sentences[i]) == 0) {
            break;
        }
        if (stopwords_found[i] == 0) {
            strcat(output_summary, sentences[i]);
            strcat(output_summary, " ");
        }
    }
}

void score_sentences() {
    int i, j, k;
    for (i = 0; i < MAX_SENTENCES; i++) {
        if (strlen(sentences[i]) == 0) {
            break;
        }
        k = 0;
        sentence_scores[i] = 0;
        sentence_lengths[i] = strlen(sentences[i]);
        while (sentences[i][k] != '\0') {
            if (sentences[i][k] == ' ') {
                char word[20];
                strncpy(word, sentences[i] + k - 4, 4);
                word[4] = '\0';
                if (strcmp(word, "not ") == 0) {
                    sentence_scores[i] -= 2;
                }
                else {
                    strncpy(word, sentences[i] + k - 3, 3);
                    word[3] = '\0';
                    if (strcmp(word, "no ") == 0) {
                        sentence_scores[i] -= 1;
                    }
                }
                strncpy(word, sentences[i] + k - 2, 2);
                word[2] = '\0';
                if (strcmp(word, "or") == 0) {
                    sentence_scores[i] += 1;
                }
                else if (strcmp(word, "in") == 0) {
                    sentence_scores[i] += 1;
                }
                else if (strcmp(word, "is") == 0) {
                    sentence_scores[i] += 1;
                }
                else if (strcmp(word, "at") == 0) {
                    sentence_scores[i] += 1;
                }
                else if (strcmp(word, "of") == 0) {
                    sentence_scores[i] += 2;
                }
            }
            k++;
        }
    }
}

void sort_sentences() {
    int i, j, tmp;
    char tmp_sentence[MAX_SENTENCE_LENGTH];
    for (i = 0; i < MAX_SENTENCES - 1; i++) {
        for (j = i + 1; j < MAX_SENTENCES; j++) {
            if (sentence_scores[j] > sentence_scores[i]) {
                tmp = sentence_scores[i];
                sentence_scores[i] = sentence_scores[j];
                sentence_scores[j] = tmp;
                strcpy(tmp_sentence, sentences[i]);
                strcpy(sentences[i], sentences[j]);
                strcpy(sentences[j], tmp_sentence);
                tmp = sentence_lengths[i];
                sentence_lengths[i] = sentence_lengths[j];
                sentence_lengths[j] = tmp;
            }
        }
    }
}

void generate_summary() {
    int i, summary_length;
    summary_length = 0;
    for (i = 0; i < MAX_SENTENCES; i++) {
        if (summary_length + sentence_lengths[i] + 1 <= MAX_SUMMARY_LENGTH) {
            strcat(output_summary, sentences[i]);
            strcat(output_summary, " ");
            summary_length += sentence_lengths[i] + 1;
        }
        else {
            break;
        }
    }
}

void print_summary() {
    printf("Summary:\n%s\n", output_summary);
}

int main() {
    read_input_text();
    read_stopwords();
    extract_sentences();
    remove_stopwords();
    score_sentences();
    sort_sentences();
    generate_summary();
    print_summary();
    return 0;
}