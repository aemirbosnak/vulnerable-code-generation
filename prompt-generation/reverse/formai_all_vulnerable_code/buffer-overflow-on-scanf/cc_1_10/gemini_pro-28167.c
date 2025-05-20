//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue *queue, int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue *queue) {
    if (queue->front == NULL) {
        return -1;
    }
    struct Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

int main() {
    int n, m, i, j, k, l;
    char c;
    scanf("%d %d", &n, &m);
    int **arr = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        arr[i] = (int *) malloc(m * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf(" %c", &c);
    if (c == 'R') {
        for (i = 0; i < m; i++) {
            struct Queue *queue = createQueue();
            for (j = 0; j < n; j++) {
                enqueue(queue, arr[j][i]);
            }
            for (j = 0; j < n; j++) {
                arr[j][i] = dequeue(queue);
            }
        }
    } else if (c == 'C') {
        for (i = 0; i < n; i++) {
            struct Queue *queue = createQueue();
            for (j = 0; j < m; j++) {
                enqueue(queue, arr[i][j]);
            }
            for (j = 0; j < m; j++) {
                arr[i][j] = dequeue(queue);
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}