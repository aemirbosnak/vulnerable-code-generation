//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

// Function to generate a random conspiracy theory
void generate_theory(char* theory) {
    char* nouns[] = {"government", "aliens", "illuminati", "lizard people", "Big Pharma", "deep state", "freemasons", "NWO", "Bilderberg Group", "secret society"};
    char* verbs[] = {"is controlling", "has infiltrated", "is manipulating", "is suppressing", "is covering up", "is plotting", "is scheming", "is engineering", "is orchestrating", "is perpetuating"};
    char* prepositions[] = {"the", "our", "their", "your", "his", "her", "its"};
    char* articles[] = {"a", "an", "the"};

    srand(time(NULL));
    int noun_index = rand() % sizeof(nouns)/sizeof(char*);
    int verb_index = rand() % sizeof(verbs)/sizeof(char*);
    int preposition_index = rand() % sizeof(prepositions)/sizeof(char*);
    int article_index = rand() % sizeof(articles)/sizeof(char*);

    strcpy(theory, articles[article_index]);
    strcat(theory, " ");
    strcat(theory, nouns[noun_index]);
    strcat(theory, " ");
    strcat(theory, prepositions[preposition_index]);
    strcat(theory, " ");
    strcat(theory, verbs[verb_index]);
    strcat(theory, " ");
    strcat(theory, "the world.");
}

// Function to print a random theory
void print_theory(char* theory) {
    printf("Conspiracy theory: %s\n", theory);
}

// Function to generate a random theory and print it
void generate_and_print_theory() {
    char theory[MAX_WORDS*MAX_WORD_LENGTH];
    generate_theory(theory);
    print_theory(theory);
}

// Function to generate multiple theories
void generate_multiple_theories(int num_theories) {
    for (int i = 0; i < num_theories; i++) {
        generate_and_print_theory();
    }
}

int main() {
    int num_theories;
    printf("How many conspiracy theories do you want to generate? ");
    scanf("%d", &num_theories);

    generate_multiple_theories(num_theories);

    return 0;
}