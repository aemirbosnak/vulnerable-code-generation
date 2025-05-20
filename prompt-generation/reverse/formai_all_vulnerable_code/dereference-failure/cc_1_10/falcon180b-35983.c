//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 80
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_PATH_LENGTH 200

// Function to count words in a string
int count_words(char* str) {
    int count = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to read a file and count words
int count_file_words(char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", file_path);
        return 0;
    }
    char line[MAX_LINE_LENGTH];
    int total_words = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int line_words = count_words(line);
        total_words += line_words;
    }
    fclose(file);
    return total_words;
}

// Function to print results
void print_results(char* file_path, int total_words) {
    printf("Total words in file %s: %d\n", file_path, total_words);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 0;
    }
    char file_path[MAX_FILE_PATH_LENGTH];
    strcpy(file_path, argv[1]);
    int total_words = count_file_words(file_path);
    print_results(file_path, total_words);
    return 0;
}