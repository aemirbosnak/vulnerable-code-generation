//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
};

void load_words(struct word words[]);
void translate_sentence(char sentence[], struct word words[]);
void save_translation(char translation[], FILE *output);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input);
        return 1;
    }

    struct word words[MAX_WORDS];
    load_words(words);

    char sentence[1000];
    while (fgets(sentence, sizeof(sentence), input)!= NULL) {
        translate_sentence(sentence, words);
        save_translation(sentence, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}

void load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat) == 2) {
        count++;
        if (count == MAX_WORDS) {
            printf("Error: Too many words in words file.\n");
            exit(1);
        }
    }

    fclose(file);
}

void translate_sentence(char sentence[], struct word words[]) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

void save_translation(char translation[], FILE *output) {
    fprintf(output, "%s", translation);
}