//FormAI DATASET v1.0 Category: Text processing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Start with taking input from the user
    printf("Enter a sentence to process: ");
    char sentence[100];
    fgets(sentence, 100, stdin);

    // Remove any newline character from the input
    int len = strlen(sentence);
    if (sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    // Tokenize the input sentence and count the number of words
    char* word = strtok(sentence, " ");
    int word_count = 0;
    while (word) {
        word_count++;
        word = strtok(NULL, " ");
    }
    printf("Total words: %d\n", word_count);

    // Find the longest word in the sentence and print it
    word = strtok(sentence, " ");
    char* longest_word = word;
    while (word) {
        if (strlen(word) > strlen(longest_word)) {
            longest_word = word;
        }
        word = strtok(NULL, " ");
    }
    printf("Longest word: %s\n", longest_word);

    // Find the most common character in the sentence and count its frequency
    int freq[256] = {0};
    for (int i = 0; i < strlen(sentence); i++) {
        freq[sentence[i]]++;
    }
    int max_freq = 0;
    char most_common_char = '\0';
    for (int i = 0; i < 256; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            most_common_char = i;
        }
    }
    printf("Most common character: %c\n", most_common_char);
    printf("Frequency of most common character: %d\n", max_freq);

    // Reverse the order of the words in the sentence and print it
    char* words[word_count];
    word = strtok(sentence, " ");
    int i = 0;
    while (word) {
        words[i] = word;
        i++;
        word = strtok(NULL, " ");
    }
    printf("Reversed sentence: ");
    for (int j = word_count - 1; j >= 0; j--) {
        printf("%s ", words[j]);
    }
    printf("\n");

    return 0;
}