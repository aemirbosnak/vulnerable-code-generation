//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    struct node *next;
} node;

node *dict;

int main() {
    char word[101];
    int i, j, k, n, found;

    // Build the dictionary
    dict = NULL;
    FILE *fp = fopen("dictionary.txt", "r");
    while (fscanf(fp, "%s", word) != EOF) {
        node *new_node = malloc(sizeof(node));
        new_node->word = strdup(word);
        new_node->next = dict;
        dict = new_node;
    }
    fclose(fp);

    // Get the user's input
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the word against the dictionary
    found = 0;
    for (i = 0; i < strlen(word); i++) {
        for (j = i + 1; j < strlen(word); j++) {
            for (k = j + 1; k < strlen(word); k++) {
                char temp = word[i];
                word[i] = word[j];
                word[j] = word[k];
                word[k] = temp;

                for (node *ptr = dict; ptr != NULL; ptr = ptr->next) {
                    if (strcmp(word, ptr->word) == 0) {
                        printf("%s is a word!\n", word);
                        found = 1;
                        break;
                    }
                }

                temp = word[i];
                word[i] = word[j];
                word[j] = word[k];
                word[k] = temp;
            }
        }
    }

    if (!found) {
        printf("%s is not a word!\n", word);
    }

    return 0;
}