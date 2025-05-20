//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: ephemeral
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct { char word[50], translation[50]; } TranslationPair;

void print_menu() {
    printf("\n--- CAT MENU ---\n");
    printf("1. Add a new translation pair\n");
    printf("2. Translate a word\n");
    printf("3. Remove a translation pair\n");
    printf("4. List all translation pairs\n");
    printf("5. Quit\n");
}

void add_translation(TranslationPair* dictionary, int* num_pairs, char* word, char* translation) {
    TranslationPair new_pair = { word, translation };
    if (*num_pairs < 100) {
        dictionary[*num_pairs] = new_pair;
        (*num_pairs)++;
    }
    else {
        printf("\nDictionary is full!\n");
    }
}

int find_index(TranslationPair* dictionary, int num_pairs, char* word) {
    for (int i = 0; i < num_pairs; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void remove_translation(TranslationPair* dictionary, int* num_pairs, int index) {
    if (index >= 0 && index < *num_pairs) {
        memmove(&dictionary[index], &dictionary[index + 1], sizeof(TranslationPair) * (*num_pairs - index - 1));
        (*num_pairs)--;
    }
}

void translate_word(TranslationPair* dictionary, int num_pairs, char* word) {
    int index = find_index(dictionary, num_pairs, word);
    if (index != -1) {
        printf("\n%s translates to %s.\n", word, dictionary[index].translation);
    }
    else {
        printf("\n%s not found in dictionary!\n", word);
    }
}

void list_translations(TranslationPair* dictionary, int num_pairs) {
    printf("\n--- DICTIONARY ---\n");
    for (int i = 0; i < num_pairs; i++) {
        printf("%s -> %s\n", dictionary[i].word, dictionary[i].translation);
    }
}

int main(void) {
    srand(time(NULL));
    TranslationPair dictionary[100];
    int num_pairs = 0;

    char command[5];
    char word[50], translation[50];

    while (1) {
        print_menu();
        scanf("%s", command);

        switch (*command) {
        case '1':
            printf("Enter a word to translate: ");
            scanf("%s", word);
            printf("Enter its translation: ");
            scanf("%s", translation);
            add_translation(dictionary, &num_pairs, word, translation);
            break;

        case '2':
            printf("Enter a word to translate: ");
            scanf("%s", word);
            translate_word(dictionary, num_pairs, word);
            break;

        case '3':
            if (num_pairs > 0) {
                print_menu();
                scanf("%s", command);
                int index = atoi(command);
                remove_translation(dictionary, &num_pairs, index);
            }
            break;

        case '4':
            list_translations(dictionary, num_pairs);
            break;

        case '5':
            exit(EXIT_SUCCESS);

        default:
            printf("\nInvalid command!\n");
            break;
        }

        system("cls");
    }

    return 0;
}