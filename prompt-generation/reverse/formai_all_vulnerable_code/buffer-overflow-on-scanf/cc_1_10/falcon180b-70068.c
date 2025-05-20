//Falcon-180B DATASET v1.0 Category: Memory management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    struct node* next;
} node;

int main() {
    node* head = NULL;
    node* tail = NULL;
    node* new_node = NULL;
    int value;

    while(1) {
        printf("Enter a value to add to the list (or 0 to exit): ");
        scanf("%d", &value);

        if(value == 0) {
            break;
        }

        new_node = (node*) malloc(sizeof(node));
        if(new_node == NULL) {
            printf("Error: could not allocate memory for new node\n");
            exit(1);
        }

        new_node->value = value;
        new_node->next = NULL;

        if(head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    printf("The list contains the following values:\n");
    node* current = head;
    while(current!= NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");

    while(head!= NULL) {
        new_node = head;
        head = head->next;
        free(new_node);
    }

    return 0;
}