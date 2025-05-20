//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_list(int size) {
    struct Node* head = NULL;
    struct Node* current = NULL;
    int i;

    for (i = 0; i < size; i++) {
        current = (struct Node*) malloc(sizeof(struct Node));
        if (current == NULL) {
            printf("Error: Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }

        current->data = i;
        current->next = NULL;

        if (head == NULL) {
            head = current;
        } else {
            struct Node* temp = head;

            while (temp->next!= NULL) {
                temp = temp->next;
            }

            temp->next = current;
        }
    }

    return head;
}

void print_list(struct Node* head) {
    struct Node* current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void sort_list(struct Node* head) {
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while (current!= NULL) {
        next = current->next;

        while (next!= NULL) {
            if (current->data > next->data) {
                int temp_data = current->data;
                current->data = next->data;
                next->data = temp_data;

                if (prev!= NULL) {
                    prev->next = next;
                } else {
                    head = next;
                }

                current = next;
                next = current->next;
            } else {
                current = next;
                next = current->next;
            }
        }

        prev = current;
        current = current->next;
    }
}

int main() {
    int size;
    struct Node* head = NULL;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    head = create_list(size);
    print_list(head);
    sort_list(head);
    print_list(head);

    return 0;
}