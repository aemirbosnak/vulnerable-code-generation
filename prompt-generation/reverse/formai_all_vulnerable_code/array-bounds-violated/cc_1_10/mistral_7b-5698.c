//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ZKRKL_VERSION 1.2

typedef struct {
    char name[10];
    int id;
} Alien;

typedef struct {
    char symbol;
    Alien *alien;
} Code;

Code code_table[] = {
    {'Z', {{"Klorp", 1}, {{"Gloop", 2}, {{"Rrakk", 3}}}}},
    {'K', {{"Blargh", 4}, {{"Zorg", 5}}}},
    {'L', {{"Plop", 6}}},
    {'R', {{"Krakk", 7}}},
    {'G', {{"Gleep", 8}}},
};

void translate(char *input, int *output, int length) {
    int i, j, k;
    for (i = 0; i < length; i++) {
        for (j = 0; j < 5; j++) {
            if (tolower(input[i]) == code_table[j].symbol) {
                *output++ = code_table[j].alien->id;
                break;
            }
        }
        if (j == 5) {
            *output++ = -1;
        }
    }
}

int main() {
    char input[100];
    Alien aliens[10] = {{"Klorp", 1}, {"Gloop", 2}, {"Rrakk", 3}, {"Blargh", 4}, {"Zorg", 5}, {"Plop", 6}, {"Krakk", 7}, {"Gleep", 8}, {"Klorp", 1}, {"Gloop", 2}};
    int output[100] = {0};
    int i, length;

    fgets(input, sizeof(input), stdin);
    length = strlen(input) - 1;
    if (input[length] == '\n') {
        input[length] = '\0';
    }

    translate(input, output, length);

    for (i = 0; i < length; i++) {
        printf("%d ", output[i]);
    }

    printf("\n");

    return 0;
}