//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: active
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

#define MAX_WORDS 1000

struct word {
    char english[50];
    char alien[100];
};

void loadWords(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].alien)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Too many words\n");
            exit(1);
        }
    }

    fclose(file);
}

int findWord(struct word words[], char *english) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].english, english) == 0) {
            return i;
        }
    }

    return -1;
}

void translate(struct word words[], char *text) {
    int i, j;
    char word[100];

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            j = 0;
            while (isalpha(text[i + j])) {
                word[j] = tolower(text[i + j]);
                j++;
            }
            word[j] = '\0';

            int index = findWord(words, word);
            if (index!= -1) {
                printf("%s ", words[index].alien);
            } else {
                printf("%s ", word);
            }
        } else {
            printf("%c ", text[i]);
        }
    }
}

int main() {
    struct word words[MAX_WORDS];
    loadWords(words);

    char text[1000];
    printf("Enter text to translate: ");
    fgets(text, sizeof(text), stdin);

    translate(words, text);

    return 0;
}