//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to summarize the text.
char *summarize(char *text, int num_sentences) {
    // Tokenize the text into sentences.
    char **sentences = (char **)malloc(sizeof(char *) * 100);
    int num_toks = 0;
    char *token = strtok(text, ".");
    while (token != NULL) {
        sentences[num_toks++] = token;
        token = strtok(NULL, ".");
    }

    // Calculate the TF-IDF for each sentence.
    double *tf_idf = (double *)malloc(sizeof(double) * num_toks);
    for (int i = 0; i < num_toks; i++) {
        // Calculate the term frequency.
        int tf = 0;
        for (int j = 0; j < num_toks; j++) {
            if (strcmp(sentences[i], sentences[j]) == 0) {
                tf++;
            }
        }

        // Calculate the inverse document frequency.
        int df = 0;
        for (int j = 0; j < num_toks; j++) {
            if (strstr(text, sentences[j]) != NULL) {
                df++;
            }
        }
        double idf = log10((double)num_toks / df);

        // Calculate the TF-IDF.
        tf_idf[i] = tf * idf;
    }

    // Sort the sentences by TF-IDF.
    for (int i = 0; i < num_toks; i++) {
        for (int j = i + 1; j < num_toks; j++) {
            if (tf_idf[i] < tf_idf[j]) {
                // Swap the sentences.
                char *temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;

                // Swap the TF-IDF values.
                double temp2 = tf_idf[i];
                tf_idf[i] = tf_idf[j];
                tf_idf[j] = temp2;
            }
        }
    }

    // Generate the summary.
    char *summary = (char *)malloc(sizeof(char) * 1000);
    int num_summary_sentences = 0;
    for (int i = 0; i < num_toks; i++) {
        if (num_summary_sentences == num_sentences) {
            break;
        }
        strcat(summary, sentences[i]);
        strcat(summary, ". ");
        num_summary_sentences++;
    }

    // Free the allocated memory.
    free(sentences);
    free(tf_idf);

    // Return the summary.
    return summary;
}

// Main function.
int main() {
    // Get the text from the user.
    char text[1000];
    printf("Enter the text to summarize: ");
    gets(text);

    // Get the number of sentences to summarize the text to.
    int num_sentences;
    printf("Enter the number of sentences to summarize the text to: ");
    scanf("%d", &num_sentences);

    // Summarize the text.
    char *summary = summarize(text, num_sentences);

    // Print the summary.
    printf("Summary: %s\n", summary);

    // Free the allocated memory.
    free(summary);

    return 0;
}