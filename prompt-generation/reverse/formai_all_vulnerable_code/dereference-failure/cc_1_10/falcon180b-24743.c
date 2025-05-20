//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define TOLERANCE 1e-6

typedef struct {
    double value;
    struct node* next;
} node;

typedef struct {
    node* head;
    int size;
} linked_list;

linked_list* create_list() {
    linked_list* l = (linked_list*)malloc(sizeof(linked_list));
    l->head = NULL;
    l->size = 0;
    return l;
}

void add_node(linked_list* l, double value) {
    node* n = (node*)malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    if (l->head == NULL) {
        l->head = n;
    } else {
        node* last = l->head;
        while (last->next!= NULL) {
            last = last->next;
        }
        last->next = n;
    }
    l->size++;
}

void print_list(linked_list* l) {
    node* n = l->head;
    while (n!= NULL) {
        printf("%lf ", n->value);
        n = n->next;
    }
    printf("\n");
}

void free_list(linked_list* l) {
    node* n = l->head;
    while (n!= NULL) {
        node* next = n->next;
        free(n);
        n = next;
    }
    free(l);
}

double calculate_voltage(double resistance, double current) {
    return resistance * current;
}

double calculate_current(double voltage, double resistance) {
    return voltage / resistance;
}

double calculate_power(double voltage, double current) {
    return voltage * current;
}

int main() {
    linked_list* circuits = create_list();
    add_node(circuits, 10.0);
    add_node(circuits, 20.0);
    add_node(circuits, 30.0);
    add_node(circuits, 40.0);
    add_node(circuits, 50.0);
    print_list(circuits);
    free_list(circuits);
    return 0;
}