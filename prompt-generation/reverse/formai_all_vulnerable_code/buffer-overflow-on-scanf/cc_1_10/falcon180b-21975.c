//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

int count_words(char *line, int *word_count);

int main() {
    FILE *file;
    char filename[MAX_FILE_NAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    int word_count = 0;
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_count++;
        word_count += count_words(line, &word_count);
    }
    
    printf("Total number of lines: %d\n", line_count);
    printf("Total number of words: %d\n", word_count);
    
    fclose(file);
    return 0;
}

int count_words(char *line, int *word_count) {
    char *word;
    int count = 0;
    
    word = strtok(line, ",.?!;:");
    
    while (word!= NULL) {
        count++;
        word = strtok(NULL, ",.?!;:");
    }
    
    *word_count += count;
    
    return count;
}