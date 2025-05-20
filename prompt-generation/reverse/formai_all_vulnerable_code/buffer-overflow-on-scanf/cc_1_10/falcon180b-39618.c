//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_SIZE 1000000
#define MAX_FILE_NAME_LENGTH 256

char filename[MAX_FILE_NAME_LENGTH];
FILE *file;
char line[MAX_LINE_LENGTH];
int line_number = 1;
int total_lines = 0;
int total_words = 0;
int total_chars = 0;

void read_file() {
    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        total_lines++;
        total_chars += strlen(line);
    }

    rewind(file);
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        total_words += count_words(line);
    }

    printf("Total lines: %d\n", total_lines);
    printf("Total words: %d\n", total_words);
    printf("Total characters: %d\n", total_chars);

    fclose(file);
}

int count_words(char *line) {
    int words = 0;
    char *token;

    token = strtok(line, " ");
    while (token!= NULL) {
        words++;
        token = strtok(NULL, " ");
    }

    return words;
}

int main() {
    while (1) {
        read_file();
    }

    return 0;
}