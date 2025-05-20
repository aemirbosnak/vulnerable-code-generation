//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_DNA_LENGTH 100
#define MAX_CYCLES 1000

struct Node {
    char dna[MAX_DNA_LENGTH];
    int cycle;
    bool visited;
    struct Node* next;
};

void generateDNA(char* dna, int length) {
    for (int i = 0; i < length; i++) {
        char randChar = 'A' + rand() % 4;
        dna[i] = randChar;
    }
    dna[length - 1] = '\0';
}

void printDNA(char* dna) {
    printf("%s\n", dna);
}

void addNode(struct Node** head, char* dna) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->dna, dna);
    newNode->cycle = 0;
    newNode->visited = false;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void dfs(struct Node* node) {
    printf("Visiting node: %s\n", node->dna);
    node->visited = true;

    if (node->cycle == MAX_CYCLES) {
        printf("Node %s reached maximum cycles.\n", node->dna);
        return;
    }

    node->cycle++;

    struct Node* temp = node->next;
    while (temp!= NULL) {
        if (!temp->visited) {
            dfs(temp);
        }
        temp = temp->next;
    }
}

int main() {
    srand(time(NULL));

    struct Node* head = NULL;

    for (int i = 0; i < MAX_NODES; i++) {
        char dna[MAX_DNA_LENGTH];
        generateDNA(dna, rand() % MAX_DNA_LENGTH + 1);
        addNode(&head, dna);
    }

    dfs(head);

    return 0;
}