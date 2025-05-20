//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char word[50];
    struct Node* next;
} Node;

Node* create_node(char* word) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->next = NULL;
    return new_node;
}

void print_list(Node* head) {
    while (head!= NULL) {
        printf("%s\n", head->word);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    char word1[50], word2[50];

    printf("Enter the first word: ");
    scanf("%s", word1);
    printf("Enter the second word: ");
    scanf("%s", word2);

    Node* node1 = create_node(word1);
    Node* node2 = create_node(word2);

    if (strcmp(word1, word2) == 0) {
        printf("The words are identical.\n");
        return 0;
    }

    if (strcmp(word1, word2) < 0) {
        node1->next = node2;
    } else {
        node2->next = node1;
    }

    head = node1;

    while (head!= NULL) {
        head = head->next;
    }

    print_list(head);

    return 0;
}