//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    FILE* input_file;
    FILE* output_file;
    char input_file_name[100];
    char output_file_name[100];
    char line[1000];
    int num_words;
    Word words[MAX_WORDS];
    int i;

    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    num_words = 0;
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char* word = strtok(line, " \t\n\r\f");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words.\n");
                exit(1);
            }
            strcpy(words[num_words].word, word);
            words[num_words].count = 1;
            num_words++;
            word = strtok(NULL, " \t\n\r\f");
        }
    }

    for (i = 0; i < num_words; i++) {
        Word* w = &words[i];
        int j;
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(w->word, words[j].word) == 0) {
                w->count += words[j].count;
                words[j].count = 0;
            }
        }
    }

    for (i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            fprintf(output_file, "%s %d\n", words[i].word, words[i].count);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}