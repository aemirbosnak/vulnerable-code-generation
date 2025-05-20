//FormAI DATASET v1.0 Category: Text Summarizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 10000
#define MAX_OUTPUT_SIZE 5000
#define MAX_WORD_COUNT 1000

char* summarize(char* input_text, int summary_length);

int main()
{
    char* input_text = (char*)malloc(MAX_INPUT_SIZE * sizeof(char));
    printf("Enter the text to be summarized (max %d characters):\n", MAX_INPUT_SIZE);
    scanf("%[^\n]s", input_text);

    int summary_length;
    printf("Enter the desired summary length (in number of sentences):\n");
    scanf("%d", &summary_length);

    char* summary = summarize(input_text, summary_length);
    printf("Summary:\n%s\n", summary);

    free(input_text);
    free(summary);

    return 0;
}

char* summarize(char* input_text, int summary_length)
{
    // Splitting text into sentences
    char** sentences = (char**)malloc(MAX_WORD_COUNT * sizeof(char*));
    int sentence_count = 0;
    char* sentence = strtok(input_text, ".!?\n");
    while (sentence != NULL) {
        sentences[sentence_count] = (char*)malloc((strlen(sentence) + 2) * sizeof(char));
        strcpy(sentences[sentence_count], sentence);
        sentence_count++;
        sentence = strtok(NULL, ".!?\n");
    }

    // Counting word occurrences
    char** words = (char**)malloc(MAX_WORD_COUNT * sizeof(char*));
    int* occurrences = (int*)malloc(MAX_WORD_COUNT * sizeof(int));
    int word_count = 0;
    for (int i = 0; i < sentence_count; i++) {
        char* word = strtok(sentences[i], " ,-");
        while (word != NULL) {
            int found = 0;
            for (int j = 0; j < word_count; j++) {
                if (strcmp(words[j], word) == 0) {
                    occurrences[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                words[word_count] = (char*)malloc((strlen(word) + 1) * sizeof(char));
                strcpy(words[word_count], word);
                occurrences[word_count] = 1;
                word_count++;
            }
            word = strtok(NULL, " ,-");
        }
    }

    // Selecting most frequent words
    char** summary_words = (char**)malloc(summary_length * sizeof(char*));
    int* summary_occurrences = (int*)malloc(summary_length * sizeof(int));
    for (int i = 0; i < summary_length; i++) {
        int max_occurrences = 0;
        int max_index = -1;
        for (int j = 0; j < word_count; j++) {
            int included = 0;
            for (int k = 0; k < i; k++) {
                if (strcmp(summary_words[k], words[j]) == 0) {
                    included = 1;
                    break;
                }
            }
            if (!included && occurrences[j] > max_occurrences) {
                max_occurrences = occurrences[j];
                max_index = j;
            }
        }
        if (max_index != -1) {
            summary_words[i] = (char*)malloc((strlen(words[max_index]) + 1) * sizeof(char));
            strcpy(summary_words[i], words[max_index]);
            summary_occurrences[i] = max_occurrences;
        }
    }

    // Generating summary
    char* summary = (char*)malloc(MAX_OUTPUT_SIZE * sizeof(char));
    char* sentence_delimiter = "";
    summary[0] = '\0';
    for (int i = 0; i < sentence_count; i++) {
        for (int j = 0; j < summary_length; j++) {
            if (strstr(sentences[i], summary_words[j]) != NULL) {
                strcat(summary, sentence_delimiter);
                strcat(summary, sentences[i]);
                sentence_delimiter = ". ";
                break;
            }
        }
        if (strlen(summary) >= MAX_OUTPUT_SIZE) {
            strcat(summary, "...");
            break;
        }
    }

    // Cleaning up
    for (int i = 0; i < sentence_count; i++)
        free(sentences[i]);
    for (int i = 0; i < word_count; i++)
        free(words[i]);
    for (int i = 0; i < summary_length; i++)
        free(summary_words[i]);
    free(sentences);
    free(words);
    free(occurrences);
    free(summary_words);
    free(summary_occurrences);

    return summary;
}