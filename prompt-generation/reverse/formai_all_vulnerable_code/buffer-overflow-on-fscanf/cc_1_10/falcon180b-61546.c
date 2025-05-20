//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

char *resume[MAX_WORDS];
int num_words = 0;

void read_resume(FILE *fp) {
    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Resume too long.\n");
            exit(1);
        }
        resume[num_words++] = strdup(word);
    }
}

void tokenize_resume() {
    int i;
    for (i = 0; i < num_words; i++) {
        char *word = resume[i];
        int len = strlen(word);
        if (len > 2 && isalpha(word[0]) && isalpha(word[len - 1])) {
            word[len - 1] = '\0';
            resume[i] = word;
        }
    }
}

void print_skills() {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(resume[i], "programming") == 0 || strcmp(resume[i], "coding") == 0) {
            printf("%s\n", resume[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_resume(fp);
    fclose(fp);

    tokenize_resume();

    print_skills();

    return 0;
}