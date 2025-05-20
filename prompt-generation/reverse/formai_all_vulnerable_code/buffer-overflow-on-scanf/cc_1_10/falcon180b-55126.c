//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

char* extract_word(char* sentence, int start, int end) {
    char* word = malloc(end - start + 1);
    memcpy(word, sentence + start, end - start);
    word[end - start] = '\0';
    return word;
}

int compare_strings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = len1 < len2? len1 : len2;

    for (int i = 0; i < min_len; i++) {
        if (tolower(str1[i])!= tolower(str2[i])) {
            return 0;
        }
    }

    return 1;
}

void print_sentence(char* sentence) {
    int word_count = 0;
    char* word = strtok(sentence, " ");

    while (word!= NULL) {
        printf("%s ", word);
        word_count++;
        word = strtok(NULL, " ");
    }

    printf("\n");
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    scanf("%s", sentence);

    char* words[MAX_WORD_LENGTH];
    int word_count = 0;
    char* current_word = strtok(sentence, " ");

    while (current_word!= NULL) {
        if (word_count >= MAX_WORD_LENGTH) {
            printf("Error: Too many words in sentence.\n");
            return 1;
        }

        words[word_count] = extract_word(sentence, 0, strlen(sentence) - 1);
        word_count++;

        current_word = strtok(NULL, " ");
    }

    printf("Original sentence: ");
    print_sentence(sentence);

    printf("Reversed sentence: ");
    for (int i = word_count - 1; i >= 0; i--) {
        printf("%s ", words[i]);
    }

    return 0;
}