//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 30

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} word_t;

int main() {
    FILE *dict_file, *input_file;
    word_t *dict = NULL;
    char line[MAX_WORD_LEN];
    int dict_size = 0, word_count = 0;
    char *input_file_name = "input.txt";

    // Load the dictionary
    dict_file = fopen("dict.txt", "r");
    if (dict_file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }
    while (fgets(line, MAX_WORD_LEN, dict_file)!= NULL) {
        int len = strlen(line);
        if (len >= MAX_WORD_LEN) {
            printf("Error: Dictionary word too long.\n");
            exit(1);
        }
        if (dict_size >= MAX_WORDS) {
            printf("Error: Dictionary too large.\n");
            exit(1);
        }
        strcpy(dict[dict_size].word, line);
        dict[dict_size].translation[0] = '\0';
        dict_size++;
    }
    fclose(dict_file);

    // Read input file and translate
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    while (fgets(line, MAX_WORD_LEN, input_file)!= NULL) {
        int len = strlen(line);
        if (len >= MAX_WORD_LEN) {
            printf("Error: Input word too long.\n");
            exit(1);
        }
        int i, j;
        for (i = 0; i < dict_size; i++) {
            if (strcasecmp(dict[i].word, line) == 0) {
                strcpy(dict[i].translation, "Alien");
                word_count++;
                break;
            }
        }
        if (i == dict_size) {
            printf("Unknown word: %s\n", line);
        }
    }
    fclose(input_file);

    // Print translation and word count
    printf("Translation complete.\n");
    printf("Words translated: %d\n", word_count);
    printf("Unknown words: %d\n", dict_size - word_count);
    return 0;
}