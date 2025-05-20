//Falcon-180B DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct word {
    char text[MAX_WORD_LENGTH];
    int count;
};

int main() {
    FILE *input_file;
    char filename[50];
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    char delimiters[] = ",.?!;:";
    int i, j, k;
    struct word words[MAX_WORDS];
    int num_words = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (strchr(delimiters, line[i])!= NULL) {
                line[i] = '\0';
            }
        }
        for (j = 0; j < strlen(line); j++) {
            if (isalpha(line[j])) {
                strcpy(word, &line[j]);
                for (k = 0; k < strlen(word); k++) {
                    word[k] = tolower(word[k]);
                }
                if (num_words >= MAX_WORDS) {
                    printf("Maximum number of words reached.\n");
                    break;
                }
                for (i = 0; i < num_words; i++) {
                    if (strcmp(word, words[i].text) == 0) {
                        words[i].count++;
                        break;
                    }
                }
                if (i == num_words) {
                    strcpy(words[num_words].text, word);
                    words[num_words].count = 1;
                    num_words++;
                }
            }
        }
    }

    fclose(input_file);

    printf("Word\t\tFrequency\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\t\t%d\n", words[i].text, words[i].count);
    }

    return 0;
}