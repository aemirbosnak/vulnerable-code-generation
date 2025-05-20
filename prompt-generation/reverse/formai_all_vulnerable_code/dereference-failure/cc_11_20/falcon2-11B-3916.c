//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Read in the input text file
    FILE *in_file = fopen("input.txt", "r");
    if (in_file == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }
    
    // Read in the input text
    char *text = malloc(sizeof(char) * 100000);
    int num_chars = fread(text, sizeof(char), 100000, in_file);
    fclose(in_file);
    
    // Tokenize the text into sentences
    char *sentence = strtok(text, "\n");
    char *sentences[100];
    int num_sentences = 0;
    while (sentence!= NULL) {
        sentences[num_sentences++] = strdup(sentence);
        sentence = strtok(NULL, "\n");
    }
    
    // Calculate the frequency of each word in each sentence
    int num_words[100];
    int *word_freq[100];
    for (int i = 0; i < num_sentences; i++) {
        num_words[i] = 0;
        word_freq[i] = malloc(sizeof(int) * 100);
        for (int j = 0; j < strlen(sentences[i]); j++) {
            char *word = strtok(sentences[i] + j, " ");
            int word_freq_index = 0;
            while (word_freq_index < 100 && strcmp(word, word_freq[i][word_freq_index])!= 0) {
                word_freq_index++;
            }
            word_freq[i][word_freq_index] = strdup(word);
            num_words[i]++;
        }
    }
    
    // Calculate the average word frequency for each sentence
    double avg_word_freq[100];
    for (int i = 0; i < num_sentences; i++) {
        int sum_word_freq = 0;
        for (int j = 0; j < num_words[i]; j++) {
            sum_word_freq += atof(word_freq[i][j]);
        }
        avg_word_freq[i] = sum_word_freq / num_words[i];
    }
    
    // Sort the sentences by average word frequency
    for (int i = 0; i < num_sentences; i++) {
        for (int j = i + 1; j < num_sentences; j++) {
            if (avg_word_freq[i] > avg_word_freq[j]) {
                char *temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
                temp = word_freq[i];
                word_freq[i] = word_freq[j];
                word_freq[j] = temp;
                temp = num_words[i];
                num_words[i] = num_words[j];
                num_words[j] = temp;
            }
        }
    }
    
    // Generate the summary text
    char summary_text[100000];
    for (int i = 0; i < num_sentences; i++) {
        if (i == 0) {
            strcpy(summary_text, sentences[i]);
        } else {
            strcat(summary_text, ". ");
            strcat(summary_text, sentences[i]);
        }
    }
    
    // Output the summary text
    printf("%s\n", summary_text);
    
    free(text);
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
        free(word_freq[i]);
    }
    free(sentences);
    free(word_freq);
    
    return 0;
}