//Falcon-180B DATASET v1.0 Category: Text processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words = 0;

void read_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char c;
    while ((c = fgetc(file))!= EOF) {
        if (isalpha(c)) {
            int i = 0;
            while (isalpha(c) && i < MAX_WORD_LENGTH - 1) {
                words[num_words][i++] = tolower(c);
                c = fgetc(file);
            }
            words[num_words][i] = '\0';
            num_words++;
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words in file\n");
                exit(1);
            }
        } else {
            ungetc(c, file);
        }
    }

    fclose(file);
}

void count_words(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) == 0) {
            printf("%s appears %d times\n", word, i + 1);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    read_file(argv[1]);

    char word[MAX_WORD_LENGTH];
    printf("Enter a word to count: ");
    scanf("%s", word);
    count_words(word);

    return 0;
}