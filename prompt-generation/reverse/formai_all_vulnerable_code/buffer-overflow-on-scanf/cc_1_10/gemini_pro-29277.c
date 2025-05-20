//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_CHARS 1024
#define MAX_WORDS 1024

struct word {
    char *word;
    struct word *next;
};

struct trie {
    struct word *head;
    struct trie *children[26];
};

struct trie *create_trie() {
    struct trie *t = malloc(sizeof(struct trie));
    if (!t) {
        return NULL;
    }

    t->head = NULL;
    for (int i = 0; i < 26; i++) {
        t->children[i] = NULL;
    }

    return t;
}

void free_trie(struct trie *t) {
    if (!t) {
        return;
    }

    struct word *w = t->head;
    while (w) {
        struct word *next = w->next;
        free(w->word);
        free(w);
        w = next;
    }

    for (int i = 0; i < 26; i++) {
        free_trie(t->children[i]);
    }

    free(t);
}

bool insert_word(struct trie *t, char *word) {
    if (!t || !word) {
        return false;
    }

    int len = strlen(word);
    struct trie *curr = t;
    for (int i = 0; i < len; i++) {
        int idx = tolower(word[i]) - 'a';
        if (!curr->children[idx]) {
            curr->children[idx] = create_trie();
        }
        curr = curr->children[idx];
    }

    if (curr->head) {
        return false;
    }

    struct word *w = malloc(sizeof(struct word));
    if (!w) {
        return false;
    }

    w->word = strdup(word);
    w->next = curr->head;
    curr->head = w;

    return true;
}

bool check_spelling(struct trie *t, char *word) {
    if (!t || !word) {
        return false;
    }

    int len = strlen(word);
    struct trie *curr = t;
    for (int i = 0; i < len; i++) {
        int idx = tolower(word[i]) - 'a';
        if (!curr->children[idx]) {
            return false;
        }
        curr = curr->children[idx];
    }

    return true;
}

void suggest_corrections(struct trie *t, char *word, char ***suggestions, int *num_suggestions) {
    if (!t || !word || !suggestions || !num_suggestions) {
        return;
    }

    int len = strlen(word);
    struct trie *curr = t;
    for (int i = 0; i < len; i++) {
        int idx = tolower(word[i]) - 'a';
        if (!curr->children[idx]) {
            return;
        }
        curr = curr->children[idx];
    }

    struct word *w = curr->head;
    while (w) {
        *suggestions = realloc(*suggestions, (*num_suggestions + 1) * sizeof(char *));
        (*suggestions)[*num_suggestions] = strdup(w->word);
        (*num_suggestions)++;
        w = w->next;
    }

    for (int i = 0; i < 26; i++) {
        if (curr->children[i]) {
            char new_word[len + 2];
            strcpy(new_word, word);
            new_word[len] = tolower('a') + i;
            new_word[len + 1] = '\0';
            suggest_corrections(t, new_word, suggestions, num_suggestions);
        }
    }
}

int main() {
    // Create a trie to store the dictionary
    struct trie *t = create_trie();

    // Load the dictionary into the trie
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp) {
        char line[MAX_CHARS];
        while (fgets(line, MAX_CHARS, fp)) {
            char *word = strtok(line, "\n");
            if (word) {
                insert_word(t, word);
            }
        }
        fclose(fp);
    }

    // Get the user input
    char input[MAX_CHARS];
    printf("Enter a word to check: ");
    scanf("%s", input);

    // Check the spelling of the user input
    if (check_spelling(t, input)) {
        printf("The spelling of '%s' is correct.\n", input);
    } else {
        printf("The spelling of '%s' is incorrect.\n", input);

        // Suggest corrections for the user input
        char **suggestions = NULL;
        int num_suggestions = 0;
        suggest_corrections(t, input, &suggestions, &num_suggestions);

        if (num_suggestions == 0) {
            printf("No suggestions found.\n");
        } else {
            printf("Suggested corrections:\n");
            for (int i = 0; i < num_suggestions; i++) {
                printf(" - %s\n", suggestions[i]);
                free(suggestions[i]);
            }
            free(suggestions);
        }
    }

    // Free the trie
    free_trie(t);

    return 0;
}