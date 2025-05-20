//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Node structure for linked list
struct node {
    int data;
    struct node *next;
};

// Linked list structure
struct linked_list {
    struct node *head;
    pthread_mutex_t mutex;
};

// Function to create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of the list
void add_node(struct linked_list *list, int data) {
    struct node *new_node = create_node(data);

    pthread_mutex_lock(&list->mutex);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct node *temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    pthread_mutex_unlock(&list->mutex);
}

// Function to print the list
void print_list(struct linked_list *list) {
    pthread_mutex_lock(&list->mutex);
    struct node *temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    pthread_mutex_unlock(&list->mutex);
}

// Function for a thread to execute
void *thread_func(void *arg) {
    struct linked_list *list = (struct linked_list *) arg;
    int i;

    for (i = 0; i < 10; i++) {
        add_node(list, i);
        print_list(list);
        sleep(1);
    }

    return NULL;
}

int main() {
    struct linked_list list;
    list.head = NULL;
    pthread_mutex_init(&list.mutex, NULL);

    pthread_t thread_id;
    int i;

    for (i = 0; i < 5; i++) {
        pthread_create(&thread_id, NULL, thread_func, &list);
        sleep(1);
    }

    for (i = 0; i < 5; i++) {
        pthread_join(thread_id, NULL);
    }

    return 0;
}