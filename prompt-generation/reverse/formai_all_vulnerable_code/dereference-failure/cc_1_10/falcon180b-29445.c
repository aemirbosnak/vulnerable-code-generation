//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 20
#define WORD_LIST_FILE "word_list.txt"

// Function to load the word list from file
void load_word_list(char *word_list[MAX_WORDS]) {
    FILE *file = fopen(WORD_LIST_FILE, "r");
    int count = 0;
    char word[MAX_WORDS][20];

    while (fscanf(file, "%s", word[count])!= EOF) {
        strcpy(word_list[count], word[count]);
        count++;
    }

    fclose(file);
}

// Function to generate a random conspiracy theory
void generate_conspiracy_theory(char *theory[MAX_CONSPIRACIES], char *word_list[MAX_WORDS]) {
    srand(time(NULL));
    int count = 0;

    while (count < MAX_CONSPIRACIES) {
        int choice = rand() % strlen(word_list[0]);
        strcat(theory[count], word_list[0][choice]);
        count++;
    }

    theory[count - 1] = '\0';
}

// Function to print the conspiracy theory in a romantic style
void print_conspiracy_theory(char *theory) {
    printf("In a world filled with love and romance,\n");
    printf("There lies a conspiracy theory so immense.\n\n");
    printf("The theory whispers of a secret organization,\n");
    printf("That controls the flow of love and affection.\n\n");
    printf("They manipulate our hearts with their power,\n");
    printf("Making us fall in love in the darkest hour.\n\n");
    printf("But fear not, my dear, for our love is true,\n");
    printf("And no conspiracy can ever break us in two.\n\n");
    printf("Together we'll fight against this hidden force,\n");
    printf("And our love will forever stay on course.\n\n");
    printf("So let's hold hands and face this mystery,\n");
    printf("With love in our hearts and romance in our history.\n");
}

int main() {
    char word_list[MAX_WORDS][20];
    char conspiracy_theory[MAX_CONSPIRACIES];

    load_word_list(word_list);
    generate_conspiracy_theory(conspiracy_theory, word_list);
    print_conspiracy_theory(conspiracy_theory);

    return 0;
}