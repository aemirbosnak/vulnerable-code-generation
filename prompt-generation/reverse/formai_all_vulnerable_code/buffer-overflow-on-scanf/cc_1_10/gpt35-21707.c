//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

struct node { // structure of node in the linked list
    int data;
    struct node* next;
};

void bucketSort(int arr[], int n) {
    struct node* buckets[n]; // array of buckets
    int i;
    for (i = 0; i < n; i++) {
        buckets[i] = NULL; // initializing each bucket
    }
    for (i = 0; i < n; i++) {
        int index = (arr[i] / n); // finding index of bucket in the array
        struct node* newNode = (struct node*) malloc(sizeof(struct node)); // creating new node to store the value
        newNode->data = arr[i];
        newNode->next = NULL;
        if (buckets[index] == NULL) { // if bucket is empty, insert new node as the first node
            buckets[index] = newNode;
        }
        else {
            struct node* temp = buckets[index];
            while (temp->next != NULL) { // traverse till last node to insert new node
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    int j = 0;
    for (i = 0; i < n; i++) {
        struct node* temp = buckets[i];
        while (temp != NULL) { // traverse each bucket and insert values back into array
            arr[j] = temp->data;
            temp = temp->next;
            j++;
        }
    }
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n); // sorting the array using bucket sort algorithm
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}