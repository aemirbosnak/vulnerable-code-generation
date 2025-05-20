//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cat language dictionary
char *cat_dict[] = {
    "meow", // 0
    "purr", // 1
    "hiss", // 2
    "scratch", // 3
    "bite", // 4
    "play", // 5
    "sleep", // 6
    "eat", // 7
    "drink", // 8
    "groom", // 9
    "hunt", // 10
    "hide", // 11
    "climb", // 12
    "jump", // 13
    "run", // 14
    "walk", // 15
    "sit", // 16
    "lie down", // 17
    "stand up", // 18
    "shake head", // 19
    "wag tail", // 20
    "arch back", // 21
    "puff up fur", // 22
    "flatten ears", // 23
    "dilate pupils", // 24
    "constrict pupils", // 25
    "show teeth", // 26
    "hide teeth", // 27
    "lick lips", // 28
    "sneeze", // 29
    "cough", // 30
    "vomit", // 31
    "urinate", // 32
    "defecate", // 33
    "mate", // 34
    "give birth", // 35
    "raise young", // 36
    "die", // 37
    "other", // 38
};

// English language dictionary
char *eng_dict[] = {
    "meow", // 0
    "purr", // 1
    "hiss", // 2
    "scratch", // 3
    "bite", // 4
    "play", // 5
    "sleep", // 6
    "eat", // 7
    "drink", // 8
    "groom", // 9
    "hunt", // 10
    "hide", // 11
    "climb", // 12
    "jump", // 13
    "run", // 14
    "walk", // 15
    "sit", // 16
    "lie down", // 17
    "stand up", // 18
    "shake head", // 19
    "wag tail", // 20
    "arch back", // 21
    "puff up fur", // 22
    "flatten ears", // 23
    "dilate pupils", // 24
    "constrict pupils", // 25
    "show teeth", // 26
    "hide teeth", // 27
    "lick lips", // 28
    "sneeze", // 29
    "cough", // 30
    "vomit", // 31
    "urinate", // 32
    "defecate", // 33
    "mate", // 34
    "give birth", // 35
    "raise young", // 36
    "die", // 37
    "other", // 38
};

// Cat language translator
char *cat_to_eng(char *cat_word) {
    int i;

    for (i = 0; i < sizeof(cat_dict) / sizeof(char *); i++) {
        if (strcmp(cat_word, cat_dict[i]) == 0) {
            return eng_dict[i];
        }
    }

    return "other";
}

// English language translator
char *eng_to_cat(char *eng_word) {
    int i;

    for (i = 0; i < sizeof(eng_dict) / sizeof(char *); i++) {
        if (strcmp(eng_word, eng_dict[i]) == 0) {
            return cat_dict[i];
        }
    }

    return "other";
}

// Main function
int main() {
    char cat_word[100];
    char eng_word[100];

    printf("Enter a cat word: ");
    scanf("%s", cat_word);

    printf("The English translation is: %s\n", cat_to_eng(cat_word));

    printf("Enter an English word: ");
    scanf("%s", eng_word);

    printf("The cat translation is: %s\n", eng_to_cat(eng_word));

    return 0;
}