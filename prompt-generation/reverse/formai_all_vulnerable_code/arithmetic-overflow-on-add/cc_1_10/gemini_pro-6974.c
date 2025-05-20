//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENT_LEN 1024
#define MAX_SENT_COUNT 100

// Custom sentence struct with pointers to the start and end of the sentence in the text
typedef struct {
    char *start;
    char *end;
} Sentence;

// Global variables for text, sentence array, and sentence count
char text[MAX_SENT_COUNT * MAX_SENT_LEN];
Sentence sentences[MAX_SENT_COUNT];
int sentence_count = 0;

// Function to split the text into sentences
void split_sentences() {
    char *ptr = text;
    while (*ptr != '\0') {
        // Find the start of the sentence
        while (*ptr != '.' && *ptr != '!' && *ptr != '?' && *ptr != '\n') {
            ptr++;
        }
        if (*ptr == '\0') {
            break;
        }

        // Find the end of the sentence
        char *end = ptr;
        while (*end != '.' && *end != '!' && *end != '?' && *end != '\n') {
            end++;
        }

        // Store the sentence in the sentence array
        sentences[sentence_count].start = ptr;
        sentences[sentence_count].end = end;
        sentence_count++;

        // Advance the pointer to the next character after the sentence
        ptr = end + 1;
    }
}

// Function to summarize the text
void summarize(int num_sentences) {
    // Calculate the number of sentences to summarize
    int summary_len = num_sentences * (strlen(text) / sentence_count);

    // Create a buffer for the summary
    char summary[summary_len + 1];

    // Copy the first sentence to the summary
    strncpy(summary, sentences[0].start, sentences[0].end - sentences[0].start);
    summary[sentences[0].end - sentences[0].start] = '\0';

    // Add the remaining sentences to the summary, selecting the most important ones
    int sentence_index = 1;
    while (strlen(summary) < summary_len) {
        // Find the most important sentence
        int max_score = 0;
        int max_score_index = -1;
        for (int i = sentence_index; i < sentence_count; i++) {
            int score = 0;

            // Give more weight to sentences that are longer
            score += sentences[i].end - sentences[i].start;

            // Give more weight to sentences that contain important keywords
            char *keyword = "important";
            if (strstr(sentences[i].start, keyword) != NULL) {
                score += 10;
            }

            if (score > max_score) {
                max_score = score;
                max_score_index = i;
            }
        }

        // Add the most important sentence to the summary
        strcat(summary, " ");
        strncat(summary, sentences[max_score_index].start, sentences[max_score_index].end - sentences[max_score_index].start);
        summary[strlen(summary)] = '\0';

        sentence_index = max_score_index + 1;
    }

    // Print the summary
    printf("%s\n", summary);
}

int main() {
    // Read the text from the user
    printf("Enter the text to summarize:\n");
    fgets(text, sizeof(text), stdin);

    // Split the text into sentences
    split_sentences();

    // Summarize the text
    int num_sentences;
    printf("Enter the number of sentences in the summary:\n");
    scanf("%d", &num_sentences);
    summarize(num_sentences);

    return 0;
}