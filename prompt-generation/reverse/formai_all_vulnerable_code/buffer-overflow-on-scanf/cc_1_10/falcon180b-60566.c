//Falcon-180B DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    srand(time(NULL));

    do {
        printf("Enter 1 to generate a random number and add it to the array.\n");
        printf("Enter 2 to display the current contents of the array.\n");
        printf("Enter 3 to exit.\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (size >= MAX_SIZE) {
                    printf("Array is full. Cannot generate more numbers.\n");
                } else {
                    arr[size] = rand() % 100;
                    size++;
                    printf("Generated number: %d\n", arr[size - 1]);
                }
                break;
            case 2:
                if (size == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array contents:\n");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}