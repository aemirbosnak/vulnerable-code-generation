//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORDS 200
#define MAX_LEN 100

typedef struct {
    char *english;
    char *alien;
} word_t;

word_t dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary() {
    FILE *fp;
    char line[MAX_LEN];
    char *token;

    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LEN, fp)!= NULL) {
        token = strtok(line, " ");
        if (token == NULL)
            continue;

        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is full.\n");
            exit(1);
        }

        dictionary[num_words].english = strdup(token);
        dictionary[num_words].alien = strdup(strtok(NULL, " "));
        num_words++;
    }

    fclose(fp);
}

int main() {
    char input[MAX_LEN];
    char *token;
    int i;

    load_dictionary();

    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_LEN, stdin);

    token = strtok(input, " ");
    while (token!= NULL) {
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                printf("%s ", dictionary[i].alien);
                break;
            }
        }

        if (i == num_words)
            printf("%s ", token);

        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}