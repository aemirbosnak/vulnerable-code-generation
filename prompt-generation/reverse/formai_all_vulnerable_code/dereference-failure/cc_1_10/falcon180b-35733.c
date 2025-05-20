//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_NAME_LENGTH 1000
#define MAX_FILE_SIZE 1000000

// Function to count the number of words in a string
int count_words(char* str) {
    int count = 0;
    int in_word = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }
    return count;
}

// Function to count the number of words in a file
int count_file_words(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    char buffer[MAX_FILE_SIZE];
    int count = 0;
    while (fgets(buffer, MAX_FILE_SIZE, file)!= NULL) {
        count += count_words(buffer);
    }
    fclose(file);
    return count;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    char filename[MAX_FILE_NAME_LENGTH];
    strcpy(filename, argv[1]);
    int count = count_file_words(filename);
    printf("The file '%s' contains %d words.\n", filename, count);
    return 0;
}