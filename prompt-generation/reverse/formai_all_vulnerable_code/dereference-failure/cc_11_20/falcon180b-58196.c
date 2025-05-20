//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 1000
#define MAX_CODE_WORDS 1000

struct CodeWord {
    char *code;
    char *word;
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage:./morse <text_file>\n");
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[MAX_CODE_LENGTH];
    char word[MAX_CODE_LENGTH];
    int word_count = 0;
    struct CodeWord code_words[MAX_CODE_WORDS];

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *ptr = strtok(line, " ");
        while (ptr!= NULL) {
            strcpy(word, ptr);
            int code_length = strlen(word);

            if (code_length == 1) {
                strcpy(code_words[word_count].code, ".-");
                strcpy(code_words[word_count].word, word);
                word_count++;
            } else if (code_length == 2) {
                strcpy(code_words[word_count].code, "-...");
                strcpy(code_words[word_count].word, word);
                word_count++;
            } else if (code_length == 3) {
                strcpy(code_words[word_count].code, "-.-.");
                strcpy(code_words[word_count].word, word);
                word_count++;
            } else if (code_length == 4) {
                strcpy(code_words[word_count].code, "-..");
                strcpy(code_words[word_count].word, word);
                word_count++;
            } else if (code_length == 5) {
                strcpy(code_words[word_count].code, ".");
                strcpy(code_words[word_count].word, word);
                word_count++;
            }

            ptr = strtok(NULL, " ");
        }
    }

    fclose(file);

    printf("Enter a word to convert to Morse code: ");
    scanf("%s", word);

    int i;
    for (i = 0; i < word_count; i++) {
        if (strcmp(word, code_words[i].word) == 0) {
            printf("%s\n", code_words[i].code);
            break;
        }
    }

    return 0;
}