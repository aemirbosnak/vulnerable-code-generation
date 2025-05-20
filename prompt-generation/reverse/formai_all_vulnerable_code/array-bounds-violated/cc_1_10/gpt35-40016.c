//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char sentence[MAX_SIZE], word[MAX_SIZE];
    int word_count = 0;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SIZE, stdin);
    sentence[strlen(sentence) - 1] = '\0'; // Remove the newline character

    printf("\nEnter a word to search for: ");
    scanf("%s", word);

    // Loop through the sentence and count the occurrences of the word
    char* ptr = sentence;
    while ((ptr = strstr(ptr, word)) != NULL) {
        word_count++;
        ptr++;
    }

    printf("\nThe word '%s' appears %d times in the sentence '%s'\n", word, word_count, sentence);
    printf("\nHere is the sentence with the word highlighted:\n");

    // Loop through the sentence and highlight the occurrences of the word
    ptr = sentence;
    int i, j;
    while ((ptr = strstr(ptr, word)) != NULL) {
        // Print everything up to the occurrence of the word
        for (i = 0; i < ptr - sentence; i++) {
            printf("%c", sentence[i]);
        }

        // Print the word in uppercase
        printf("\033[1;33m"); // Set text color to yellow (33) and bold (1)
        for (j = 0; j < strlen(word); j++) {
            printf("%c", toupper(word[j]));
        }
        printf("\033[0m"); // Reset text color

        // Move the pointer past the occurrence of the word
        ptr += strlen(word);
    }

    // Print the rest of the sentence
    for (i = ptr - sentence; i < strlen(sentence); i++) {
        printf("%c", sentence[i]);
    }

    return 0;
}