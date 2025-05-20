//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_TEXT_LENGTH 100000
#define MAX_FILE_NAME_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    char text_file[MAX_FILE_NAME_LENGTH];
    strcpy(text_file, argv[1]);

    FILE *fp = fopen(text_file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file '%s'.\n", text_file);
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    int word_count[MAX_WORD_LENGTH] = {0};

    int text_length = fread(word, 1, MAX_TEXT_LENGTH, fp);
    fclose(fp);

    if (text_length == 0) {
        fprintf(stderr, "File is empty.\n");
        return 1;
    }

    for (int i = 0; i < text_length; i++) {
        word[i] = tolower(word[i]);
        if (word[i] == '\n' || word[i] == '\0') {
            continue;
        }

        for (int j = 0; j < MAX_WORD_LENGTH; j++) {
            if (word[i] == word[j]) {
                word_count[j]++;
            }
        }
    }

    int top_word_count = 0;
    int top_word_index[10] = {0};

    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (word_count[i] > top_word_count) {
            top_word_count = word_count[i];
            for (int j = 0; j < 10; j++) {
                if (top_word_index[j] == 0) {
                    top_word_index[j] = i;
                }
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d. '%s' - %d\n", i + 1, word, top_word_count);
    }

    return 0;
}