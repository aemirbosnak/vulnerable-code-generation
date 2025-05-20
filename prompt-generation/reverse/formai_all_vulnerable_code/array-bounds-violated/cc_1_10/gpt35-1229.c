//FormAI DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    printf("Enter a sentence (less than 100 characters):\n");
    fgets(sentence, 100, stdin);

    // Remove newline character from sentence
    if (sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';
    }

    printf("Original sentence: %s\n", sentence);

    // Remove vowels from sentence
    char vowels[] = "aeiouAEIOU";
    int len = strlen(sentence);
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (strchr(vowels, sentence[i]) == NULL) {
            sentence[index++] = sentence[i];
        }
    }
    sentence[index] = '\0';

    printf("Sentence without vowels: %s\n", sentence);

    // Count number of words in sentence
    int word_count = 0;
    for (int i = 0; i < len; i++) {
        if (sentence[i] == ' ') {
            word_count++;
        }
    }
    word_count++; // Last word is not followed by a space

    printf("Number of words in sentence: %d\n", word_count);

    // Capitalize first letter of each word in sentence
    char *token;
    token = strtok(sentence, " ");
    while (token != NULL) {
        token[0] = toupper(token[0]);
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}