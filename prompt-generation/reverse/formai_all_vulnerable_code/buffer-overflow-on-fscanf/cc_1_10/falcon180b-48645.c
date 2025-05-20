//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char word[100];
    int frequency;
    struct node *next;
} Node;

Node *createNode(char word[], int frequency) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->frequency = frequency;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node *head, char word[], int frequency) {
    Node *newNode = createNode(word, frequency);
    Node *current = head;
    while (current->next!= NULL && strcmp(current->next->word, word)!= 0) {
        current = current->next;
    }
    if (current->next == NULL) {
        current->next = newNode;
    } else {
        current->next->frequency += frequency;
    }
}

void printList(Node *head) {
    Node *current = head;
    while (current!= NULL) {
        printf("%s - %d\n", current->word, current->frequency);
        current = current->next;
    }
}

int main() {
    FILE *file;
    char word[100];
    int frequency = 1;
    Node *head = NULL;
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    while (fscanf(file, "%s", word)!= EOF) {
        if (isalpha(word[0])) {
            word[strcspn(word, ".,?!;:\"'")] = '\0'; // Remove punctuation from end of word
            char *p = word;
            while (*p!= '\0') {
                *p = tolower(*p);
                p++;
            }
            insertNode(head, word, frequency);
        }
    }
    fclose(file);
    printList(head);
    return 0;
}