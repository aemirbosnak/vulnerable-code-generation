//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double value;
    struct node* next;
} node;

typedef struct {
    node* head;
} linked_list;

linked_list* create_list() {
    linked_list* list = (linked_list*)malloc(sizeof(linked_list));
    list->head = NULL;
    return list;
}

void add_node(linked_list* list, double value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    if(list->head == NULL) {
        list->head = new_node;
    } else {
        node* temp = list->head;
        while(temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list(linked_list* list) {
    node* temp = list->head;
    while(temp!= NULL) {
        printf("%lf ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    linked_list* list = create_list();
    add_node(list, 1.0);
    add_node(list, 2.0);
    add_node(list, 3.0);
    add_node(list, 4.0);
    add_node(list, 5.0);
    print_list(list);
    return 0;
}