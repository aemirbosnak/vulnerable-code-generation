//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGGAGE 100

typedef struct {
    char destination[20];
    int weight;
} baggage;

typedef struct node {
    baggage data;
    struct node *next;
} node;

node *head = NULL;

void addBaggage(baggage newBaggage) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = newBaggage;
    newNode->next = head;
    head = newNode;
}

void displayList() {
    node *currentNode = head;
    printf("\nBaggage List:\n");
    while (currentNode != NULL) {
        printf("Destination: %s, Weight: %d kg\n", currentNode->data.destination, currentNode->data.weight);
        currentNode = currentNode->next;
    }
}

int main() {
    int i;
    char destination[MAX_BAGGAGE][20];
    int weight[MAX_BAGGAGE];

    printf("Enter baggage information (destination and weight, separated by space, 'q' to quit):\n");

    for (i = 0; i < MAX_BAGGAGE;) {
        scanf("%s %d", destination[i], &weight[i]);

        if (strcmp(destination[i], "q") == 0) {
            break;
        }

        baggage newBaggage = {destination[i], weight[i]};
        addBaggage(newBaggage);
        i++;
    }

    displayList();

    return 0;
}