//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

int countWords(char *sentence);
void reverseString(char *str);
void translate(char *input, char *output);

int main() {
    char input[MAX_WORD_LENGTH];
    char output[MAX_WORD_LENGTH];

    printf("Enter a sentence: ");
    scanf("%s", input);

    countWords(input);

    translate(input, output);

    printf("Translated sentence: %s\n", output);

    return 0;
}

int countWords(char *sentence) {
    int count = 0;
    char *word;

    word = strtok(sentence, " ");

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

void reverseString(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void translate(char *input, char *output) {
    int i, j, wordCount;
    char *word;
    char *reverseInput;
    char *reverseOutput;

    wordCount = countWords(input);
    reverseString(input);
    reverseInput = strdup(input);

    for (i = 0; i < wordCount; i++) {
        word = strtok(reverseInput, " ");
        j = 0;

        while (word[j]!= '\0') {
            if (isalpha(word[j])) {
                output[i*MAX_WORD_LENGTH+j] = toupper(word[j]);
            } else {
                output[i*MAX_WORD_LENGTH+j] = word[j];
            }
            j++;
        }

        output[i*MAX_WORD_LENGTH] = '\0';
    }

    reverseString(output);

    printf("Translated sentence: %s\n", output);
}