//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int count;
} Class;

Class *classes = NULL;
int num_classes = 0;

void add_class(const char *name) {
    Class *new_class = malloc(sizeof(Class));
    new_class->name = strdup(name);
    new_class->count = 0;
    classes = realloc(classes, sizeof(Class) * ++num_classes);
    classes[num_classes - 1] = *new_class;
}

void classify(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file '%s'\n", filename);
        return;
    }

    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            char word[100];
            int i = 0;
            while (isalpha(ch)) {
                word[i++] = tolower(ch);
                ch = fgetc(file);
            }
            word[i] = '\0';

            Class *best_match = NULL;
            int best_score = 0;

            for (int j = 0; j < num_classes; j++) {
                int score = 0;
                for (int k = 0; k < strlen(word) && k < strlen(classes[j].name); k++) {
                    if (word[k] == classes[j].name[k]) {
                        score++;
                    }
                }
                if (score > best_score) {
                    best_match = &classes[j];
                    best_score = score;
                }
            }

            if (best_match) {
                best_match->count++;
            }
        }
    }

    fclose(file);

    for (int i = 0; i < num_classes; i++) {
        printf("%s: %d\n", classes[i].name, classes[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    add_class("cat");
    add_class("dog");
    add_class("bird");

    classify(argv[1]);

    return 0;
}