//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include<stdbool.h>
#include<limits.h>
#include<float.h>
#include<locale.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

char *words[MAX_WORDS];
int num_words = 0;

void load_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words in %s\n", filename);
            exit(1);
        }
        words[num_words] = strdup(word);
        num_words++;
    }

    fclose(file);
}

void randomize_string(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        int j = rand() % strlen(str);
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

void generate_text(char *filename, int num_sentences) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not create %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_sentences; i++) {
        int num_words_in_sentence = rand() % 10 + 5;
        char sentence[MAX_WORD_LEN * num_words_in_sentence];
        sentence[0] = '\0';

        for (int j = 0; j < num_words_in_sentence; j++) {
            int word_index = rand() % num_words;
            strcat(sentence, words[word_index]);
            strcat(sentence, " ");
        }
        strcat(sentence, ".");
        strcat(sentence, " ");

        randomize_string(sentence);
        fprintf(file, "%s\n", sentence);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file num_sentences\n", argv[0]);
        exit(1);
    }

    load_words(argv[1]);
    generate_text(argv[2], atoi(argv[3]));

    return 0;
}