//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 64
#define MAX_WORDS 1000

void process_line(char *line, char words[][MAX_WORD_LENGTH], int *word_count) {
    char *token = strtok(line, " \n");
    *word_count = 0;
    
    while (token != NULL) {
        strncpy(words[*word_count], token, MAX_WORD_LENGTH);
        words[*word_count][MAX_WORD_LENGTH - 1] = '\0'; // Ensuring null termination
        (*word_count)++;
        token = strtok(NULL, " \n");
    }
}

void print_word_frequency(char words[][MAX_WORD_LENGTH], int word_count) {
    int frequencies[MAX_WORDS] = {0};
    int unique_word_count = 0;

    for (int i = 0; i < word_count; i++) {
        int found = 0;
        for (int j = 0; j < unique_word_count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequencies[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strncpy(words[unique_word_count], words[i], MAX_WORD_LENGTH);
            frequencies[unique_word_count] = 1;
            unique_word_count++;
        }
    }
    
    printf("\nWord Frequency:\n");
    for (int i = 0; i < unique_word_count; i++) {
        printf("%s: %d\n", words[i], frequencies[i]);
    }
}

void convert_to_uppercase(char *line) {
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] >= 'a' && line[i] <= 'z') {
            line[i] = line[i] - 'a' + 'A';
        }
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;

    printf("Welcome to the Grateful Text Processor!\n");
    printf("Please enter the filename to process: ");

    char filename[100];
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file: %s\n", filename);
        return 1;
    }
    
    printf("\nProcessing the file...\n");
    
    while (fgets(line, sizeof(line), file)) {
        convert_to_uppercase(line);  // Convert to uppercase before processing.
        process_line(line, words, &word_count);
    }
    
    fclose(file);
    print_word_frequency(words, word_count);
    
    printf("\nThank you for using the Grateful Text Processor! Goodbye!\n");
    
    return 0;
}