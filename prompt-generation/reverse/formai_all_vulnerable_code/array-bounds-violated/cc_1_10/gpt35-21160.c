//FormAI DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOC_LENGTH 1000
#define MAX_SENTENCES 50
#define MAX_SUMMARY_LENGTH 200

char *document[MAX_SENTENCES];
int *sentence_scores;

int count_sentences(char *doc) {
    int count = 0;
    char *ptr = doc;

    while (*ptr) {
        if (*ptr == '.' || *ptr == '?' || *ptr == '!') {
            count++;
        }
        ptr++;
    }

    return count;
}

void parse_document(char *doc, int num_sentences) {
    char *ptr = doc;
    int sentence_index = 0;

    while (*ptr) {
        document[sentence_index] = ptr;
        sentence_index++;
        ptr++;

        while (*ptr != '.' && *ptr != '?' && *ptr != '!' && *ptr) {
            ptr++;
        }
        if (!*ptr) {
            break;
        }
        *ptr = '\0';
        ptr++;
    }
}

int calculate_sentence_score(char *sentence) {
    // Implement your custom logic here
    return strlen(sentence);
}

void find_sentence_scores(int num_sentences) {
    sentence_scores = malloc(num_sentences * sizeof(int));

    for (int i = 0; i < num_sentences; i++) {
        sentence_scores[i] = calculate_sentence_score(document[i]);
    }
}

void print_summary(int summary_length, int num_sentences) {
    int summary_scores[num_sentences];

    for (int i = 0; i < num_sentences; i++) {
        summary_scores[i] = sentence_scores[i];
    }

    while (summary_length > 0) {
        int max_score_index = 0;
        int max_score = -1;

        for (int i = 0; i < num_sentences; i++) {
            if (summary_scores[i] > max_score) {
                max_score_index = i;
                max_score = summary_scores[i];
            }
        }

        if (max_score_index == -1) {
            break;
        }

        printf("%s. ", document[max_score_index]);

        summary_scores[max_score_index] = -1;
        summary_length--;
    }

    printf("\n");
}

int main() {
    char document_text[MAX_DOC_LENGTH];
    int num_sentences;
    
    printf("Enter the document: ");
    fgets(document_text, MAX_DOC_LENGTH, stdin);

    num_sentences = count_sentences(document_text);

    parse_document(document_text, num_sentences);

    find_sentence_scores(num_sentences);

    print_summary(MAX_SUMMARY_LENGTH, num_sentences);

    free(sentence_scores);

    return 0;
}