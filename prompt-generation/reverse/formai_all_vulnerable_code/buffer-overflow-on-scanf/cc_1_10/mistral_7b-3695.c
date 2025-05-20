//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CAT_SIZE 256

typedef struct {
    char name[20];
    int value;
} Cat;

Cat cats[CAT_SIZE];
int cats_count = 0;

void meow(int value) {
    for (int i = 0; i < value; i++) {
        printf("Meeeeowwwww!\n");
    }
}

void purr(int value) {
    for (int i = 0; i < value; i++) {
        printf("Purr... Purr... Purr...\n");
    }
}

void translate(char* text) {
    char current_word[20];
    char* word = strtok(text, " ");
    int len = strlen(word);

    if (len > 19) {
        printf("Error: word too long!\n");
        return;
    }

    strcpy(current_word, word);

    for (int i = 0; i < cats_count; i++) {
        if (strcmp(current_word, cats[i].name) == 0) {
            switch (cats[i].value) {
                case 1:
                    meow(len / 2);
                    break;
                case 2:
                    purr(len / 3);
                    break;
                case 3:
                    meow(len);
                    purr(len);
                    break;
            }
            return;
        }
    }

    // New word, add it to the dictionary
    strcpy(current_word, word);
    cats[cats_count++] = (Cat) { .name = current_word, .value = rand() % 4 + 1 };

    switch (cats[cats_count - 1].value) {
        case 1:
            meow(len);
            break;
        case 2:
            purr(len);
            break;
        case 3:
            meow(len);
            purr(len);
            break;
    }
}

int main() {
    char input[100];

    cats[0] = (Cat) { .name = "Whiskers", .value = 2 };
    cats[1] = (Cat) { .name = "Fluffy", .value = 1 };
    cats[2] = (Cat) { .name = "Garfield", .value = 3 };

    while (1) {
        printf("Enter a word to translate: ");
        scanf("%s", input);

        translate(input);
    }

    return 0;
}