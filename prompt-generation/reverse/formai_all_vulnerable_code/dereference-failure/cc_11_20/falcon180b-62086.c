//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    char input_text[1000000];
    int num_words = 0;
    WordFrequency words[MAX_WORDS];
    FILE *input_file;

    input_file = fopen("input_text.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    int file_size = ftell(input_file);
    rewind(input_file);

    if (file_size == 0) {
        printf("Error: Input file is empty.\n");
        exit(1);
    }

    fread(input_text, file_size, 1, input_file);
    fclose(input_file);

    char *token = strtok(input_text, " \t\r\n\f\v");
    while (token!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }

        int i;
        for (i = 0; i < strlen(token); i++) {
            if (!isalpha(token[i])) {
                token[i] = '\0';
            }
        }

        strcpy(words[num_words].word, token);
        words[num_words].frequency = 1;
        num_words++;

        token = strtok(NULL, " \t\r\n\f\v");
    }

    int num_spam_words = 0;
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, "viagra") == 0 || strcmp(words[i].word, "cialis") == 0 || strcmp(words[i].word, "levitra") == 0 || strcmp(words[i].word, "penis") == 0 || strcmp(words[i].word, "enlargement") == 0 || strcmp(words[i].word, "breast") == 0 || strcmp(words[i].word, "enhancement") == 0) {
            num_spam_words++;
        }
    }

    if (num_spam_words >= num_words / 2) {
        printf("This message may be spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}