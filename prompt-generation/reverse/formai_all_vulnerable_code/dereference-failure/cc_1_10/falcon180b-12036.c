//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000
#define MAX_WORDS 10000

typedef struct node {
    char *word;
    struct node *next;
} Node;

Node *hash_table[MAX_SIZE];
int num_words = 0;

unsigned int hash(char *word) {
    unsigned int sum = 0;
    while (*word!= '\0') {
        sum += *word;
        word++;
    }
    return sum % MAX_SIZE;
}

void insert(char *word) {
    unsigned int index = hash(word);
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->word = strdup(word);
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
    num_words++;
}

int search(char *word) {
    unsigned int index = hash(word);
    Node *current = hash_table[index];
    while (current!= NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void delete_all() {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        Node *current = hash_table[i];
        while (current!= NULL) {
            Node *temp = current;
            current = current->next;
            free(temp->word);
            free(temp);
        }
    }
    num_words = 0;
}

int main() {
    int choice, i;
    char word[100];

    srand(time(NULL));

    for (i = 0; i < MAX_WORDS; i++) {
        sprintf(word, "word_%d", i);
        insert(word);
    }

    while (1) {
        printf("1. Insert a word\n2. Search for a word\n3. Delete all words\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a word: ");
                scanf("%s", word);
                insert(word);
                break;
            case 2:
                printf("Enter a word: ");
                scanf("%s", word);
                if (search(word)) {
                    printf("Word found\n");
                } else {
                    printf("Word not found\n");
                }
                break;
            case 3:
                delete_all();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}