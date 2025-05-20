//FormAI DATASET v1.0 Category: Text Summarizer ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// define the maximum number of words to be summarized
#define MAX_WORDS 100

// function to get the frequency of each word in the text
void get_word_frequency(char text[], char words[][50], int frequency[], int *num_words) {
    // initialize variables
    char word[50];
    int i, j, k, freq, len;

    *num_words = 0;
    i = 0;

    // go through each character in the text
    while(text[i] != '\0') {
        // initialize variables for a new word
        j = 0;
        freq = 0;
        len = strlen(word);

        // if a letter is found, add it to the word
        if(isalpha(text[i])) {
            word[j++] = tolower(text[i]);
        }
        // if a word is complete
        else if(len > 0) {
            // add a null terminator to the word
            word[j] = '\0';

            // check if the word already exists
            for(k = 0; k < *num_words; k++) {
                if(strcmp(word, words[k]) == 0) {
                    // increment the frequency of the word
                    frequency[k]++;
                    freq = 1;
                    break;
                }
            }

            // if the word does not exist, add it to the list
            if(!freq) {
                strcpy(words[*num_words], word);
                frequency[*num_words]++;
                (*num_words)++;
            }

            // reset the word
            j = 0;
            word[j] = '\0';
        }

        i++;        
    }
}

// function to sort the words by frequency
void sort_words_by_frequency(char words[][50], int frequency[], int num_words) {
    // initialize variables
    int i, j, max_idx, temp_freq;
    char temp_word[50];

    // go through each word
    for(i = 0; i < num_words; i++) {
        // find the word with the maximum frequency
        max_idx = i;
        for(j = i+1; j < num_words; j++) {
            if(frequency[j] > frequency[max_idx]) {
                max_idx = j;
            }
        }

        // swap the current word with the word with maximum frequency
        strcpy(temp_word, words[i]);
        strcpy(words[i], words[max_idx]);
        strcpy(words[max_idx], temp_word);

        // swap the current frequency with the frequency of maximum frequency word
        temp_freq = frequency[i];
        frequency[i] = frequency[max_idx];
        frequency[max_idx] = temp_freq;
    }
}

// function to summarize the text
void summarize_text(char text[], int summary_length) {
    // initialize variables
    char words[MAX_WORDS][50];
    int frequency[MAX_WORDS] = {0};
    int num_words, i;

    // get the frequency of each word in the text
    get_word_frequency(text, words, frequency, &num_words);

    // sort the words by frequency
    sort_words_by_frequency(words, frequency, num_words);

    // print the summary
    printf("Summary:\n");
    for(i = 0; i < num_words && i < summary_length; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// main function
int main() {
    char text[1000];
    int summary_length;

    // get the text to summarize
    printf("Enter the text to summarize:\n");
    fgets(text, 1000, stdin);

    // get the length of the summary
    printf("Enter the length of summary:\n");
    scanf("%d", &summary_length);

    // summarize the text
    summarize_text(text, summary_length);

    return 0;
}