//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_LENGTH 1000000 // 1 million characters

// Function to count the frequency of a word in a file
int count_word_frequency(FILE *file, char *word) {
    int frequency = 0;
    char c;
    while ((c = fgetc(file))!= EOF) {
        if (isalpha(c)) {
            char *current_word = malloc(MAX_WORD_LENGTH * sizeof(char));
            int current_word_length = 0;
            while (isalpha(c)) {
                if (current_word_length >= MAX_WORD_LENGTH) {
                    break;
                }
                current_word[current_word_length++] = tolower(c);
                c = fgetc(file);
            }
            current_word[current_word_length] = '\0';
            if (strcmp(current_word, word) == 0) {
                frequency++;
            }
            free(current_word);
        }
    }
    return frequency;
}

// Function to read the file and count the frequency of each word
void count_word_frequencies(FILE *file) {
    char word[MAX_WORD_LENGTH];
    int frequency;
    while (fscanf(file, "%s", word)!= EOF) {
        frequency = count_word_frequency(file, word);
        printf("%s: %d\n", word, frequency);
    }
}

int main() {
    FILE *file;
    char filename[MAX_FILE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    count_word_frequencies(file);
    fclose(file);
    return 0;
}