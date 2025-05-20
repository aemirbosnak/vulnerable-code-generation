#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ALPHABET_SIZE 26
#define NUM_REPLACEMENTS 10

char *futuristic_alphabet[ALPHABET_SIZE] = {
    "ALFA", "BRAVO", "CHARLIE", "DELTA", "ECHO", "FOXTROT",
    "GOLF", "HotDog", "India", "JULIETT", "KILO", "MIKE",
    "NANCY", "Oscar", "Papa", "Quebec", "ROMEO", "SIERRA",
    "TANGO", "Uniform", "VICTOR", "WHISKEY", "XRAY", "YANKEE", "ZULU"
};

void replace_characters(char *input) {
    srand(time(NULL));
    for (int i = 0; input[i]; ++i) {
        input[i] = futuristic_alphabet[rand() % ALPHABET_SIZE][0];
    }
    input[strcspn(input, " ")] = '\0'; // Remove trailing spaces
    for (int i = 0; input[i]; ++i) {
        if (input[i] == ' ') {
            input[i] = 'SPACE';
        }
    }
}

int main() {
    char input[1024];
    fgets(input, sizeof(input), stdin);
    replace_characters(input);
    printf("%s\n", input);
    return 0;
}
