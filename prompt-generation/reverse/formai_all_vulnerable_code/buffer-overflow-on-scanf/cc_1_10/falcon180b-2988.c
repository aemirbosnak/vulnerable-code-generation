//Falcon-180B DATASET v1.0 Category: Memory management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node* next;
};

void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return ptr;
}

void my_free(void* ptr) {
    free(ptr);
}

int main() {
    struct node* head = NULL;
    char input[10];

    while (1) {
        printf("Enter the data to be inserted (enter 'q' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break;
        }

        struct node* new_node = (struct node*) my_malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        new_node->data = atoi(input);
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            struct node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    printf("Linked list:\n");
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("Freeing memory...\n");
    temp = head;
    while (temp!= NULL) {
        struct node* next = temp->next;
        my_free(temp);
        temp = next;
    }

    return 0;
}