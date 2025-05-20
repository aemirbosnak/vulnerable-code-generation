//FormAI DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define Linked List structure
typedef struct LinkedList {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

// Function to create a new Node
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new Linked List
LinkedList* create_linked_list() {
    LinkedList* new_list = (LinkedList*) malloc(sizeof(LinkedList));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

// Function to insert a Node at the beginning of a Linked List
void insert_node_at_beginning(LinkedList* list, Node* new_node) {
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head = new_node;
    }
    list->size++;
}

// Function to insert a Node at the end of a Linked List
void insert_node_at_end(LinkedList* list, Node* new_node) {
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

// Function to delete a Node from the beginning of a Linked List
void delete_node_from_beginning(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty!\n");
    } else {
        Node* temp = list->head;
        list->head = list->head->next;
        if (list->tail == temp) {
            list->tail = NULL;
        }
        free(temp);
        list->size--;
    }
}

// Function to delete a Node from the end of a Linked List
void delete_node_from_end(LinkedList* list) {
    if (list->tail == NULL) {
        printf("List is empty!\n");
    } else {
        Node* temp = list->head;
        while (temp->next != list->tail) {
            temp = temp->next;
        }
        list->tail = temp;
        free(temp->next);
        temp->next = NULL;
        list->size--;
    }
}

// Driver function to test Linked List operations
int main() {
    LinkedList* list = create_linked_list();
    printf("A neon green linked list flickers to life on your screen...\n");

    printf("You have a choice to add a number to the beginning or end of the list.\n");
    printf("What would you like to do? Press 1 for beginning, 2 for end and 0 to quit.\n");
    int choice;
    scanf("%d", &choice);
    while (choice != 0) {
        if (choice == 1 || choice == 2) {
            printf("What is the data value?\n");
            int data_input;
            scanf("%d", &data_input);
            Node* new_node = create_node(data_input);
            if (choice == 1) {
                insert_node_at_beginning(list, new_node);
                printf("%d has been added to the beginning of the list.\n", data_input);
            } else if (choice == 2) {
                insert_node_at_end(list, new_node);
                printf("%d has been added to the end of the list.\n", data_input);
            }
        } else {
            printf("Invalid choice.\n");
        }
        printf("What would you like to do? Press 1 for beginning, 2 for end and 0 to quit.\n");
        scanf("%d", &choice);
    }
    printf("You have chosen to quit. Here is the final list:\n");

    printf("[");

    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL) {
            printf(", ");
        }
    }

    printf("]\n");

    printf("Now the list disappears into the neon green void...\n");
    return 0;
}