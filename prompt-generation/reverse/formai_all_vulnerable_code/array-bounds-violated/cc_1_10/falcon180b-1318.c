//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

typedef struct {
    char name[MAX_WORDS][MAX_WORD_LENGTH];
    int num_names;
} ConspiracyTheory;

ConspiracyTheory generate_conspiracy_theory() {
    ConspiracyTheory theory = { { "" } };
    int i;

    srand(time(NULL));

    for (i = 0; i < MAX_WORDS; i++) {
        int j;
        char word[MAX_WORD_LENGTH];

        for (j = 0; j < MAX_WORD_LENGTH; j++) {
            char c = rand() % 26 + 'a';
            word[j] = c;
        }
        word[j] = '\0';

        strcpy(theory.name[i], word);
    }

    theory.num_names = rand() % MAX_WORDS;

    return theory;
}

void print_conspiracy_theory(ConspiracyTheory theory) {
    printf("The %s conspiracy theory involves ", theory.name[0]);

    int i;
    for (i = 1; i < theory.num_names; i++) {
        printf("%s ", theory.name[i]);
    }

    printf("working together to ");

    i = rand() % 3;
    switch (i) {
        case 0:
            printf("control the world's governments.");
            break;
        case 1:
            printf("cover up the truth about aliens.");
            break;
        case 2:
            printf("manipulate the stock market.");
            break;
    }
}

int main() {
    int i;

    for (i = 0; i < 10; i++) {
        ConspiracyTheory theory = generate_conspiracy_theory();
        print_conspiracy_theory(theory);
        printf("\n");
    }

    return 0;
}