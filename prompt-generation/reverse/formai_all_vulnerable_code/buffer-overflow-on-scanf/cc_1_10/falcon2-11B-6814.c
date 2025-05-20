//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void create_graph() {
    srand(time(NULL));
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = rand() % 10;
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
    
    for (int i = 0; i < n; i++) {
        int data = rand() % 10;
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = data;
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
        
        struct node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_graph() {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main() {
    create_graph();
    print_graph();
    return 0;
}