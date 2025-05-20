//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_WORDS 1000

struct word {
    char *english;
    char *alien;
};

bool load_dictionary(struct word *dictionary) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return false;
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", dictionary[count].english, dictionary[count].alien)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Error: Dictionary is too large.\n");
            fclose(file);
            return false;
        }
    }

    fclose(file);
    return true;
}

void translate_sentence(char *sentence, struct word *dictionary) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                printf("%s ", dictionary[i].alien);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("Unknown word: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

int main() {
    struct word dictionary[MAX_WORDS];
    if (!load_dictionary(dictionary)) {
        return 1;
    }

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, dictionary);

    return 0;
}