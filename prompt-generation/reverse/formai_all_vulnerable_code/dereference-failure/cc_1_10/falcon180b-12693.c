//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct bucket {
    int data;
    int count;
    struct bucket *next;
} Bucket;

void createBucket(Bucket **head, int size) {
    Bucket *newBucket = (Bucket *)malloc(sizeof(Bucket));
    newBucket->data = -1;
    newBucket->count = 0;
    newBucket->next = NULL;
    if (*head == NULL) {
        *head = newBucket;
        return;
    }
    Bucket *temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newBucket;
}

void insertBucket(Bucket **head, int data, int size) {
    Bucket *temp = *head;
    while (temp!= NULL) {
        if (temp->data == data) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    createBucket(head, size);
}

void sortBucket(Bucket **head, int size) {
    Bucket *temp = *head;
    while (temp!= NULL) {
        Bucket *next = temp->next;
        while (next!= NULL) {
            if (temp->data > next->data) {
                int tempData = temp->data;
                temp->data = next->data;
                next->data = tempData;
            }
            next = next->next;
        }
        temp = temp->next;
    }
}

void printBucket(Bucket *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Bucket *head = NULL;
    int n, size = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x);
        insertBucket(&head, x, size);
        size++;
    }
    printf("Sorted elements:\n");
    sortBucket(&head, size);
    printBucket(head);
    return 0;
}