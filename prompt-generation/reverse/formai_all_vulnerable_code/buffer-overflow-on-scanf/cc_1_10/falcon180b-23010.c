//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100

// Function to read a line from a file
char* read_line(FILE* file) {
    char line[MAX_WORD_SIZE];
    fgets(line, MAX_WORD_SIZE, file);
    return strdup(line);
}

// Function to count the number of words in a line
int word_count(char* line) {
    int count = 0;
    char* token = strtok(line, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to print the line with word index
void print_line(char* line, int index) {
    char* token = strtok(line, " ");
    while (token!= NULL) {
        printf("%s ", token);
        if (index == 0) {
            printf("*");
        }
        index--;
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char* line;
    while ((line = read_line(file))!= NULL) {
        int index = 0;
        printf("Enter the word index to highlight: ");
        scanf("%d", &index);
        print_line(line, index);
        free(line);
    }

    fclose(file);
    return 0;
}