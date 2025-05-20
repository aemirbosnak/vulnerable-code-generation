//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 5000
#define MAX_WORD_LENGTH 100
#define MAX_WORDS_PER_LINE 100

int main(int argc, char* argv[]) {

    FILE* file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int words_per_line[MAX_WORDS_PER_LINE];

    int line_number = 1;
    int total_words = 0;
    int total_lines = 0;
    int max_words_per_line = 0;

    while(fgets(line, MAX_LINE_LENGTH, file)!= NULL) {

        total_lines++;

        int words_in_line = 0;
        char* token = strtok(line, " ");
        while(token!= NULL) {

            strcpy(word, token);

            if(strlen(word) > MAX_WORD_LENGTH) {
                printf("Error: Word too long on line %d.\n", line_number);
                exit(1);
            }

            int index = 0;
            while(index < MAX_WORDS_PER_LINE && words_in_line < MAX_WORDS_PER_LINE) {
                if(strcmp(word, "")!= 0) {
                    strcpy(words_per_line[index], word);
                    index++;
                }
                words_in_line++;
            }

            if(strcmp(word, "")!= 0) {
                printf("Error: Word too many on line %d.\n", line_number);
                exit(1);
            }

            token = strtok(NULL, " ");
        }

        if(words_in_line > max_words_per_line) {
            max_words_per_line = words_in_line;
        }

        total_words += words_in_line;
        line_number++;
    }

    printf("Total lines: %d\n", total_lines);
    printf("Total words: %d\n", total_words);
    printf("Longest line: %d words\n", max_words_per_line);

    fclose(file);
    return 0;
}