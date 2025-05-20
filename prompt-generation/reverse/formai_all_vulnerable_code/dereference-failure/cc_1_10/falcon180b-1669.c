//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

struct Node {
    char data[MAX_SIZE];
    int freq;
    struct Node* next;
};

struct Node* createNode(char data[], int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->freq = freq;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, char data[], int freq) {
    struct Node* newNode = createNode(data, freq);
    struct Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%s %d\n", temp->data, temp->freq);
        temp = temp->next;
    }
}

void search(struct Node* head, char data[]) {
    struct Node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            printf("Found %s with frequency %d\n", temp->data, temp->freq);
            return;
        }
        temp = temp->next;
    }
    printf("Not found\n");
}

int main() {
    struct Node* head = NULL;
    char data[MAX_SIZE];
    int freq;
    printf("Enter words to be inserted\n");
    while (scanf("%s", data)!= EOF) {
        printf("Enter frequency\n");
        scanf("%d", &freq);
        insert(&head, data, freq);
    }
    printf("Enter word to search\n");
    scanf("%s", data);
    search(head, data);
    display(head);
    return 0;
}