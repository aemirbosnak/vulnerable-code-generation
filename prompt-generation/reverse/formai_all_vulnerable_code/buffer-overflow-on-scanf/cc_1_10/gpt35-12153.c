//FormAI DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the occurrences of a word in a sentence
int countWord(char *sentence, char *word) {
    int count = 0;

    // Loop through the sentence and check for the word
    for(int i = 0; i < strlen(sentence); i++) {
        int flag = 1;

        // Check if the word matches the sentence starting from position i
        for(int j = 0; j < strlen(word); j++) {
            if(sentence[i+j] != word[j]) {
                flag = 0;
                break;
            }
        }

        // If word is found, increment the count
        if(flag && (i == 0 || sentence[i-1] == ' ') && (i+strlen(word) == strlen(sentence) || sentence[i+strlen(word)] == ' ')) {
            count++;
        }
    }

    return count;
}

int main() {
    // Take input of the sentence and word to be counted
    char sentence[1000], word[100];
    printf("Enter the sentence: ");
    fgets(sentence, 1000, stdin);
    printf("Enter the word to be counted: ");
    scanf("%s", word);

    // Remove unwanted characters from the sentence
    for(int i = 0; i < strlen(sentence); i++) {
        if(sentence[i] == '\n' || sentence[i] == '\r') {
            sentence[i] = '\0';
            break;
        }
    }

    // Count the occurrences of the word in the sentence
    int count = countWord(sentence, word);
    printf("The word '%s' occurs %d times in the sentence.\n", word, count);

    return 0;
}