//FormAI DATASET v1.0 Category: Linked list operations ; Style: curious
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef NODE *LINK;

LINK create_list();
void add_node(LINK);
void delete_node(LINK, int);
void display_list(LINK);

int main() {
    LINK head, tail;
    head = tail = NULL;
    int choice, value, position;

    do {
        printf("\n===============\n");
        printf(" Linked List Menu");
        printf("\n===============\n");
        printf("1. Create List\n");
        printf("2. Add Node\n");
        printf("3. Delete Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: head = create_list();
                    tail = head;
                    break;

            case 2: add_node(tail);
                    tail = tail->next;
                    break;

            case 3: printf("\nEnter the position of the node to delete: ");
                    scanf("%d", &position);
                    delete_node(head, position);
                    break;

            case 4: display_list(head);
                    break;

            case 5: printf("\nExiting program...");
                    exit(0);
                    break;

            default: printf("\nInvalid choice, try again.");
                     break;
        }

    } while(1);

    return 0;
}

LINK create_list() {
    LINK head, node, tail;
    int num_nodes, value, i;

    printf("\nEnter the number of nodes to create: ");
    scanf("%d", &num_nodes);
    head = NULL;

    for(i=0; i<num_nodes; i++) {
        node = (NODE*) malloc(sizeof(NODE));

        if(node == NULL) {
            printf("\nMemory allocation failed, exiting program...");
            exit(0);
        }

        printf("\nEnter the value for node %d: ", i+1);
        scanf("%d", &value);

        node->data = value;
        node->next = NULL;

        if(head == NULL) {
            head = node;
            tail = node;
        }

        else {
            tail->next = node;
            tail = node;
        }
    }

    printf("\nList created successfully!");

    return head;
}

void add_node(LINK tail) {
    NODE *new_node;
    int value;

    new_node = (NODE*) malloc(sizeof(NODE));

    if(new_node == NULL) {
        printf("\nMemory allocation failed, exiting program...");
        exit(0);
    }

    printf("\nEnter the value for the new node: ");
    scanf("%d", &value);

    new_node->data = value;
    new_node->next = NULL;
    tail->next = new_node;

    printf("\nNode added successfully!");
}

void delete_node(LINK head, int position) {
    NODE *temp, *prev;
    int i;

    temp = head;

    if(position == 1) {
        head = temp->next;
        free(temp);
        printf("\nNode at position %d deleted successfully!", position);
        return;
    }

    for(i=1; i<position; i++) {
        prev = temp;
        temp = temp->next;

        if(temp == NULL) {
            printf("\nInvalid position, node not found!");
            return;
        }
    }

    prev->next = temp->next;
    free(temp);

    printf("\nNode at position %d deleted successfully!", position);
}

void display_list(LINK head) {
    NODE *temp;
    temp = head;

    if(temp == NULL) {
        printf("\nList is empty!");
        return;
    }

    printf("\nLinked List Values:");

    while(temp != NULL) {
       printf("\n%d",temp->data);
       temp = temp->next;
    }
}