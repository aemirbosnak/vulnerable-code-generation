//FormAI DATASET v1.0 Category: Data recovery tool ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 10000

typedef struct node{
    int data;
    struct node* next;
}Node;

void insert(Node **head_ref, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node *prev = *head_ref;
    new_node->data = data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (prev->next != NULL) {
        prev = prev->next;
    }
    prev->next = new_node;
}

void display(Node* head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void recover_data(Node* crashed_data_head, Node* original_data_head) {
    Node* crashed_temp = crashed_data_head;
    while (crashed_temp != NULL) {
        if (!search(original_data_head, crashed_temp->data)) {
            insert(&original_data_head, crashed_temp->data);
        }
        crashed_temp = crashed_temp->next;
    }
    printf("\nRecovered Data\n");
    display(original_data_head);
}

int main() {
    Node* original_data_head = NULL;
    Node* crashed_data_head = NULL;
    printf("Enter original data - Enter 0 to stop:\n");
    while (true) {
        int temp;
        scanf("%d", &temp);
        if (temp == 0) {
            break;
        }
        insert(&original_data_head, temp);
    }
    printf("\nEnter crashed data - Enter 0 to stop:\n");
    while (true) {
        int temp;
        scanf("%d", &temp);
        if (temp == 0) {
            break;
        }
        insert(&crashed_data_head, temp);
    }
    printf("\nOriginal Data\n");
    display(original_data_head);
    printf("\nCrashed Data\n");
    display(crashed_data_head);
    recover_data(crashed_data_head, original_data_head);

    return 0;
}