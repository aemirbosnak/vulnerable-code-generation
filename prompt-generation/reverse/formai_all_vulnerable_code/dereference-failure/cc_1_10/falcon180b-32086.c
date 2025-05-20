//Falcon-180B DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

char *words[MAX_WORDS];
int num_words = 0;

void process_line(char *line) {
    char *word;
    int len;
    int i;

    // Remove punctuation and convert to lowercase
    for (i = 0; line[i]!= '\0'; i++) {
        if (isalpha(line[i])) {
            line[i] = tolower(line[i]);
        } else if (!isspace(line[i])) {
            line[i] = '\0';
        }
    }

    // Tokenize line into words
    word = strtok(line, " ");
    while (word!= NULL) {
        len = strlen(word);
        if (len <= MAX_WORD_LEN) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words.\n");
                exit(1);
            }
            strcpy(words[num_words], word);
            num_words++;
        }
        word = strtok(NULL, " ");
    }
}

void print_words() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_WORD_LEN * 2];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        process_line(line);
    }

    fclose(file);
    print_words();

    return 0;
}