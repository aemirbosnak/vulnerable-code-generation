//Falcon-180B DATASET v1.0 Category: Data mining ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    char *word;
    int count;
    struct node *next;
};

struct node *newNode(char *word) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->word = strdup(word);
    newnode->count = 1;
    newnode->next = NULL;
    return newnode;
}

void addWord(struct node **head, char *word) {
    struct node *newnode = *head;
    while (newnode!= NULL) {
        if (strcmp(newnode->word, word) == 0) {
            newnode->count++;
            return;
        }
        newnode = newnode->next;
    }
    newnode = newNode(word);
    newnode->next = *head;
    *head = newnode;
}

void printList(struct node *node) {
    while (node!= NULL) {
        printf("%s: %d\n", node->word, node->count);
        node = node->next;
    }
}

int main() {
    char input[1000];
    char word[100];
    FILE *file;
    struct node *head = NULL;

    printf("Enter the name of the file: ");
    scanf("%s", input);

    file = fopen(input, "r");
    if (file == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        addWord(&head, word);
    }

    fclose(file);

    printf("Word count:\n");
    printList(head);

    return 0;
}