//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words to store in the ebook
#define MAX_WORDS 1000

// Define the structure for each word in the ebook
typedef struct {
    char word[50];
    int frequency;
} Word;

// Function to compare two words based on their frequency
int compare_words(const void* a, const void* b) {
    const Word* word1 = (const Word*)a;
    const Word* word2 = (const Word*)b;
    
    if (word1->frequency > word2->frequency) {
        return -1;
    } else if (word1->frequency < word2->frequency) {
        return 1;
    } else {
        return 0;
    }
}

// Function to read the ebook from a file and store it in memory
void read_ebook(FILE* file, Word* words) {
    char ch;
    int i = 0;
    
    // Read the file until the end or the maximum number of words is reached
    while (fscanf(file, "%c", &ch) == 1 && i < MAX_WORDS) {
        // Convert the character to lowercase
        ch = tolower(ch);
        
        // Check if the character is a letter
        if (ch >= 'a' && ch <= 'z') {
            // Add the word to the ebook
            strcpy(words[i].word, "");
            while (fscanf(file, "%c", &ch) == 1 && ch >= 'a' && ch <= 'z') {
                strcat(words[i].word, &ch);
            }
            words[i].frequency = 1;
            i++;
        }
    }
    
    // Sort the ebook by frequency
    qsort(words, i, sizeof(Word), compare_words);
}

// Function to print the ebook
void print_ebook(const Word* words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s (%d)\n", words[i].word, words[i].frequency);
    }
}

// Main function
int main() {
    FILE* file;
    Word words[MAX_WORDS];
    
    // Open the ebook file
    file = fopen("ebook.txt", "r");
    
    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening ebook file.\n");
        return 1;
    }
    
    // Read the ebook from the file
    read_ebook(file, words);
    
    // Print the ebook
    printf("Ebook:\n");
    print_ebook(words, MAX_WORDS);
    
    // Close the ebook file
    fclose(file);
    
    return 0;
}