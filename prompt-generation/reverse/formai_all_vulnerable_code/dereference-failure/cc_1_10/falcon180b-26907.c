//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char* english;
    char* cat;
} Translation;

int main() {
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");
    
    if (input_file == NULL || output_file == NULL) {
        printf("Error: Failed to open file(s).\n");
        return 1;
    }

    Translation* translations = calloc(MAX_LINE_LENGTH, sizeof(Translation));
    int num_translations = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char* english_word = strtok(line, " ");
        char* cat_word = strtok(NULL, " ");

        if (english_word == NULL || cat_word == NULL) {
            printf("Error: Invalid line format.\n");
            return 1;
        }

        Translation* translation = &translations[num_translations++];
        translation->english = strdup(english_word);
        translation->cat = strdup(cat_word);
    }

    fprintf(output_file, "{\n");
    for (int i = 0; i < num_translations; i++) {
        fprintf(output_file, "  \"%s\": \"%s\"", translations[i].english, translations[i].cat);
        if (i < num_translations - 1) {
            fprintf(output_file, ",");
        }
        fprintf(output_file, "\n");
    }
    fprintf(output_file, "}\n");

    fclose(input_file);
    fclose(output_file);

    return 0;
}