//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node **head, int data) {
    Node *temp = *head, *prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; // Node not found
    if (prev == NULL) {
        *head = temp->next; // Node to delete is head
    } else {
        prev->next = temp->next; // Bypass the node
    }
    free(temp);
}

float calculateMean(Node *head) {
    if (head == NULL) return 0.0;
    float sum = 0;
    int count = 0;
    Node *current = head;
    while (current != NULL) {
        sum += current->data;
        count++;
        current = current->next;
    }
    return sum / count;
}

void collectData(Node *head, int *arr, int *size) {
    Node *current = head;
    while (current != NULL) {
        arr[(*size)++] = current->data;
        current = current->next;
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

float calculateMedian(Node *head) {
    if (head == NULL) return 0.0;
    int arr[100], size = 0;
    collectData(head, arr, &size);
    qsort(arr, size, sizeof(int), compare);
    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        return arr[size / 2];
    }
}

int calculateMode(Node *head) {
    if (head == NULL) return 0;
    int frequency[101] = {0};  // Assuming the values are in the range 0-100
    Node *current = head;
    while (current != NULL) {
        frequency[current->data]++;
        current = current->next;
    }
    int mode = 0, maxCount = frequency[0];
    for (int i = 1; i < 101; i++) {
        if (frequency[i] > maxCount) {
            maxCount = frequency[i];
            mode = i;
        }
    }
    return mode;
}

void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int option, value;

    do {
        printf("Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Calculate Mean\n");
        printf("4. Calculate Median\n");
        printf("5. Calculate Mode\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&head, value);
                printf("Inserted %d\n", value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                printf("Deleted %d\n", value);
                break;
            case 3:
                printf("Mean: %.2f\n", calculateMean(head));
                break;
            case 4:
                printf("Median: %.2f\n", calculateMedian(head));
                break;
            case 5:
                printf("Mode: %d\n", calculateMode(head));
                break;
            case 6:
                printf("Current List: ");
                display(head);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (option != 7);

    return 0;
}