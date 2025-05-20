//FormAI DATASET v1.0 Category: Text Summarizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("My Darling, let me summarize this wonderful moment we're sharing together.\n");
    
    // ask for user input
    printf("Please enter the text you want me to summarize:\n");
    char input[1000];
    fgets(input, sizeof(input), stdin);

    // tokenize the input text
    char *token = strtok(input, " ");
    int num_words = 0;
    while (token != NULL) {
        printf("%s ", token);
        num_words++;
        token = strtok(NULL, " ");
    }
    printf("\n");
    printf("There are %d words in your beautiful text.\n", num_words);
    
    // calculate average word length
    double total_length = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != ' ' && input[i] != '\n') {
            total_length++;
        }
    }
    double avg_length = total_length / num_words;
    printf("The average word length is %.1f characters.\n", avg_length);
    
    // determine most common word
    char *words[1000];
    int freq[1000];
    int num_unique_words = 0;
    token = strtok(input, " ");
    while (token != NULL) {
        int i;
        for (i = 0; i < num_unique_words; i++) {
            if (strcmp(words[i], token) == 0) {
                freq[i]++;
                break;
            }
        }
        if (i == num_unique_words) {
            words[num_unique_words] = strdup(token);
            freq[num_unique_words] = 1;
            num_unique_words++;
        }
        token = strtok(NULL, " ");
    }
    int max_freq = -1;
    char *most_common_word = "";
    for (int i = 0; i < num_unique_words; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            most_common_word = words[i];
        }
    }
    printf("The most common word is \"%s\" with a frequency of %d.\n", most_common_word, max_freq);
    
    // say goodbye
    printf("Thank you for sharing your lovely words with me. I will always remember this moment with you.\n");
    return 0;
}