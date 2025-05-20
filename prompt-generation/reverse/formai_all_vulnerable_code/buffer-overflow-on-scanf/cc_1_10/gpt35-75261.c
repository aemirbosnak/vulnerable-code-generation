//FormAI DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

// Structure definition for the linked list node
struct node {
    int data;
    struct node *next;
};

// This function creates a new node and returns it
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// This function inserts a node at the beginning of the linked list
void insert_at_beginning(struct node** head_ref, int data) {
    struct node* new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// This function inserts a node at the end of the linked list
void insert_at_end(struct node** head_ref, int data) {
    struct node* new_node = create_node(data);
    struct node* temp = *head_ref;
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// This function inserts a node at a given position in the linked list
void insert_at_position(struct node** head_ref, int data, int position) {
    struct node* new_node = create_node(data);
    struct node* temp = *head_ref;
    if(position == 1) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    for(int i=1; i<position-1; i++) {
        if(temp->next != NULL) {
            temp = temp->next;
        }
        else {
            printf("Position out of range.\n");
            return;
        }
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// This function deletes a node from the beginning of the linked list
void delete_from_beginning(struct node** head_ref) {
    if(*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

// This function deletes a node from the end of the linked list
void delete_from_end(struct node** head_ref) {
    if(*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = *head_ref;
    struct node* prev = NULL;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if(prev == NULL) {
        *head_ref = NULL;
    }
    else {
        prev->next = NULL;
    }
    free(temp);
}

// This function deletes a node from a given position in the linked list
void delete_from_position(struct node** head_ref, int position) {
    if(*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = *head_ref;
    struct node* prev = NULL;
    if(position == 1) {
        *head_ref = (*head_ref)->next;
        free(temp);
        return;
    }
    for(int i=1; i<position; i++) {
        if(temp == NULL) {
            printf("Position out of range.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

// This function displays the linked list
void display(struct node* head) {
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete from Position\n");
    printf("7. Display List\n");
    printf("8. Exit\n");
    while(1) {
        printf("Enter operation number: ");
        int operation;
        scanf("%d", &operation);
        switch(operation) {
            case 1:
                printf("Enter data to be inserted: ");
                int data1;
                scanf("%d", &data1);
                insert_at_beginning(&head, data1);
                break;
            case 2:
                printf("Enter data to be inserted: ");
                int data2;
                scanf("%d", &data2);
                insert_at_end(&head, data2);
                break;
            case 3:
                printf("Enter position at which data is to be inserted: ");
                int position, data3;
                scanf("%d", &position);
                printf("Enter data to be inserted: ");
                scanf("%d", &data3);
                insert_at_position(&head, data3, position);
                break;
            case 4:
                delete_from_beginning(&head);
                break;
            case 5:
                delete_from_end(&head);
                break;
            case 6:
                printf("Enter position at which data is to be deleted: ");
                int position2;
                scanf("%d", &position2);
                delete_from_position(&head, position2);
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid operation number.\n");
        }
    }
    return 0;
}