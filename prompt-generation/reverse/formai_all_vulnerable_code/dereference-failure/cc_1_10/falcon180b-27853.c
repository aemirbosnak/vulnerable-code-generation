//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 100

// Struct to store a single word
typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} Word;

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_SIZE);
    fgets(line, MAX_LINE_SIZE, file);
    return line;
}

// Function to split a line into words
void split_line(char* line, Word* words) {
    char* word = strtok(line, ",.?!;:");
    int i = 0;
    while (word!= NULL) {
        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
        word = strtok(NULL, ",.?!;:");
    }
}

// Function to sort words by frequency
void sort_words(Word* words, int num_words) {
    int i, j;
    Word temp;
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (words[j].count > words[i].count) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

// Function to print the word count
void print_count(Word* words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Word words[MAX_WORD_SIZE];
    int num_words = 0;

    char* line = read_line(file);
    while (line!= NULL) {
        split_line(line, words);
        num_words += 1;
        line = read_line(file);
    }

    sort_words(words, num_words);
    print_count(words, num_words);

    fclose(file);
    return 0;
}