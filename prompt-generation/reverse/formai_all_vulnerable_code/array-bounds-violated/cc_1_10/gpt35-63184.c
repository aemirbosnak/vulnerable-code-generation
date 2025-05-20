//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_VOCAB_SIZE 100
#define MAX_TRANSLATION_SIZE 50

typedef struct vocab {
    char c_word[MAX_WORD_LENGTH];
    int c_word_id;
} vocab;

typedef struct translation {
    char c_word[MAX_WORD_LENGTH];
    int c_trans_id;
} translation;

vocab c_vocab[MAX_VOCAB_SIZE];
translation c_translation[MAX_TRANSLATION_SIZE];
int available_vocab_slots[MAX_VOCAB_SIZE];
int available_translation_slots[MAX_TRANSLATION_SIZE];
int vocab_count = 0;
int trans_count = 0;
int available_vocab_count = MAX_VOCAB_SIZE;
int available_trans_count = MAX_TRANSLATION_SIZE;

int generate_random_id(int max_val) {
    return rand() % max_val + 1;
}

int check_word(char word[]) {
    int i;
    for(i = 0; i < vocab_count; i++) {
        if(strcmp(c_vocab[i].c_word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int add_word(char word[]) {
    int word_id = check_word(word);
    if(word_id != -1) {
        return word_id;
    } else {
        if(available_vocab_count == 0) {
            return -1;
        } else {
            vocab new_vocab = { .c_word_id = generate_random_id(MAX_VOCAB_SIZE), .c_word = "" };
            strncpy(new_vocab.c_word, word, MAX_WORD_LENGTH);
            c_vocab[vocab_count] = new_vocab;
            available_vocab_slots[vocab_count] = new_vocab.c_word_id;
            available_vocab_count--;
            vocab_count++;
            return new_vocab.c_word_id;
        }
    }
}

int check_translation(char trans[]) {
    int i;
    for(i = 0; i < trans_count; i++) {
        if(strcmp(c_translation[i].c_word, trans) == 0) {
            return i;
        }
    }
    return -1;
}

int add_translation(char trans[]) {
    int trans_id = check_translation(trans);
    if(trans_id != -1) {
        return trans_id;
    } else {
        if(available_trans_count == 0) {
            return -1;
        } else {
            translation new_translation = { .c_trans_id = generate_random_id(MAX_TRANSLATION_SIZE), .c_word = "" };
            strncpy(new_translation.c_word, trans, MAX_WORD_LENGTH);
            c_translation[trans_count] = new_translation;
            available_translation_slots[trans_count] = new_translation.c_trans_id;
            available_trans_count--;
            trans_count++;
            return new_translation.c_trans_id;
        }
    }
}

void add_word_translation_pair(int word_id, int trans_id) {
    printf("Word with ID: %d and Translation with ID: %d have been added to the translator.\n", word_id, trans_id);
}

void perform_translation(char word[]) {
    int word_id = check_word(word);
    if(word_id == -1) {
        printf("Word not found in translator.\n");
        return;
    }
    vocab target_word = c_vocab[word_id];
    int trans_id = check_translation(target_word.c_word);
    if(trans_id == -1) {
        printf("Translation for '%s' not found in translator.\n", target_word.c_word);
        return;
    }
    translation target_trans = c_translation[trans_id];
    printf("'%s' in alien language translates to '%s'.\n", target_word.c_word, target_trans.c_word);
}

void print_available_vocab_slots() {
    int i;
    for(i = 0; i < vocab_count; i++) {
        if(available_vocab_slots[i] != -1) {
            printf("Available Vocab Slot: %d\n", available_vocab_slots[i]);
        }
    }

}

void print_available_translation_slots() {
    int i;
    for(i = 0; i < trans_count; i++) {
        if(available_translation_slots[i] != -1) {
            printf("Available Translation Slot: %d\n", available_translation_slots[i]);
        }
    }
}

void print_vocabulary() {
    int i;
    printf("Vocabulary:\n");
    for(i = 0; i < vocab_count; i++) {
        printf("Word[%d]: %s\n", c_vocab[i].c_word_id, c_vocab[i].c_word);
    }
}

void print_translations() {
    int i;
    printf("Translations:\n");
    for(i = 0; i < trans_count; i++) {
        printf("Translation[%d]: %s\n", c_translation[i].c_trans_id, c_translation[i].c_word);
    }
}

int main() {
    srand(time(NULL));
    char input[MAX_WORD_LENGTH];
    int input_word_id, input_trans_id;

    printf("Welcome to the C Alien Language Translator!\n");

    while(1) {
        printf("\nEnter a command (add_word / add_translation / add_pair / translate / exit): ");
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strlen(input) - 1] = '\0';

        if(strcmp(input, "add_word") == 0) {
            printf("Enter a word to add to the translator: ");
            fgets(input, MAX_WORD_LENGTH, stdin);
            input[strlen(input) - 1] = '\0';

            input_word_id = add_word(input);

            if(input_word_id == -1) {
                printf("No available vocabulary slots remaining.\n");
            } else {
                printf("'%s' has been added to the translator with ID: %d.\n", input, input_word_id);
            }
        }

        if(strcmp(input, "add_translation") == 0) {
            printf("Enter a translation to add to the translator: ");
            fgets(input, MAX_WORD_LENGTH, stdin);
            input[strlen(input) - 1] = '\0';

            input_trans_id = add_translation(input);

            if(input_trans_id == -1) {
                printf("No available translation slots remaining.\n");
            } else {
                printf("'%s' has been added to the translator with ID: %d.\n", input, input_trans_id);
            }
        }

        if(strcmp(input, "add_pair") == 0) {
            printf("Enter a word to add to the translator: ");
            fgets(input, MAX_WORD_LENGTH, stdin);
            input[strlen(input) - 1] = '\0';

            input_word_id = add_word(input);

            if(input_word_id == -1) {
                printf("No available vocabulary slots remaining.\n");
            } else {
                printf("'%s' has been added to the translator with ID: %d.\n", input, input_word_id);
                printf("Enter a translation to add to the translator: ");
                fgets(input, MAX_WORD_LENGTH, stdin);
                input[strlen(input) - 1] = '\0';

                input_trans_id = add_translation(input);

                if(input_trans_id == -1) {
                    printf("No available translation slots remaining.\n");
                } else {
                    printf("'%s' has been added to the translator with ID: %d.\n", input, input_trans_id);
                    add_word_translation_pair(input_word_id, input_trans_id);
                }
            }
        }

        if(strcmp(input, "translate") == 0) {
            printf("Enter a word to translate from alien language: ");
            fgets(input, MAX_WORD_LENGTH, stdin);
            input[strlen(input) - 1] = '\0';

            perform_translation(input);
        }

        if(strcmp(input, "exit") == 0) {
            printf("\nExiting C Alien Language Translator...\n");
            break;
        }
    }

    return 0;
}