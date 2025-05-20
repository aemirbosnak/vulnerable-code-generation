//Falcon-180B DATASET v1.0 Category: Educational ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define SENTENCES_PER_PARAGRAPH 5

// Function prototypes
void reverse_string(char *str);
int count_words(char *sentence);
int count_sentences(char *paragraph);
void capitalize_first_letter(char *str);

int main() {
    char input_string[MAX_SENTENCE_LENGTH];
    char output_string[MAX_SENTENCE_LENGTH];
    int num_paragraphs;
    int i;

    // Get user input
    printf("Enter the number of paragraphs: ");
    scanf("%d", &num_paragraphs);

    for (i = 0; i < num_paragraphs; i++) {
        printf("Enter paragraph %d:\n", i+1);
        fgets(input_string, MAX_SENTENCE_LENGTH, stdin);

        // Reverse each sentence in the paragraph
        char *sentence = strtok(input_string, ".");
        while (sentence!= NULL) {
            reverse_string(sentence);
            printf("%s ", sentence);
            sentence = strtok(NULL, ".");
        }
        printf("\n");
    }

    return 0;
}

void reverse_string(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int count_words(char *sentence) {
    int count = 0;
    char *word;

    word = strtok(sentence, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

int count_sentences(char *paragraph) {
    int count = 0;
    char *sentence;

    sentence = strtok(paragraph, ".");
    while (sentence!= NULL) {
        count++;
        sentence = strtok(NULL, ".");
    }

    return count;
}

void capitalize_first_letter(char *str) {
    if (isalpha(*str)) {
        *str = toupper(*str);
    }
}