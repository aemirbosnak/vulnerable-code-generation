//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 500

struct word {
    char *english;
    char *morse;
};

void load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open words.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].morse)!= EOF) {
        count++;
    }

    fclose(file);
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    char input[1000];
    printf("Enter text to convert to Morse code: ");
    fgets(input, sizeof(input), stdin);

    int index = 0;
    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].morse);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("Unknown word: %s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}