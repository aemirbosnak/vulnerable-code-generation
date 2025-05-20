//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000
#define TABLE_SIZE 11

typedef struct Node {
    int key;
    struct Node *next;
} Node;

Node *table[TABLE_SIZE];
int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(Node **head, int key) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n");
}

void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Array size exceeded.\n");
        return -1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    shuffle(arr, n);

    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int index = hash(key);
        if (table[index] == NULL) {
            insert(&table[index], key);
        } else {
            Node *current = table[index];
            while (current->next != NULL) {
                current = current->next;
            }
            insert(&current->next, key);
        }
    }

    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == NULL) {
            continue;
        }
        printf("Index %d: ", i);
        printList(table[i]);
    }

    return 0;
}