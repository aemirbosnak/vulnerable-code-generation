//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct memory_block {
    int data;
    struct memory_block *next;
};

void memory_alloc(struct memory_block **head, int data) {
    struct memory_block *new_block = malloc(sizeof(struct memory_block));
    new_block->data = data;
    new_block->next = *head;
    *head = new_block;
}

void memory_free(struct memory_block **head, int data) {
    struct memory_block *curr = *head;
    struct memory_block *prev = NULL;

    while (curr != NULL) {
        if (curr->data == data) {
            if (prev == NULL) {
                *head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main() {
    struct memory_block *head = NULL;
    memory_alloc(&head, 10);
    memory_alloc(&head, 20);
    memory_alloc(&head, 30);
    memory_free(&head, 20);
    memory_alloc(&head, 40);

    struct memory_block *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    return 0;
}