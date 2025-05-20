//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct word_freq {
    char *word;
    int frequency;
} word_freq;

void count_word_freq(char *string, word_freq *word_freq_arr, int *arr_size) {
    // Base case
    if (*string == '\0') {
        return;
    }
    
    // Check for end of word
    char *word_end = strchr(string, ' ');
    if (word_end == NULL) {
        word_end = strchr(string, '\0');
    }
    
    int word_len = word_end - string;
    
    // Check if word exists in array; if so, increment frequency
    for (int i = 0; i < *arr_size; i++) {
        if (strncmp(word_freq_arr[i].word, string, word_len) == 0) {
            word_freq_arr[i].frequency++;
            count_word_freq(word_end, word_freq_arr, arr_size);
            return;
        }
    }
    
    // If word does not exist in array, add to array
    word_freq_arr = realloc(word_freq_arr, (*arr_size + 1) * sizeof(word_freq));
    word_freq_arr[*arr_size].word = malloc(word_len + 1);
    strncpy(word_freq_arr[*arr_size].word, string, word_len);
    word_freq_arr[*arr_size].word[word_len] = '\0';
    word_freq_arr[*arr_size].frequency = 1;
    (*arr_size)++;
    
    // Recursive call
    count_word_freq(word_end, word_freq_arr, arr_size);
}

int main() {
    char string[1000];
    printf("Enter a string: ");
    fgets(string, 1000, stdin);
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
    
    word_freq *word_freq_arr = malloc(sizeof(word_freq));
    int arr_size = 0;
    
    count_word_freq(string, word_freq_arr, &arr_size);
    
    // Print word frequency array
    for (int i = 0; i < arr_size; i++) {
        printf("%s: %d\n", word_freq_arr[i].word, word_freq_arr[i].frequency);
    }
    
    // Cleanup
    for (int i = 0; i < arr_size; i++) {
        free(word_freq_arr[i].word);
    }
    free(word_freq_arr);
    
    return 0;
}