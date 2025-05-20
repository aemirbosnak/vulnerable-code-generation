//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define WORD_SIZE 50
#define DICTIONARY_SIZE 1000
#define LOAD_DICTIONARY 1
typedef struct {
    char word[WORD_SIZE];
    int is_valid;
} Word;
Word dictionary[DICTIONARY_SIZE];
void load_dictionary() {
    FILE *fp;
    int i = 0;
    if ((fp = fopen("dictionary.txt", "r")) == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }
    while (fscanf(fp, "%s", dictionary[i].word) != EOF) {
        i++;
    }
    fclose(fp);
}
bool is_valid_word(char *word) {
    int i;
    for (i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcasecmp(word, dictionary[i].word) == 0 && dictionary[i].is_valid == 1) {
            return true;
        }
    }
    return false;
}
void check_word(char *word) {
    if (is_valid_word(word)) {
        printf("%s is a valid word.\n", word);
    } else {
        printf("%s is not a valid word.\n", word);
    }
}
int main(int argc, char *argv[]) {
    int i;
    char input[WORD_SIZE];
    load_dictionary();
    printf("Spell checker:\n");
    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            check_word(argv[i]);
        }
    } else {
        printf("Enter a word to check: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        check_word(input);
    }
    return 0;
}