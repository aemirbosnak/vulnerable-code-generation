//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20
#define DICTIONARY_SIZE 100

typedef struct {
    char c;
    int index;
} Element;

void knuthShuffle(int *a, int n) {
    int i, j, k, temp;

    for (i = n - 1; i > 0; i--) {
        k = rand() % (i + 1);
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
}

void generateDictionary(Element *dictionary) {
    FILE *fp;
    int i = 0;

    fp = fopen("dictionary.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    while (fscanf(fp, " %c", &dictionary[i].c) != EOF) {
        dictionary[i].index = i;
        i++;
    }

    fclose(fp);
}

void generatePassword(Element *dictionary, int *shuffledIndexes, int length) {
    int i, j;
    char password[length + 1];

    for (i = 0; i < length; i++) {
        if (isalpha(dictionary[shuffledIndexes[i]].c)) {
            password[i] = tolower(dictionary[shuffledIndexes[i]].c);
        } else {
            password[i] = dictionary[shuffledIndexes[i]].c;
        }
    }

    password[length] = '\0';

    for (i = 0; i < length; i++) {
        for (j = i + 1; j < length; j++) {
            if (password[i] == password[j]) {
                generatePassword(dictionary, shuffledIndexes, length);
                return;
            }
        }
    }

    printf("Password: %s\n", password);
}

int main() {
    srand(time(NULL));

    Element dictionary[DICTIONARY_SIZE];
    int shuffledIndexes[MAX_LENGTH];

    generateDictionary(dictionary);

    int length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;

    knuthShuffle(dictionary, DICTIONARY_SIZE);

    int i;
    for (i = 0; i < length; i++) {
        shuffledIndexes[i] = dictionary[i].index;
    }

    generatePassword(dictionary, shuffledIndexes, length);

    return 0;
}