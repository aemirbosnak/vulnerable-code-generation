//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <sys/time.h>

struct vertex {
    int data;
    struct vertex *next;
};

struct vertex *new_vertex(int data) {
    struct vertex *new_node = (struct vertex*)malloc(sizeof(struct vertex));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct vertex *insert_node(struct vertex *head, int data) {
    struct vertex *new_node = new_vertex(data);
    if (head == NULL) {
        head = new_node;
    } else {
        struct vertex *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

void print_list(struct vertex *head) {
    struct vertex *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct vertex *head = NULL;
    int choice;
    struct timeval start, end;
    gettimeofday(&start, NULL);

    while (1) {
        printf("Enter choice: 1 - Insert Node, 2 - Print List, 3 - Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int data;
            printf("Enter data: ");
            scanf("%d", &data);
            head = insert_node(head, data);
        } else if (choice == 2) {
            print_list(head);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    gettimeofday(&end, NULL);
    printf("Time taken: %ld microseconds\n", (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec));
    return 0;
}