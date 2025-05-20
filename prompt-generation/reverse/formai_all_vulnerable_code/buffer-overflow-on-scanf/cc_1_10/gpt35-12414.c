//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Romeo and Juliet
/* Thou art welcome to the User Input Sanitizer,
   A program that cleanses input from impure sources,
   And dispenses with any danger that may lurk therein.

   In order to make sure our program never dost fail,
   We must validate each and every user input we receive,
   And convert it into a pure and uncorrupted form.

   Our method for doing so is to strip away any dangerous characters,
   And replace them with a simple dash, '-'.

   Thus, the user's input shall be rendered pure and holy,
   And our program will be protected from nefarious intentions.

   Hark! The code below shall demonstrate how this may be done. */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

void sanitize(char *input) {
    char *output = malloc(strlen(input) + 1);

    for (size_t i = 0; i < strlen(input); i++) {
        if (isalnum(input[i]) || isspace(input[i])) {
            output[i] = input[i];
        } else {
            output[i] = '-';
        }
    }

    output[strlen(input)] = '\0';
    strcpy(input, output);
    free(output);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Greetings, fair user! Pray tell, what is thy name?\n");
    scanf("%[^\n]", input);
    sanitize(input);
    printf("Ah, so thy name is %s. A fine name indeed!\n", input);

    printf("Tell me, fair user, where dost thou hail from?\n");
    scanf(" %[^\n]", input);
    sanitize(input);
    printf("Verily, %s is a far-off and exotic land!\n", input);

    printf("What is thy favorite color, fair user?\n");
    scanf(" %[^\n]", input);
    sanitize(input);
    printf("Ah, %s! A most excellent choice!\n", input);

    return 0;
}
/* Finito! */