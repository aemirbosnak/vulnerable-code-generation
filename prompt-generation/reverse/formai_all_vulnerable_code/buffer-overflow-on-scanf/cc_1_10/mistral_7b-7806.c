//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_LEN 50

typedef struct Word {
    char *word;
    int len;
    struct Word *next;
} Word;

void generate_poem(Word **head, int depth) {
    Word *curr = *head, *prev = NULL, *new;
    int random_num, i;

    if (curr == NULL)
        return;

    if (depth == 0) {
        printf("%s\n", curr->word);
        *head = curr->next;
        free(curr);
        return;
    }

    for (i = 0; i < depth; i++) {
        if (curr->next == NULL) {
            random_num = rand() % (MAX_WORDS - i);
            curr = *head;
            while (random_num--) {
                prev = curr;
                curr = curr->next;
            }
            new = (Word *)malloc(sizeof(Word));
            new->len = curr->len;
            new->word = (char *)malloc((curr->len + 1) * sizeof(char));
            strcpy(new->word, curr->word);
            new->next = curr->next;
            prev->next = new;
        }
        generate_poem(&(curr->next), depth - 1);
        curr = curr->next;
    }
}

int main() {
    srand(time(NULL));
    Word *head = NULL;
    Word *words[MAX_WORDS];
    int i, j, num_words;

    printf("Enter the number of words: ");
    scanf("%d", &num_words);

    for (i = 0; i < num_words; i++) {
        printf("Enter word %d: ", i + 1);
        words[i] = (Word *)malloc(sizeof(Word));
        words[i]->len = 0;
        fgets(words[i]->word, MAX_LEN, stdin);
        words[i]->word[strlen(words[i]->word) - 1] = '\0';
        words[i]->len = strlen(words[i]->word);
        words[i]->next = head;
        head = words[i];
    }

    generate_poem(&head, rand() % 5 + 3);

    for (i = 0; i < num_words; i++) {
        free(words[i]->word);
        free(words[i]);
    }
    free(head);

    return 0;
}