//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[20];
    struct node *next;
};

struct node *head = NULL;

void addNode(char data[]) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList() {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    char data[20];
    while (1) {
        printf("Enter the data: ");
        scanf("%s", data);

        addNode(data);
        printf("Do you want to add another data (y/n)? ");
        char ans;
        scanf(" %c", &ans);
        if (ans == 'n') {
            break;
        }
    }

    displayList();
    return 0;
}