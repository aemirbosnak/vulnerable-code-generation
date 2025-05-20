//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 50
#define MAX_WORDS 10

typedef struct {
    char *subject;
    char *verb;
    char *object;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES];
char words[MAX_WORDS][20];
int num_words = 0;

void init_words() {
    FILE *fp = fopen("words.txt", "r");
    char word[20];
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(words[num_words++], word);
    }
    fclose(fp);
}

void generate_conspiracy() {
    srand(time(NULL));
    int num_conspiracies = rand() % MAX_CONSPIRACIES + 1;
    for (int i = 0; i < num_conspiracies; i++) {
        int subject_index = rand() % num_words;
        int verb_index = rand() % num_words;
        int object_index = rand() % num_words;
        strcpy(conspiracies[i].subject, words[subject_index]);
        strcpy(conspiracies[i].verb, words[verb_index]);
        strcpy(conspiracies[i].object, words[object_index]);
    }
}

void print_conspiracies() {
    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        if (conspiracies[i].subject[0]!= '\0') {
            printf("%s is secretly %s %s.\n", conspiracies[i].subject, conspiracies[i].verb, conspiracies[i].object);
        }
    }
}

int main() {
    init_words();
    generate_conspiracy();
    print_conspiracies();
    return 0;
}