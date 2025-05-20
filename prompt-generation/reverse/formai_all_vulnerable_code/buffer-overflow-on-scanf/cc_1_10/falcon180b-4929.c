//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

struct Node {
    int data;
    int freq;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->freq = 1;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    while (temp!= NULL && temp->data < data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        newNode->next = head;
        return newNode;
    } else {
        newNode->next = temp;
        return head;
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* temp1 = list1;
    struct Node* temp2 = list2;
    while (temp1!= NULL && temp2!= NULL) {
        if (temp1->data < temp2->data) {
            result = insertNode(result, temp1->data);
            temp1 = temp1->next;
        } else {
            result = insertNode(result, temp2->data);
            temp2 = temp2->next;
        }
    }
    while (temp1!= NULL) {
        result = insertNode(result, temp1->data);
        temp1 = temp1->next;
    }
    while (temp2!= NULL) {
        result = insertNode(result, temp2->data);
        temp2 = temp2->next;
    }
    return result;
}

void mergeSort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    struct Node* mid = head;
    while (mid->next!= NULL && mid->next->next!= NULL) {
        mid = mid->next;
    }
    struct Node* secondHalf = mid->next;
    mid->next = NULL;
    mergeSort(head);
    mergeSort(secondHalf);
    head = mergeLists(head, secondHalf);
}

int main() {
    srand(time(NULL));
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size\n");
        exit(0);
    }
    struct Node* head = NULL;
    for (int i = 0; i < size; i++) {
        int data = rand() % 100;
        head = insertNode(head, data);
        printf("%d ", data);
    }
    printf("\n");
    mergeSort(head);
    printf("Sorted list: ");
    displayList(head);
    printf("\n");
    return 0;
}