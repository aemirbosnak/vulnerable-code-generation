//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    char input_file[100], output_file[100];
    FILE *input, *output;
    char line[1000];
    char word[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int num_words = 0;
    int i, j;

    // Get input and output file names
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input file
    input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Open output file
    output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    // Read input file and count words
    while (fgets(line, sizeof(line), input)!= NULL) {
        i = 0;
        while (i < strlen(line)) {
            if (isspace(line[i])) {
                line[i] = '\0';
                if (strlen(word) > 0) {
                    for (j = 0; j < num_words; j++) {
                        if (strcmp(words[j].word, word) == 0) {
                            words[j].count++;
                            break;
                        }
                    }
                    if (j == num_words) {
                        strcpy(words[num_words].word, word);
                        words[num_words].count = 1;
                        num_words++;
                    }
                }
                i++;
                strcpy(word, "");
            } else {
                strcat(word, &line[i]);
            }
        }
    }

    // Write output file
    fprintf(output, "Word\tCount\n");
    for (i = 0; i < num_words; i++) {
        fprintf(output, "%s\t%d\n", words[i].word, words[i].count);
    }

    // Close files
    fclose(input);
    fclose(output);

    return 0;
}