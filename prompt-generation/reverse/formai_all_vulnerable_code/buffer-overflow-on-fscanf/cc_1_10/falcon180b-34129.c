//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

void read_words(FILE *fp) {
    char word[MAX_WORD_LENGTH];
    char c;
    int i = 0;

    while (fscanf(fp, "%c", &c) == 1) {
        if (isalpha(c)) {
            word[i] = tolower(c);
            i++;
        } else if (i > 0) {
            word[i] = '\0';
            strcpy(words[num_words], word);
            num_words++;
            i = 0;
        }
    }

    if (i > 0) {
        word[i] = '\0';
        strcpy(words[num_words], word);
        num_words++;
    }
}

void translate_words(char *input_file, char *output_file) {
    FILE *fp_in, *fp_out;
    char c;
    int i, j;

    fp_in = fopen(input_file, "r");
    fp_out = fopen(output_file, "w");

    if (fp_in == NULL || fp_out == NULL) {
        printf("Error: could not open file(s).\n");
        exit(1);
    }

    for (i = 0; i < num_words; i++) {
        for (j = 0; j < strlen(words[i]); j++) {
            c = words[i][j];

            if (isalpha(c)) {
                c = 'a' + (int) (rand() % 26);
            }

            fprintf(fp_out, "%c", c);
        }
        fprintf(fp_out, " ");
    }

    fclose(fp_in);
    fclose(fp_out);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    read_words(stdin);
    translate_words(argv[1], argv[2]);

    return 0;
}