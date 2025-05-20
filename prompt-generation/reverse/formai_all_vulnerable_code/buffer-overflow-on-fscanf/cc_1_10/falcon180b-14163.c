//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_CONSPIRACY_WORDS 10
#define WORD_LIST_FILE "word_list.txt"

char *conspiracy_theory[MAX_CONSPIRACY_LENGTH];
int num_words;

void load_word_list(void) {
    FILE *fp;
    char word[MAX_CONSPIRACY_WORDS];

    if ((fp = fopen(WORD_LIST_FILE, "r")) == NULL) {
        printf("Error: Unable to open word list file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        conspiracy_theory[num_words++] = strdup(word);
    }

    fclose(fp);
}

void generate_conspiracy_theory(void) {
    int i;

    for (i = 0; i < num_words; i++) {
        conspiracy_theory[i] = conspiracy_theory[rand() % num_words];
    }
}

int main(void) {
    srand(time(NULL));

    load_word_list();
    generate_conspiracy_theory();

    printf("The conspiracy theory is: ");

    for (int i = 0; i < num_words; i++) {
        printf("%s ", conspiracy_theory[i]);
    }

    printf("\n");

    return 0;
}