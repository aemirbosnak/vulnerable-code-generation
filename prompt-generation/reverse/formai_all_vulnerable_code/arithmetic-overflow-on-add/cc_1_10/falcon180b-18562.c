//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Function to count the words in a sentence
int countWords(char *sentence) {
    int count = 0;
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to count the frequency of words in a text
void countWordFrequency(char *text, int *frequency) {
    int i, j, k, wordCount;
    char word[MAX_WORD_LENGTH];
    memset(frequency, 0, sizeof(int) * MAX_WORDS);
    char *sentence = strtok(text, ".");
    while (sentence!= NULL) {
        wordCount = countWords(sentence);
        for (i = 0; i < wordCount; i++) {
            strcpy(word, strtok(sentence, " "));
            for (j = 0; j < strlen(word); j++) {
                word[j] = tolower(word[j]);
            }
            for (k = 0; k < MAX_WORD_LENGTH; k++) {
                if (word[k] == '\0')
                    break;
                frequency[(int)word[k]]++;
            }
        }
        sentence = strtok(NULL, ".");
    }
}

int main() {
    FILE *file;
    char ch;
    char text[10000];
    int i, j, frequency[26];

    // Open the file for reading
    file = fopen("apocalypse.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(file))!= EOF) {
        if (ch == '.') {
            text[i] = '.';
            i++;
        } else if (isalpha(ch)) {
            text[i] = tolower(ch);
            i++;
        }
    }
    text[i] = '\0';

    // Count the frequency of words in the text
    countWordFrequency(text, frequency);

    // Print the results
    printf("Word\tFrequency\n");
    for (i = 0; i < 26; i++) {
        if (frequency[i] > 0) {
            printf("%c\t%d\n", i + 'a', frequency[i]);
        }
    }

    fclose(file);
    return 0;
}