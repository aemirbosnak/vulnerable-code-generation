//FormAI DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_CHARS 10000
#define MAX_SUMMARY_CHARS 1000

void summarize(char *input, char *output);

int main() {
    char input[MAX_INPUT_CHARS];
    char summary[MAX_SUMMARY_CHARS];

    printf("Enter your text:\n");
    fgets(input, MAX_INPUT_CHARS, stdin);

    summarize(input, summary);

    printf("\nSummary:\n%s\n", summary);

    return 0;
}

void summarize(char *input, char *output) {
    int input_length = strlen(input);
    int num_sentences = 0;
    int num_summary_chars = 0;

    // Count the number of sentences in the input
    for(int i = 0; i < input_length; i++) {
        if(input[i] == '.' || input[i] == '!' || input[i] == '?') {
            num_sentences++;
        }
    }

    // Divide the input into sentences and choose a representative phrase from each sentence
    char sentences[num_sentences][MAX_INPUT_CHARS];
    char phrases[num_sentences][50];
    int sentence_lengths[num_sentences];
    int phrase_lengths[num_sentences];

    int sentence_index = 0;
    int phrase_index = 0;
    int start_index = 0;
    for(int i = 0; i < input_length; i++) {
        if(input[i] == '.' || input[i] == '!' || input[i] == '?') {
            // Add the current sentence to the sentences array
            int end_index = i + 1;
            int length = end_index - start_index;
            memcpy(sentences[sentence_index], &input[start_index], length);
            sentence_lengths[sentence_index] = length;

            // Choose a representative phrase from the sentence
            int phrase_start_index = -1;
            int phrase_end_index = -1;
            for(int j = start_index; j < end_index; j++) {
                if((input[j] >= 'A' && input[j] <= 'Z') || (input[j] >= 'a' && input[j] <= 'z')) {
                    if(phrase_start_index == -1) {
                        phrase_start_index = j;
                    }
                    phrase_end_index = j + 1;
                }
                else if(phrase_start_index != -1) {
                    break;
                }
            }
            memcpy(phrases[phrase_index], &input[phrase_start_index], phrase_end_index - phrase_start_index);
            phrase_lengths[phrase_index] = phrase_end_index - phrase_start_index;

            // Update indices for the next sentence
            start_index = i + 1;
            sentence_index++;
            phrase_index++;
        }
    }

    // Construct the summary by choosing the most representative phrase from each sentence
    int summary_index = 0;
    int used_phrases[num_sentences];
    for(int i = 0; i < num_sentences; i++) {
        used_phrases[i] = 0;
    }

    while(num_summary_chars < MAX_SUMMARY_CHARS && summary_index < num_sentences) {
        int max_score = 0;
        int max_score_index = -1;
        for(int i = 0; i < num_sentences; i++) {
            if(!used_phrases[i]) {
                int score = 0;
                for(int j = 0; j < num_sentences; j++) {
                    if(!used_phrases[j] && i != j) {
                        for(int k = 0; k < phrase_lengths[i]; k++) {
                            if(strstr(phrases[j], &phrases[i][k])) {
                                score++;
                            }
                        }
                    }
                }
                if(score > max_score) {
                    max_score = score;
                    max_score_index = i;
                }
            }
        }

        memcpy(&output[num_summary_chars], sentences[max_score_index], sentence_lengths[max_score_index]);
        num_summary_chars += sentence_lengths[max_score_index];
        used_phrases[max_score_index] = 1;
        summary_index++;
    }

    output[num_summary_chars] = '\0';
}