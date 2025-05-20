//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main() {
    char word[MAX_WORD_LENGTH];
    int count = 0;

    FILE *in_file, *out_file;

    in_file = fopen("input.csv", "r");
    if (in_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    out_file = fopen("output.csv", "w");
    if (out_file == NULL) {
        printf("Error opening output file.\n");
        fclose(in_file);
        return 1;
    }

    while (fscanf(in_file, "%s", word)!= EOF) {
        count++;
    }

    fclose(in_file);

    printf("Total words: %d\n", count);

    in_file = fopen("input.csv", "r");
    if (in_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    out_file = fopen("output.csv", "w");
    if (out_file == NULL) {
        printf("Error opening output file.\n");
        fclose(in_file);
        return 1;
    }

    while (fscanf(in_file, "%s", word)!= EOF) {
        if (strlen(word) > 0) {
            fprintf(out_file, "%s\n", word);
        }
    }

    fclose(in_file);
    fclose(out_file);

    return 0;
}