//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Node {
    char data[MAX_SIZE];
    int freq;
    struct Node* next;
};

struct Node* createNode(char str[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, str);
    newNode->freq = 1;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, char str[]) {
    struct Node* newNode = *head;
    while (newNode!= NULL && strcmp(newNode->data, str)!= 0) {
        newNode = newNode->next;
    }
    if (newNode == NULL) {
        newNode = createNode(str);
        newNode->next = *head;
        *head = newNode;
    } else {
        newNode->freq++;
    }
}

void display(struct Node* head) {
    while (head!= NULL) {
        printf("%s %d\n", head->data, head->freq);
        head = head->next;
    }
}

void search(struct Node* head, char str[]) {
    struct Node* curr = head;
    while (curr!= NULL) {
        if (strcmp(curr->data, str) == 0) {
            printf("Found %s with frequency %d\n", curr->data, curr->freq);
            break;
        }
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Not found\n");
    }
}

int main() {
    struct Node* head = NULL;
    char str[MAX_SIZE];

    printf("Enter strings to be inserted:\n");
    while (scanf("%s", str)!= EOF) {
        insert(&head, str);
    }

    printf("Displaying the list:\n");
    display(head);

    printf("Enter string to search:\n");
    scanf("%s", str);
    search(head, str);

    return 0;
}