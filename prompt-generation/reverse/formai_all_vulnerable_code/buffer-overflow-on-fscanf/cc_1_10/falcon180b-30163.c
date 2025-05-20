//Falcon-180B DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 100

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

void read_file(FILE* file, WordCount* word_counts, int num_words) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char* word = strtok(line, ",.?!;:-\n");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                strcpy(word_counts[i].word, word);
                word_counts[i].count = 1;
                i++;
                num_words++;
                for (; i < num_words; i++) {
                    word_counts[i].word[0] = '\0';
                    word_counts[i].count = 0;
                }
            }
            word = strtok(NULL, ",.?!;:-\n");
        }
    }
}

void write_file(FILE* file, WordCount* word_counts, int num_words) {
    fprintf(file, "Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        fprintf(file, "%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    int num_words = 0;
    WordCount word_counts[100];
    while (num_words < 100 && fscanf(input_file, "%s", word_counts[num_words].word)!= EOF) {
        num_words++;
    }

    read_file(input_file, word_counts, num_words);

    write_file(output_file, word_counts, num_words);

    fclose(input_file);
    fclose(output_file);

    return 0;
}