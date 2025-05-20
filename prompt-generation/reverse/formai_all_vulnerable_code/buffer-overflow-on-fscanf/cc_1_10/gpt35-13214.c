//FormAI DATASET v1.0 Category: Spell checking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Welcome message */
void welcome_message() {
    printf("Hello! I'm your happy spell checker.\n");
    printf("I'll help you correct your mistakes. Let's get started!\n");
}

/* Check for a word in the dictionary */
int check_word(char* word) {
    FILE* fp;
    char dict_word[50];

    fp = fopen("dictionary.txt", "r");
    if(fp == NULL) {
        printf("Error: Dictionary file not found.\n");
        exit(1);
    }

    while(fscanf(fp, "%s", dict_word) != EOF) {
        if(strcmp(word, dict_word) == 0) {
            fclose(fp);
            return 1; // word found in dictionary
        }
    }

    fclose(fp);
    return 0; // word not found in dictionary
}

/* Correct spelling mistakes in a sentence */
void correct_spelling(char* sentence) {
    char* word = strtok(sentence, " ");
    int index = 0;
    int word_start = 0;
    int word_end = 0;
    int mistake_found = 0;
    char corrected_word[50] = {0};
    char corrected_sentence[200] = {0};

    while(word != NULL) {
        index = 0;
        word_start = word-sentence;
        word_end = word_start + strlen(word);

        while(word[index]) {
            word[index] = tolower(word[index]); // convert word to lowercase
            index++;
        }

        if(!check_word(word)) {
            printf("Oops! Mistake found in the sentence.\n");

            // generate corrected word
            printf("Correcting '%s'...\n", word);

            // randomize the corrected word for some fun
            int length = strlen(word);
            for(int i = 0; i < length; i++) {
                corrected_word[i] = rand() % 2 ? tolower(word[i]) : toupper(word[i]);
            }

            mistake_found = 1;
        }
        
        word = strtok(NULL, " ");

        if(mistake_found) {
            // add the corrected word to the corrected sentence
            strncat(corrected_sentence, sentence + word_start, word_end - word_start);
            strcat(corrected_sentence, " ");
            strcat(corrected_sentence, corrected_word);
            strcat(corrected_sentence, " ");

            mistake_found = 0;
        } else {
            // add the original word to the corrected sentence
            strncat(corrected_sentence, sentence + word_start, word_end - word_start);
            strcat(corrected_sentence, " ");
        }
    }

    printf("Corrected sentence: %s\n", corrected_sentence);
}

int main() {
    /* Initialize random seed */
    srand(time(0));

    /* Print welcome message to user */
    welcome_message();

    char sentence[200];

    printf("Please enter a sentence to check:\n");
    fgets(sentence, 200, stdin);

    /* remove newline character from input */
    sentence[strcspn(sentence, "\n")] = 0;

    /* Correct any spelling mistakes in the sentence */
    correct_spelling(sentence);

    printf("Hope I was able to help you! Have a great day!!\n");

    return 0;
}