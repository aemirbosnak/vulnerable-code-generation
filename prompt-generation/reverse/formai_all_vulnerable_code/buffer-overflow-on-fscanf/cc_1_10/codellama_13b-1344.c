//Code Llama-13B DATASET v1.0 Category: Intrusion detection system ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 16
#define MAX_DICTIONARY_SIZE 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

void read_dictionary(Word dictionary[], int *size) {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s", dictionary[i].word) != EOF) {
        dictionary[i].frequency = 0;
        i++;
    }

    *size = i;

    fclose(fp);
}

void read_input(char *line, int *size) {
    fgets(line, MAX_LINE_LENGTH, stdin);
    *size = strlen(line);
}

void check_line(Word dictionary[], int dictionary_size, char *line, int line_size) {
    for (int i = 0; i < dictionary_size; i++) {
        char *word = strtok(line, " ");
        while (word != NULL) {
            if (strcmp(word, dictionary[i].word) == 0) {
                dictionary[i].frequency++;
            }
            word = strtok(NULL, " ");
        }
    }
}

void print_results(Word dictionary[], int dictionary_size) {
    for (int i = 0; i < dictionary_size; i++) {
        printf("%s: %d\n", dictionary[i].word, dictionary[i].frequency);
    }
}

int main() {
    Word dictionary[MAX_DICTIONARY_SIZE];
    int dictionary_size;
    read_dictionary(dictionary, &dictionary_size);

    char line[MAX_LINE_LENGTH];
    int line_size;
    read_input(line, &line_size);

    check_line(dictionary, dictionary_size, line, line_size);

    print_results(dictionary, dictionary_size);

    return 0;
}