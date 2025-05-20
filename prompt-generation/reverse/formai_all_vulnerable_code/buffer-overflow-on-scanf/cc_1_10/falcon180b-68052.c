//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void read_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            int i = 0;
            while (isalpha(word[i])) {
                words[num_words].word[i] = tolower(word[i]);
                i++;
            }
            words[num_words].length = i;
            num_words++;
            word = strtok(NULL, ",.!?;:");
        }
    }

    fclose(file);
}

void generate_test(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        int num_words_in_sentence = rand() % 10 + 5;
        for (int j = 0; j < num_words_in_sentence; j++) {
            int word_index = rand() % num_words;
            fprintf(file, "%s ", words[word_index].word);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    char input_filename[100];
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    read_words(input_filename);

    char output_filename[100];
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    generate_test(output_filename);

    return 0;
}