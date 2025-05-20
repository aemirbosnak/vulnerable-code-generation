//FormAI DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 200

// Function prototypes
void summarize(char *text);

// Main function
int main()
{
    char text[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int i = 0;
    printf("Enter up to %d sentences. Enter a blank line to terminate.\n", MAX_SENTENCES);
    while (i < MAX_SENTENCES) {
        fgets(text[i], MAX_SENTENCE_LENGTH, stdin);
        if (strcmp(text[i], "\n") == 0) {
            break;
        }
        i++;
    }
    summarize(*text);
    return 0;
}

// Function to summarize text
void summarize(char *text)
{
    // Split the text into sentences
    char *sentence[MAX_SENTENCES];
    int num_sentences = 0;
    char *word = strtok(text, ".,;");
    while (word != NULL) {
        sentence[num_sentences] = word;
        num_sentences++;
        word = strtok(NULL, ".,;");
    }

    // Count the number of words in each sentence
    int num_words[num_sentences];
    for (int i = 0; i < num_sentences; i++) {
        int count = 0;
        char *s = sentence[i];
        while (*s != '\0') {
            if (*s == ' ') {
                count++;
            }
            s++;
        }
        num_words[i] = count + 1;
    }

    // Calculate the weight of each sentence
    float weight[num_sentences];
    for (int i = 0; i < num_sentences; i++) {
        int sum = 0;
        char *s = sentence[i];
        while (*s != '\0') {
            if (*s != ' ' && *s != '\n') {
                sum += *s;
            }
            s++;
        }
        weight[i] = (float) sum / num_words[i];
    }

    // Find the highest weighted sentence
    int index = 0;
    float max_weight = weight[0];
    for (int i = 1; i < num_sentences; i++) {
        if (weight[i] > max_weight) {
            max_weight = weight[i];
            index = i;
        }
    }

    // Print the summary
    printf("\nSummary:\n%s\n", sentence[index]);
}