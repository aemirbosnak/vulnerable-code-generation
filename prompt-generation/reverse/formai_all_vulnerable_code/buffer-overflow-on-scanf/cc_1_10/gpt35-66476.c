//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to remove punctuation from a string
void remove_punctuations(char* str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (!ispunct((unsigned char) str[i])) {
            str[j++] = tolower((unsigned char) str[i]);
        }
        i++;
    }
    str[j] = '\0';
}

// Structure to hold the word and its frequency
typedef struct {
    char* word;
    int frequency;
} WordCount;

// Function to compare two WordCount structs based on frequency
int compare_word_count(const void* a, const void* b) {
    const WordCount* aa = (const WordCount*) a;
    const WordCount* bb = (const WordCount*) b;
    return bb->frequency - aa->frequency;
}

// Function to print the word frequency table
void print_word_count_table(const WordCount* word_counts, const int num_words, const int total_words) {
    printf("\nWord Frequency Table\n");
    printf("--------------------\n");
    for (int i = 0; i < num_words; i++) {
        printf("%-15s %d %.2f%%\n", word_counts[i].word, word_counts[i].frequency, ((float) word_counts[i].frequency / (float) total_words) * 100);
    }
}

int main() {
    char filename[256];
    printf("Enter filename: ");
    scanf("%s", filename);
    
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Count the total number of words in the file
    int total_words = 0; 
    char buffer[1024];
    while (fscanf(fp, "%s", buffer) != EOF) {
        total_words++;
    }

    // Reset the file pointer back to the start of the file
    fseek(fp, 0, SEEK_SET);
    
    // Read the file into memory
    char* file_buffer = (char*) malloc(total_words * sizeof(char));
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        strcat(file_buffer, buffer);
    }
    fclose(fp);

    // Split the file buffer into individual words
    char* word = strtok(file_buffer, " \n");
    WordCount* word_counts = (WordCount*) malloc(total_words * sizeof(WordCount));
    int num_words = 0;
    while (word != NULL) {
        // Remove punctuation and convert to lowercase
        remove_punctuations(word);

        // Search for the word in the word counts array
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].frequency++;
                found = 1;
                break;
            }
        }
        // Add the word to the word counts array if it wasn't found
        if (!found) {
            word_counts[num_words].word = (char*) malloc((strlen(word) + 1) * sizeof(char));
            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].frequency = 1;
            num_words++;
        }
        word = strtok(NULL, " \n");
    }

    // Sort the word counts array based on frequency
    qsort(word_counts, num_words, sizeof(WordCount), compare_word_count);

    // Print the word frequency table
    print_word_count_table(word_counts, num_words, total_words);

    // Free dynamically allocated memory
    for (int i = 0; i < num_words; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);
    free(file_buffer);

    return 0;
}