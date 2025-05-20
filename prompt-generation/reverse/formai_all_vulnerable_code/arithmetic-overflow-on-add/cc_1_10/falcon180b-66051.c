//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

struct word_count {
    char word[20];
    int count;
};

void read_file(FILE *file, struct word_count words[MAX_WORDS]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(file))!= EOF && isalnum(ch)) {
                words[i].word[j++] = tolower(ch);
            }
            words[i].word[j] = '\0';
            words[i].count++;
            i++;
        }
    }
}

void write_file(FILE *file, struct word_count words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            fprintf(file, "%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    struct word_count words[MAX_WORDS];

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    read_file(input_file, words);
    fclose(input_file);

    write_file(output_file, words);
    fclose(output_file);

    return 0;
}