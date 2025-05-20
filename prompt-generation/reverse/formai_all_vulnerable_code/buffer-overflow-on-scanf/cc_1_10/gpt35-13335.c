//FormAI DATASET v1.0 Category: Spell checking ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

char* word_list[MAX_WORDS];
int num_words = 0;

/* Hash function used to determine hash value of a word */
unsigned int hash_word(const char* word) {
    unsigned int hash = 0;
    for(int i = 0; i < strlen(word); i++) {
        hash += tolower(word[i]) * (i + 1);
    }
    return hash;
}

/* Function used to check if a word is already in the word list */
int is_word_in_list(const char* word) {
    unsigned int hash = hash_word(word);
    for(int i = 0; i < num_words; i++) {
        if(hash == word_list[i][0] && strcmp(word_list[i] + 1, word) == 0) {
            return 1;
        }
    }
    return 0;
}

/* Function used to add a word to the word list */
void add_word_to_list(const char* word) {
    if(num_words >= MAX_WORDS) {
        printf("Error: Maximum number of words exceeded\n");
    } else if(is_word_in_list(word)) {
        printf("%s is already in the word list\n", word);
    } else {
        unsigned int hash = hash_word(word);
        char* new_word = malloc(sizeof(char) * (MAX_WORD_LEN + 1));
        new_word[0] = hash;
        strcpy(new_word + 1, word);
        word_list[num_words] = new_word;
        num_words++;
        printf("%s added to the word list\n", word);
    }
}

/* Function used to remove a word from the word list */
void remove_word_from_list(const char* word) {
    unsigned int hash = hash_word(word);
    for(int i = 0; i < num_words; i++) {
        if(hash == word_list[i][0] && strcmp(word_list[i] + 1, word) == 0) {
            free(word_list[i]);
            for(int j = i; j < num_words - 1; j++) {
                word_list[j] = word_list[j + 1];
            }
            num_words--;
            printf("%s removed from the word list\n", word);
            return;
        }
    }
    printf("%s is not in the word list\n", word);
}

/* Function used to check if a word is spelled correctly */
int is_word_spelled_correctly(const char* word) {
    unsigned int hash = hash_word(word);
    for(int i = 0; i < num_words; i++) {
        if(hash == word_list[i][0] && strcmp(word_list[i] + 1, word) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char command[MAX_WORD_LEN + 1] = "";
    while(strcmp(command, "exit") != 0) {
        printf("Enter a command (add, remove, check, exit): ");
        scanf("%s", command);
        if(strcmp(command, "add") == 0) {
            char word[MAX_WORD_LEN + 1] = "";
            printf("Enter a word to add to the spell checker: ");
            scanf("%s", word);
            add_word_to_list(word);
        } else if(strcmp(command, "remove") == 0) {
            char word[MAX_WORD_LEN + 1] = "";
            printf("Enter a word to remove from the spell checker: ");
            scanf("%s", word);
            remove_word_from_list(word);
        } else if(strcmp(command, "check") == 0) {
            char word[MAX_WORD_LEN + 1] = "";
            printf("Enter a word to check the spelling of: ");
            scanf("%s", word);
            printf("%s\n", is_word_spelled_correctly(word) ? "Correct" : "Incorrect");
        } else if(strcmp(command, "exit") != 0) {
            printf("Invalid command\n");
        }
    }
    return 0;
}