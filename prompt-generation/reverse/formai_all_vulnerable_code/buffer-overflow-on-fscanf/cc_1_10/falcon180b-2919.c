//Falcon-180B DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void add_node(Node** head, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void write_to_file(Node* head, FILE* fp) {
    if (head == NULL) {
        fprintf(fp, "NULL\n");
        return;
    }
    fprintf(fp, "%d ", head->data);
    write_to_file(head->next, fp);
}

Node* read_from_file(FILE* fp) {
    int data;
    fscanf(fp, "%d", &data);
    Node* head = (Node*) malloc(sizeof(Node));
    head->data = data;
    head->next = NULL;
    return head;
}

void sort_list(Node** head) {
    Node* curr = *head;
    Node* prev = NULL;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = NULL;
        if (prev == NULL || curr->data < prev->data) {
            curr->next = prev;
            prev = curr;
        } else {
            Node* temp = prev;
            while (temp->next!= NULL && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }
    *head = prev;
}

int main() {
    FILE* fp = fopen("data.txt", "w");
    Node* head = NULL;
    add_node(&head, 5);
    add_node(&head, 3);
    add_node(&head, 7);
    add_node(&head, 1);
    add_node(&head, 9);
    print_list(head);
    write_to_file(head, fp);
    fclose(fp);

    fp = fopen("data.txt", "r");
    head = read_from_file(fp);
    print_list(head);
    sort_list(&head);
    print_list(head);
    fclose(fp);

    return 0;
}