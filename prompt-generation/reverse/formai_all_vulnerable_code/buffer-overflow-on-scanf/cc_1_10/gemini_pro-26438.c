//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} node_t;

typedef struct queue {
    node_t *front;
    node_t *rear;
} queue_t;

queue_t *create_queue() {
    queue_t *q = malloc(sizeof(queue_t));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(queue_t *q, char *data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

char *dequeue(queue_t *q) {
    if (q->front == NULL) {
        return NULL;
    }
    char *data = q->front->data;
    node_t *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

int main() {
    queue_t *q = create_queue();
    char *input = malloc(101);
    while (1) {
        printf("> ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "add") == 0) {
            char *data = malloc(101);
            scanf(" %[^\n]%*c", data);
            enqueue(q, data);
        } else if (strcmp(input, "remove") == 0) {
            char *data = dequeue(q);
            if (data == NULL) {
                printf("Queue is empty\n");
            } else {
                printf("%s\n", data);
            }
        } else if (strcmp(input, "count") == 0) {
            int count = 0;
            node_t *current = q->front;
            while (current != NULL) {
                count++;
                current = current->next;
            }
            printf("%d\n", count);
        } else if (strcmp(input, "clear") == 0) {
            while (q->front != NULL) {
                dequeue(q);
            }
        } else {
            printf("Unknown command\n");
        }
    }
    free(input);
    while (q->front != NULL) {
        dequeue(q);
    }
    free(q);
    return 0;
}