//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define WORD_LEN 20

char words[MAX_WORDS][WORD_LEN];
int num_words = 0;

void load_words(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    char word[WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(words[num_words], word);
        num_words++;
    }
    fclose(fp);
}

void translate(char* input) {
    char* output = malloc(strlen(input) + 1);
    strcpy(output, input);
    for (int i = 0; i < num_words; i++) {
        char* word = words[i];
        int len = strlen(word);
        char* pos = strstr(output, word);
        while (pos!= NULL) {
            for (int j = 0; j < len; j++) {
                pos[j] = '*';
            }
            pos += len;
            pos = strstr(pos, word);
        }
    }
    printf("%s\n", output);
    free(output);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    load_words(argv[1]);
    FILE* fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        printf("Error: could not open file %s\n", argv[2]);
        return 1;
    }
    char line[1000];
    while (fgets(line, sizeof(line), stdin)!= NULL) {
        translate(line);
        fprintf(fp_out, "%s", line);
    }
    fclose(fp_out);
    return 0;
}