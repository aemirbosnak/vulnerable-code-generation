//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    char line[1000];
    char *word;
    int i, j, k, num_words = 0;
    Word words[MAX_WORDS];

    printf("Enter input filename: ");
    scanf("%s", input_filename);

    printf("Enter output filename: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    while (fgets(line, 1000, input_file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                for (j = 0; j < num_words; j++) {
                    if (strcmp(word, words[j].word) > 0) {
                        for (k = num_words - 1; k >= j; k--) {
                            strcpy(words[k].word, words[k - 1].word);
                            words[k].count = words[k - 1].count;
                        }
                        strcpy(words[j].word, word);
                        words[j].count = 1;
                        num_words++;
                        break;
                    }
                }
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    for (i = 0; i < num_words; i++) {
        fprintf(output_file, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}