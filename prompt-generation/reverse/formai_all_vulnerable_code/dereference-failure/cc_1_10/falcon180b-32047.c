//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(char *filename, struct word *words) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char ch;
    int in_word = 0;
    char word[MAX_WORD_LENGTH];
    word[0] = '\0';

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            if (!in_word) {
                in_word = 1;
                strcat(word, &ch);
            } else {
                strcat(word, &ch);
            }
        } else {
            in_word = 0;

            if (strlen(word) > 0) {
                int i;
                for (i = 0; i < strlen(word); i++) {
                    word[i] = tolower(word[i]);
                }

                int found = 0;
                for (i = 0; i < MAX_WORD_LENGTH; i++) {
                    if (words[i].word[0] == '\0') {
                        strcpy(words[i].word, word);
                        words[i].count = 1;
                        found = 1;
                        break;
                    } else if (strcmp(word, words[i].word) == 0) {
                        words[i].count++;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Error: word '%s' not found in file\n", word);
                    exit(1);
                }
            }
        }
    }

    fclose(fp);
}

void translate(char *filename, struct word *words) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char ch;
    int in_word = 0;
    char word[MAX_WORD_LENGTH];
    word[0] = '\0';

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            if (!in_word) {
                in_word = 1;
                strcat(word, &ch);
            } else {
                strcat(word, &ch);
            }
        } else {
            in_word = 0;

            if (strlen(word) > 0) {
                int i;
                for (i = 0; i < strlen(word); i++) {
                    word[i] = tolower(word[i]);
                }

                int found = 0;
                for (i = 0; i < MAX_WORD_LENGTH; i++) {
                    if (strcmp(word, words[i].word) == 0) {
                        if (words[i].count == 1) {
                            fprintf(fp, "meow ");
                        } else {
                            fprintf(fp, "meows ");
                        }
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    fprintf(fp, "%s ", word);
                }
            }
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    struct word words[MAX_WORD_LENGTH];
    read_file(argv[1], words);

    translate(argv[2], words);

    return 0;
}