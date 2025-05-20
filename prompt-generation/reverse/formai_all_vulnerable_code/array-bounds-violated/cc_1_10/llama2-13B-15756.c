//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define WORD_LENGTH 20
#define MIN_WORD_LENGTH 5

// Define a struct to hold a word and its frequency
typedef struct word {
    char *word;
    int frequency;
} Word;

// Define a list of words
typedef struct list {
    Word *words;
    int count;
} List;

// Function to read a sentence and count its words
void count_words(char *sentence, List *list) {
    // Split the sentence into words
    char *words[WORD_LENGTH];
    int i = 0;
    while (sentence[i] != '\0') {
        words[i] = sentence + i;
        i++;
    }

    // Add each word to the list
    for (int j = 0; j < i; j++) {
        Word word;
        word.word = words[j];
        word.frequency = 1;
        list->words = realloc(list->words, (list->count + 1) * sizeof(Word));
        list->words[list->count] = word;
        list->count++;
    }
}

// Function to print the list of words and their frequencies
void print_list(List *list) {
    for (int i = 0; i < list->count; i++) {
        printf("%s: %d\n", list->words[i].word, list->words[i].frequency);
    }
}

// Function to calculate the average word length
double average_word_length(List *list) {
    int sum = 0;
    for (int i = 0; i < list->count; i++) {
        sum += strlen(list->words[i].word);
    }
    return (double)sum / list->count;
}

// Function to print a happy message
void print_happy_message() {
    printf("YAY! You've reached the end of the program! :D \n");
}

int main() {
    // Create a list of words
    List list;
    list.words = malloc(sizeof(Word));
    list.count = 0;

    // Read a sentence and count its words
    char sentence[] = "The quick brown fox jumps over the lazy dog.";
    count_words(sentence, &list);

    // Print the list of words and their frequencies
    print_list(&list);

    // Calculate the average word length
    double average_length = average_word_length(&list);
    printf("Average word length: %f\n", average_length);

    // Print a happy message
    print_happy_message();

    return 0;
}