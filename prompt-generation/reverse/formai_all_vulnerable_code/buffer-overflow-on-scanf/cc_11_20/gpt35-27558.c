//FormAI DATASET v1.0 Category: Text Summarizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 10000
#define MAX_SENTENCES 1000

char* summarize(char* text, int max_sentences);

int main() {
    char text[MAX_STR_LEN];
    int max_sentences;

    printf("Enter the text to be summarized: \n");
    fgets(text, MAX_STR_LEN, stdin);

    printf("Enter the maximum number of sentences for the summary: \n");
    scanf("%d", &max_sentences);

    char* summary = summarize(text, max_sentences);

    printf("Summary: \n%s\n", summary);

    free(summary); // free the dynamically allocated memory

    return 0;
}

/*
    This function takes in a string of text and the maximum number of sentences
    required for the summary. It returns the summarized version of the text as a string.
*/
char* summarize(char* text, int max_sentences) {
    char* sentences[MAX_SENTENCES]; // array to store sentences
    char* token; // used to tokenize the text
    char* sentence; // pointer for each sentence
    int sentence_count = 0; // count of number of sentences in the text
    int i, j;

    // tokenize the text into sentences
    token = strtok(text, ".!?"); // split at punctuation marks
    while(token != NULL) {
        // allocate memory for each sentence and copy it over
        sentence = malloc((strlen(token) + 2) * sizeof(char)); // add space for period and null character
        strcpy(sentence, token);
        // add period to end of sentence if not already present
        if(sentence[strlen(sentence) - 1] != '.') {
            strcat(sentence, ".");
        }
        // store sentence pointer in array
        sentences[sentence_count++] = sentence;

        // get next token
        token = strtok(NULL, ".!?");
    }

    // array to store scores for each sentence
    int* scores = malloc(sentence_count * sizeof(int));

    // initialize score for each sentence to 0
    for(i = 0; i < sentence_count; i++) {
        scores[i] = 0;
    }

    // calculate score for each sentence
    for(i = 0; i < sentence_count; i++) {
        token = strtok(sentences[i], " "); // split sentence into words

        while(token != NULL) {
            // check if word is a keyword
            if(strcmp(token, "the") == 0 || strcmp(token, "a") == 0 || strcmp(token, "an") == 0 ||
               strcmp(token, "is") == 0 || strcmp(token, "are") == 0 || strcmp(token, "was") == 0 ||
               strcmp(token, "were") == 0 || strcmp(token, "has") == 0 || strcmp(token, "have") == 0 ||
               strcmp(token, "had") == 0 || strcmp(token, "and") == 0 || strcmp(token, "or") == 0 ||
               strcmp(token, "not") == 0 || strcmp(token, "but") == 0 || strcmp(token, "if") == 0 ||
               strcmp(token, "when") == 0 || strcmp(token, "where") == 0 || strcmp(token, "who") == 0 ||
               strcmp(token, "what") == 0 || strcmp(token, "why") == 0 || strcmp(token, "how") == 0) {
                scores[i]++;
            }

            // get next token
            token = strtok(NULL, " ");
        }
    }

    // sort sentences based on their scores (in descending order)
    for(i = 0; i < sentence_count - 1; i++) {
        for(j = i + 1; j < sentence_count; j++) {
            if(scores[i] < scores[j]) {
                // swap score values
                int temp_score = scores[i];
                scores[i] = scores[j];
                scores[j] = temp_score;

                // swap sentence pointers in array
                char* temp_sentence = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp_sentence;
            }
        }
    }

    // concatenate top max_sentences sentences into summary string
    char* summary = malloc(MAX_STR_LEN * sizeof(char));
    summary[0] = '\0'; // initialize to empty string
    for(i = 0; i < max_sentences; i++) {
        strcat(summary, sentences[i]);
    }

    // free all dynamically allocated memory
    free(scores); 
    for(i = 0; i < sentence_count; i++) {
        free(sentences[i]);
    }

    return summary;
}