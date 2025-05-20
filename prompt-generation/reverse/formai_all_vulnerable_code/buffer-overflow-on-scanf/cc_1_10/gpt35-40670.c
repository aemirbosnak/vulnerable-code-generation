//FormAI DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void check_spelling(char *word) {
    /*Some dictionaries*/
    char *american_dict[] = {"color", "center", "organization", "program", "analyze"};
    int american_dict_len = sizeof(american_dict) / sizeof(american_dict[0]);

    char *british_dict[] = {"colour", "centre", "organisation", "programme", "analyse"};
    int british_dict_len = sizeof(british_dict) / sizeof(british_dict[0]);

    int dict_len;
    char **dict;

    /*Check if word is all alphabets*/
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            printf("%s\n", "Sorry, your input is invalid. Please input an all alphabetical word");
            return;
        }
    }

    /*Determine which dictionary to use*/
    if (strlen(word) >= 7 && word[strlen(word)-1] == 'e') {
        dict = british_dict;
        dict_len = british_dict_len;
    } else {
        dict = american_dict;
        dict_len = american_dict_len;
    }

    /*Check and suggest alternatives*/
    int n_alternatives = 0;
    for (int i = 0; i < dict_len; i++) {
        if (!strcmp(word, dict[i])) {
            printf("%s\n", "Your spelling is correct!");
            return;
        } else if (!strncmp(word, dict[i], strlen(word)-1) && dict[i][strlen(word)-1] != '\0') {
            printf("%s%s\n", "Did you mean ", dict[i]);
            n_alternatives++;
        }
    }

    if (n_alternatives == 0) {
        printf("%s\n", "Sorry, we do not have any suggestions for your spelling");
    }
}

int main() {
    printf("%s\n", "Welcome to Spell Checker!");
    char word[100];
    while (1) {
        printf("%s", "> ");
        scanf("%s", word);
        if (!strcmp(word, "exit")) {
            break;
        }
        check_spelling(word);
    }
    printf("%s\n", "Thank you for using Spell Checker!");
    return 0;
}