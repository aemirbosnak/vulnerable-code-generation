//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 20

char words[MAX_WORDS][MAX_LENGTH];
int num_words = 0;

void load_words(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[num_words], word);
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Warning: reached maximum number of words (%d)\n", MAX_WORDS);
            break;
        }
    }

    fclose(file);
}

void generate_theory(int num_words, char** words) {
    srand(time(0));

    printf("Conspiracy Theory:\n");
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        char* temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }

    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
        if (i % 5 == 4) {
            printf("\n");
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    load_words(argv[1]);
    generate_theory(num_words, words);

    return 0;
}