//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

typedef struct node {
    char *word;
    struct node *left;
    struct node *right;
} node_t;

node_t *root = NULL;

void insert(char *word) {
    node_t *p = root;
    node_t *parent = NULL;
    int cmp;

    while (p) {
        cmp = strcmp(word, p->word);
        parent = p;

        if (cmp < 0) {
            p = p->left;
        } else if (cmp > 0) {
            p = p->right;
        } else {
            return;
        }
    }

    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = strdup(word);
    new_node->left = NULL;
    new_node->right = NULL;

    if (parent) {
        if (cmp < 0) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    } else {
        root = new_node;
    }
}

int search(char *word) {
    node_t *p = root;
    int cmp;

    while (p) {
        cmp = strcmp(word, p->word);

        if (cmp < 0) {
            p = p->left;
        } else if (cmp > 0) {
            p = p->right;
        } else {
            return 1;
        }
    }

    return 0;
}

void load_dictionary(char *filename) {
    FILE *f = fopen(filename, "r");
    char buf[BUFSIZE];

    if (!f) {
        perror("fopen");
        exit(1);
    }

    while (fgets(buf, BUFSIZE, f)) {
        buf[strlen(buf) - 1] = '\0';
        insert(buf);
    }

    fclose(f);
}

void spell_check(char *word) {
    if (!search(word)) {
        printf("%s is not in the dictionary.\n", word);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s dictionary.txt\n", argv[0]);
        exit(1);
    }

    load_dictionary(argv[1]);
    spell_check("hello");
    spell_check("world");
    spell_check("misspell");

    return 0;
}