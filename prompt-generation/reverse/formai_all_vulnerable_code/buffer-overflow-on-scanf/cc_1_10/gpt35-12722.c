//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 25 // maximum number of words in a sentence
#define MAX_LENGTH 20 // maximum length of a word

void printRandomSentence();
void printRandomWord();

int main() {
    int num_sentences;
    double total_time, average_time, wpm; 
    printf("Welcome to the Typing Speed Test program!\n");
    printf("How many sentences would you like to type? ");
    scanf("%d", &num_sentences);
    printf("Please type the following sentences:\n");
    time_t start_time = time(NULL);
    int i;
    for (i = 0; i < num_sentences; i++) {
        printRandomSentence();
        printf("\n"); // print a newline to separate sentences
    }
    time_t end_time = time(NULL);
    total_time = difftime(end_time, start_time);
    average_time = total_time / num_sentences;
    wpm = (double)MAX_WORDS * num_sentences / total_time * 60;
    printf("\nYou typed %d sentences in %.2f seconds.\n", num_sentences, total_time);
    printf("Your average typing time per sentence was %.2f seconds\n", average_time);
    printf("Your typing speed is %.2f words per minute\n", wpm);
    return 0;
}

void printRandomSentence() {
    int num_words = rand() % MAX_WORDS + 1; // generate a random number of words
    int i;
    for (i = 0; i < num_words; i++) {
        printRandomWord();
        printf(" "); // print a space between words
    }
}

void printRandomWord() {
    int num_chars = rand() % MAX_LENGTH + 1; // generate a random length for the word
    char word[MAX_LENGTH + 1]; // allocate space for the word and the null terminator
    int i;
    for (i = 0; i < num_chars; i++) {
        int random_letter = rand() % 26 + 97; // generate a random lowercase letter
        word[i] = (char)random_letter;
    }
    word[num_chars] = '\0'; // add null terminator to the end of the word
    printf("%s", word);
}