//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char *string;
    int length;
} String;

String *read_file(char *filename) {
    FILE *file;
    String *result;
    char *buffer;
    int length;

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    result = malloc(sizeof(String));
    result->string = malloc(MAX_STRING_LENGTH);
    result->length = 0;

    while ((buffer = fgets(result->string + result->length, MAX_STRING_LENGTH - result->length, file))!= NULL) {
        length = strlen(buffer);
        result->length += length;
        result->string = realloc(result->string, result->length + 1);
        strcat(result->string, buffer);
    }

    fclose(file);

    return result;
}

String *remove_stop_words(String *input, char **stop_words, int num_stop_words) {
    String *result;
    char *word;
    int i;

    result = malloc(sizeof(String));
    result->string = malloc(MAX_STRING_LENGTH);
    result->length = 0;

    word = strtok(input->string, " ");
    while (word!= NULL) {
        for (i = 0; i < num_stop_words; i++) {
            if (strcmp(word, stop_words[i]) == 0) {
                word = strtok(NULL, " ");
                continue;
            }
        }
        result->string = realloc(result->string, result->length + strlen(word) + 1);
        strcat(result->string, word);
        strcat(result->string, " ");
        word = strtok(NULL, " ");
    }

    result->length = strlen(result->string);
    result->string = realloc(result->string, result->length + 1);
    result->string[result->length] = '\0';

    return result;
}

void print_summary(String *input, int num_sentences) {
    char *sentence;
    int i;

    sentence = strtok(input->string, ".");
    for (i = 0; i < num_sentences && sentence!= NULL; i++) {
        printf("%s ", sentence);
        sentence = strtok(NULL, ". ");
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <num_sentences>\n", argv[0]);
        exit(1);
    }

    String *input;
    char **stop_words;
    int num_stop_words;
    int num_sentences;

    input = read_file(argv[1]);
    stop_words = malloc(sizeof(char *) * 5);
    stop_words[0] = "the";
    stop_words[1] = "and";
    stop_words[2] = "of";
    stop_words[3] = "to";
    stop_words[4] = "in";
    num_stop_words = 5;
    num_sentences = atoi(argv[2]);

    input = remove_stop_words(input, stop_words, num_stop_words);
    print_summary(input, num_sentences);

    free(input->string);
    free(input);
    free(stop_words);

    return 0;
}