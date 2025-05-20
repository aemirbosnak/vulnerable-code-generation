//FormAI DATASET v1.0 Category: Text Summarizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* summarize(char* text);

int main() {
    
    char text[1000];
    printf("Enter text: ");
    fgets(text, 1000, stdin);

    char* summarized_text = summarize(text);
    printf("%s", summarized_text);
    
    free(summarized_text);
    return 0;
}

char* summarize(char* text) {

    // Remove extra white spaces
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        if ((text[i] == ' ' || text[i] == '\t') && (text[i + 1] == ' ' || text[i + 1] == '\t')) {
            memmove(&text[i], &text[i + 1], length - i);
            length--;
            i--;
        }
    }

    // Convert to lowercase
    length = strlen(text);
    for (int i = 0; i < length; i++) {
        text[i] = tolower(text[i]);
    }

    // Remove punctuations
    char* punctuations = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    length = strlen(text);
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < strlen(punctuations); j++) {
            if (text[i] == punctuations[j]) {
                memmove(&text[i], &text[i + 1], length - i);
                length--;
                i--;
                break;
            }
        }
    }

    // Tokenize the text
    char* tokens[1000];
    int num_tokens = 0;
    tokens[num_tokens++] = strtok(text, " ");

    while (tokens[num_tokens - 1] != NULL) {
        tokens[num_tokens++] = strtok(NULL, " ");
    }

    // Count the frequencies of each word
    char* words[1000];
    int freq[1000] = {0};
    int num_words = 0;

    for (int i = 0; i < num_tokens - 1; i++) {
        int is_new_word = 1;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(tokens[i], words[j]) == 0) {
                freq[j]++;
                is_new_word = 0;
                break;
            }
        }
        if (is_new_word) {
            words[num_words] = malloc(strlen(tokens[i]) + 1);
            strcpy(words[num_words], tokens[i]);
            freq[num_words] = 1;
            num_words++;
        }
    }

    // Find the most frequent words
    int max_freq = 0;
    for (int i = 0; i < num_words; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }

    int num_high_freq_words = 0;
    char* high_freq_words[1000];

    for (int i = 0; i < num_words; i++) {
        if (freq[i] >= max_freq / 2) {
            high_freq_words[num_high_freq_words] = malloc(strlen(words[i]) + 1);
            strcpy(high_freq_words[num_high_freq_words], words[i]);
            num_high_freq_words++;
        }
    }

    // Construct the summary
    char* summary = malloc(1000 * sizeof(char));
    summary[0] = '\0';

    for (int i = 0; i < num_tokens - 1; i++) {
        int is_high_freq_word = 0;
        for (int j = 0; j < num_high_freq_words; j++) {
            if (strcmp(tokens[i], high_freq_words[j]) == 0) {
                is_high_freq_word = 1;
                break;
            }
        }
        if (is_high_freq_word) {
            strcat(summary, tokens[i]);
            strcat(summary, " ");
        }
    }

    // Add punctuation at the end
    length = strlen(summary);
    char last_char = summary[length - 1];
    if (last_char != '.' && last_char != '?' && last_char != '!') {
        strcat(summary, ".");
    }

    // Deallocate memory
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    for (int i = 0; i < num_high_freq_words; i++) {
        free(high_freq_words[i]);
    }

    return summary;
}