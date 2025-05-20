//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_DATA_SIZE 100

typedef struct {
    char data[MAX_DATA_SIZE];
    int size;
    struct node* next;
} node;

typedef struct {
    node* head;
    int size;
} linked_list;

linked_list* create_list() {
    linked_list* list = (linked_list*)malloc(sizeof(linked_list));
    list->head = NULL;
    list->size = 0;
    return list;
}

void add_node(linked_list* list, char* data) {
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->data, data);
    new_node->size = strlen(data);
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    list->size++;
}

int search_node(linked_list* list, char* data) {
    node* temp = list->head;

    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

void delete_node(linked_list* list, char* data) {
    node* temp = list->head;
    node* prev = NULL;

    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    if (prev == NULL) {
        list->head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    list->size--;
}

void print_list(linked_list* list) {
    node* temp = list->head;

    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    linked_list* list = create_list();
    char* data = "Hello World!";

    add_node(list, data);
    print_list(list);

    if (search_node(list, data)) {
        printf("Data found!\n");
    } else {
        printf("Data not found.\n");
    }

    delete_node(list, data);
    print_list(list);

    return 0;
}