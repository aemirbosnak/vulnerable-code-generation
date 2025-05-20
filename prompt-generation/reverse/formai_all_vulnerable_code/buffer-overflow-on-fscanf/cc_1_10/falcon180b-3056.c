//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

char *conspiracies[MAX_CONSPIRACIES];
char *words[MAX_WORDS];
int num_conspiracies = 0;
int num_words = 0;

void generate_conspiracy() {
    char conspiracy[MAX_WORD_LENGTH];
    char *word1 = words[rand() % num_words];
    char *word2 = words[rand() % num_words];
    char *word3 = words[rand() % num_words];
    char *word4 = words[rand() % num_words];
    char *word5 = words[rand() % num_words];

    strcpy(conspiracy, word1);
    strcat(conspiracy, " ");
    strcat(conspiracy, word2);
    strcat(conspiracy, " ");
    strcat(conspiracy, word3);
    strcat(conspiracy, " ");
    strcat(conspiracy, word4);
    strcat(conspiracy, " ");
    strcat(conspiracy, word5);

    conspiracies[num_conspiracies] = strdup(conspiracy);
    num_conspiracies++;
}

void generate_words() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int i = 0;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        words[i] = strdup(word);
        i++;
        if (i >= MAX_WORDS) {
            break;
        }
    }

    fclose(file);
    num_words = i;
}

int main() {
    srand(time(NULL));

    generate_words();

    while (num_conspiracies < MAX_CONSPIRACIES) {
        generate_conspiracy();
    }

    printf("Conspiracy Theories:\n");
    for (int i = 0; i < num_conspiracies; i++) {
        printf("%s\n", conspiracies[i]);
    }

    return 0;
}