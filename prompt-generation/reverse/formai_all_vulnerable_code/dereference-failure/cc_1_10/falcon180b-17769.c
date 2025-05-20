//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 10

struct word {
    char *english;
    char *alien;
};

int main() {
    struct word words[MAX_WORDS];
    int num_words = 0;
    char input_line[1000];
    char *token;
    FILE *input_file;
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }
    while (fgets(input_line, sizeof(input_line), input_file)!= NULL) {
        token = strtok(input_line, " ");
        while (token!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words in input.\n");
                exit(1);
            }
            if (strlen(token) > MAX_WORD_LEN) {
                printf("Error: Word \"%s\" is too long.\n", token);
                exit(1);
            }
            words[num_words].english = strdup(token);
            words[num_words].alien = (char *)malloc(MAX_WORD_LEN * sizeof(char));
            strcpy(words[num_words].alien, "");
            num_words++;
            token = strtok(NULL, " ");
        }
    }
    fclose(input_file);
    for (int i = 0; i < num_words; i++) {
        printf("Enter translation for \"%s\": ", words[i].english);
        scanf("%s", words[i].alien);
    }
    input_file = fopen("output.txt", "w");
    if (input_file == NULL) {
        printf("Error: Output file could not be created.\n");
        exit(1);
    }
    for (int i = 0; i < num_words; i++) {
        fprintf(input_file, "%s %s\n", words[i].english, words[i].alien);
    }
    fclose(input_file);
    printf("Translation complete.\n");
    return 0;
}