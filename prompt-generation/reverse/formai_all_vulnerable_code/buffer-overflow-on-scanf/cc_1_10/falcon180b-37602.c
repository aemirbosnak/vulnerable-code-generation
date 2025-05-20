//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char data[50];
    int count;
    struct node* next;
};

void insert(struct node** head, char* word) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->data, word);
    new_node->count = 1;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%s %d\n", temp->data, temp->count);
        temp = temp->next;
    }
}

void search(struct node* head, char* word) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, word) == 0) {
            printf("%s found %d times\n", word, temp->count);
            return;
        }
        temp = temp->next;
    }
    printf("%s not found\n", word);
}

int main() {
    struct node* head = NULL;
    char word[50];

    int choice, i;

    do {
        printf("\n1. Insert\n2. Display\n3. Search\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter word: ");
                scanf("%s", word);
                insert(&head, word);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter word to search: ");
                scanf("%s", word);
                search(head, word);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}