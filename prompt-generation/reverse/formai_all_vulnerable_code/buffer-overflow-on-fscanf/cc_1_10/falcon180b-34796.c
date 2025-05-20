//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50
#define NUM_CLASSES 10

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct class {
    char name[50];
    int count;
};

void read_words(FILE *fp, struct word *words) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            if (isalpha(word[i])) {
                word[i] = tolower(word[i]);
            }
        }
        int index = hash(word);
        words[index].count++;
    }
}

int hash(char *word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += word[i];
    }
    return sum % MAX_WORDS;
}

void print_classes(struct class *classes) {
    for (int i = 0; i < NUM_CLASSES; i++) {
        printf("%s: %d\n", classes[i].name, classes[i].count);
    }
}

int main() {
    srand(time(NULL));
    struct word words[MAX_WORDS];
    struct class classes[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        sprintf(classes[i].name, "Class %d", i + 1);
        classes[i].count = 0;
    }
    FILE *fp = fopen("data.txt", "r");
    read_words(fp, words);
    fclose(fp);
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            int class_index = rand() % NUM_CLASSES;
            classes[class_index].count++;
        }
    }
    print_classes(classes);
    return 0;
}