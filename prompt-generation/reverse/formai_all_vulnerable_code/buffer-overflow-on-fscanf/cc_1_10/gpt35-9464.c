//FormAI DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_WORDS = 1000; // maximum number of words expected in input file

// function to read words from a file and return the number of words read
int read_file(FILE *fptr, char *words[]) {
    int count = 0;
    char buf[100];

    while(fscanf(fptr, "%s", buf) != EOF) {
        words[count] = strdup(buf); // strdup dynamically allocates memory and returns a pointer to it
        count++;
    }

    return count;
}

// function to sort the words in alphabetical order
void sort_words(char *words[], int count) {
    for(int i = 0; i < count - 1; i++) {
        for(int j = i + 1; j < count; j++) {
            if(strcmp(words[i], words[j]) > 0) {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

// function to write the sorted words to a file
void write_file(FILE *fptr, char *words[], int count) {
    for(int i = 0; i < count; i++) {
        fprintf(fptr, "%s\n", words[i]);
    }
}

int main() {
    char *words[MAX_WORDS];
    FILE *input_file, *output_file;
    int count;

    // open input and output files
    input_file = fopen("input.txt", "r");
    if(input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    output_file = fopen("output.txt", "w");
    if(output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // read words from input file
    count = read_file(input_file, words);

    // sort words in alphabetical order
    sort_words(words, count);

    // write sorted words to output file
    write_file(output_file, words, count);

    // close files and free memory used
    fclose(input_file);
    fclose(output_file);
    for(int i = 0; i < count; i++) {
        free(words[i]);
    }

    printf("Words sorted successfully!\n");

    return 0;
}