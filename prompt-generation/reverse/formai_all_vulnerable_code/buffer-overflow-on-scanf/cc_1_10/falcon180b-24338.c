//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_SENTENCE_LEN 1000

// Function to count the number of words in a sentence
int count_words(char* sentence) {
    int word_count = 0;
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        word_count++;
        word = strtok(NULL, " ");
    }
    return word_count;
}

// Function to reverse a string
void reverse_string(char* str, int length) {
    char temp;
    for (int i = 0; i < length/2; i++) {
        temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
}

// Function to convert a string to uppercase
void strtoupper(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    // Prompt user for input
    char input[MAX_SENTENCE_LEN];
    printf("Enter a sentence: ");
    scanf("%s", input);

    // Count number of words in input sentence
    int word_count = count_words(input);

    // Reverse the input sentence
    reverse_string(input, strlen(input));

    // Convert the reversed sentence to uppercase
    strtoupper(input);

    // Print the modified sentence and word count
    printf("Reversed and uppercase sentence: %s\n", input);
    printf("Number of words in sentence: %d\n", word_count);

    return 0;
}