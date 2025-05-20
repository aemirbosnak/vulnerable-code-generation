//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int n;

void insert(int val) {
    if (n == MAX_SIZE) {
        printf("Array is full\n");
        return;
    }
    arr[n++] = val;
}

void display() {
    printf("Array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void search(int val) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("%d found at position %d\n", val, i+1);
            return;
        }
    }
    printf("%d not found in the array\n", val);
}

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice, val;
    while (1) {
        printf("Enter your choice:\n1. Display array\n2. Search element\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}