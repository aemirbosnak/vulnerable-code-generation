//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_SENTENCE_LENGTH 200
#define MAX_SENTENCES 50

// Structure to hold a sentence and its corresponding importance
typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    float importance; // Importance score for summarization
} Sentence;

// Function declarations
void read_text(char *text, int length);
int tokenize_sentences(char *text, Sentence *sentences);
void calculate_importance(Sentence *sentences, int count);
void print_summary(Sentence *sentences, int count, int summary_length);

int main() {
    char text[MAX_TEXT_LENGTH];
    Sentence sentences[MAX_SENTENCES];
    int sentence_count;
    int summary_length;

    printf("Enter the text to summarize (up to 1000 characters):\n");
    read_text(text, MAX_TEXT_LENGTH);
    
    sentence_count = tokenize_sentences(text, sentences);
    
    calculate_importance(sentences, sentence_count);
    
    printf("Enter the number of sentences to include in the summary:\n");
    scanf("%d", &summary_length);
    
    print_summary(sentences, sentence_count, summary_length);

    return 0;
}

// Function to read the text input
void read_text(char *text, int length) {
    fgets(text, length, stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character if present
}

// Function to tokenize sentences from the input text
int tokenize_sentences(char *text, Sentence *sentences) {
    const char *delimiter = ".!?"; // Sentence delimiters
    char *token;
    int count = 0;

    token = strtok(text, delimiter);
    while (token != NULL && count < MAX_SENTENCES) {
        strcpy(sentences[count].sentence, token);
        sentences[count].importance = 0.0; // Initialize importance
        count++;
        token = strtok(NULL, delimiter);
    }
    return count;
}

// Function to calculate the importance of each sentence
void calculate_importance(Sentence *sentences, int count) {
    // Naive calculation based on the length of sentences for demonstration purposes
    for (int i = 0; i < count; i++) {
        sentences[i].importance = (float)strlen(sentences[i].sentence) / 10; // Simple importance metric
    }
}

// Function to print the summary based on importance
void print_summary(Sentence *sentences, int count, int summary_length) {
    // Sort sentences based on importance using a basic bubble sort for demonstration
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (sentences[j].importance < sentences[j + 1].importance) {
                Sentence temp = sentences[j];
                sentences[j] = sentences[j + 1];
                sentences[j + 1] = temp;
            }
        }
    }

    printf("\nSummary:\n");
    for (int i = 0; i < summary_length && i < count; i++) {
        printf("%s. ", sentences[i].sentence);
    }
    printf("\n");
}