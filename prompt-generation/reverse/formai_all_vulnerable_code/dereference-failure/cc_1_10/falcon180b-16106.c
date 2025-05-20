//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double value;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
    int size;
} list;

list* create_list() {
    list* l = (list*)malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

void add_node(list* l, double value) {
    node* n = (node*)malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    if (l->head == NULL) {
        l->head = n;
        l->tail = n;
    } else {
        l->tail->next = n;
        l->tail = n;
    }
    l->size++;
}

void print_list(list* l) {
    node* n = l->head;
    while (n!= NULL) {
        printf("%lf ", n->value);
        n = n->next;
    }
    printf("\n");
}

void free_list(list* l) {
    node* n = l->head;
    while (n!= NULL) {
        node* temp = n;
        n = n->next;
        free(temp);
    }
    free(l);
}

list* multiply_lists(list* a, list* b) {
    list* result = create_list();
    node* n1 = a->head;
    node* n2 = b->head;
    while (n1!= NULL && n2!= NULL) {
        add_node(result, n1->value * n2->value);
        n1 = n1->next;
        n2 = n2->next;
    }
    while (n1!= NULL) {
        add_node(result, n1->value * 0.0);
        n1 = n1->next;
    }
    while (n2!= NULL) {
        add_node(result, n2->value * 0.0);
        n2 = n2->next;
    }
    return result;
}

int main() {
    list* a = create_list();
    list* b = create_list();
    add_node(a, 1.0);
    add_node(a, 2.0);
    add_node(a, 3.0);
    add_node(b, 4.0);
    add_node(b, 5.0);
    add_node(b, 6.0);
    list* result = multiply_lists(a, b);
    print_list(result);
    free_list(a);
    free_list(b);
    free_list(result);
    return 0;
}