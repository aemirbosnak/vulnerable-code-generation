//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_CONSPIRACY_LENGTH 200

typedef struct {
    char text[MAX_CONSPIRACY_LENGTH];
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES];
int num_conspiracies;

void generate_conspiracy(int index) {
    char *words[MAX_WORDS];
    int num_words = 0;
    char buffer[MAX_CONSPIRACY_LENGTH];
    int i, j;

    // Load conspiracy words
    FILE *fp = fopen("conspiracy_words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open conspiracy_words.txt\n");
        return;
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            break;
        }
        words[num_words++] = strdup(word);
    }
    fclose(fp);

    // Generate conspiracy
    sprintf(buffer, "The %s is a hoax perpetrated by the ", words[0]);
    for (i = 1; i < num_words; i++) {
        strcat(buffer, words[i]);
        if (i < num_words - 1) {
            strcat(buffer, ", ");
        }
    }
    strcat(buffer, "in order to ");
    for (i = 0; i < num_words; i++) {
        strcat(buffer, words[i]);
        if (i < num_words - 1) {
            strcat(buffer, ", ");
        }
    }
    strcat(buffer, ". Wake up, sheeple!");
    strcpy(conspiracies[index].text, buffer);
}

int main() {
    srand(time(NULL));

    FILE *fp = fopen("conspiracies.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open conspiracies.txt for writing\n");
        return 1;
    }

    num_conspiracies = 0;
    while (num_conspiracies < MAX_CONSPIRACIES) {
        generate_conspiracy(num_conspiracies);
        num_conspiracies++;
    }

    for (int i = 0; i < num_conspiracies; i++) {
        fprintf(fp, "%s\n", conspiracies[i].text);
    }

    fclose(fp);

    printf("Generated %d conspiracies and saved to conspiracies.txt\n", num_conspiracies);

    return 0;
}