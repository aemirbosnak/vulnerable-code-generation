//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cat language dictionary
char *cat_dict[] = {
    "Meow",
    "Purr",
    "Hiss",
    "Growl",
    "Yowl",
    "Chirp",
    "Trill",
    "Mew",
    "Caterwaul",
    "Waul",
    "Squeak",
    "Miaow",
    "Mrow"
};

// Random number generator
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Cat language translator
char *cat_translate(char *str) {
    int len = strlen(str);
    char *cat_str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        int idx = rand_int(0, 12);
        cat_str[i] = cat_dict[idx][0];
    }
    cat_str[len] = '\0';
    return cat_str;
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Get user input
    char *str = malloc(100);
    printf("Enter a string: ");
    scanf("%s", str);

    // Translate string to cat language
    char *cat_str = cat_translate(str);

    // Print translated string
    printf("Cat language translation: %s\n", cat_str);

    // Free memory
    free(str);
    free(cat_str);

    return 0;
}