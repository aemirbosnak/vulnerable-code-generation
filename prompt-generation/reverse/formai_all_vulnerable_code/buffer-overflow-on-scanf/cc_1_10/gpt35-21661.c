//FormAI DATASET v1.0 Category: Spell checking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate random typos
char generate_typo(char c) {
    int rand_num = rand() % 3;
    char typo;
    switch(rand_num) {
        case 0:
            typo = c + 1;
            break;
        case 1:
            typo = c - 1;
            break;
        case 2:
            typo = 'a' + (rand() % 26);
            break;
    }
    return typo;
}

int main() {
    char word[100];
    printf("Enter a word to check for typos: ");
    scanf("%s", word);

    srand(time(NULL));
    int len = strlen(word);
    char checked_word[len];

    // Check for typos and fix them if found
    for(int i = 0; i < len; i++) {
        char c = word[i];
        char typo = generate_typo(c);
        printf("%c", typo);

        // If the generated typo isn't the original character, replace it
        if(typo != c) {
            checked_word[i] = typo;
        } else {
            checked_word[i] = c;
        }
    }

    printf("\n\nOriginal word:\n%s\n", word);
    printf("Checked word:\n%s\n", checked_word);

    // Compare the original word and checked word to see if there are any typos
    if(strcmp(word, checked_word) == 0) {
        printf("\nNo typos found.\n");
    } else {
        printf("\nTypos found.\n");
    }

    return 0;
}