//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 50
#define MAX_WORDS 1000
#define MAX_THEORIES 10

typedef struct {
    char name[MAX_LENGTH];
    char *words[MAX_WORDS];
    int num_words;
} Person;

void generate_theory(Person *p) {
    int i, j, k;
    char theory[MAX_LENGTH];
    char *word;

    i = rand() % p->num_words;
    word = p->words[i];

    for (j = 0; j < MAX_LENGTH && word[j]!= '\0'; j++) {
        theory[j] = word[j];
    }

    for (k = j; k < MAX_LENGTH; k++) {
        theory[k] = rand() % 26 + 'a';
    }

    theory[k] = '\0';

    printf("Theory: %s\n", theory);
}

void generate_theories(Person *p, int num_theories) {
    int i;

    for (i = 0; i < num_theories; i++) {
        generate_theory(p);
    }
}

int main() {
    Person p;
    srand(time(NULL));

    p.num_words = 0;

    while (p.num_words < MAX_WORDS) {
        char word[MAX_LENGTH];

        printf("Enter a word: ");
        scanf("%s", word);

        if (p.num_words >= MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }

        p.words[p.num_words] = strdup(word);
        p.num_words++;
    }

    generate_theories(&p, MAX_THEORIES);

    return 0;
}