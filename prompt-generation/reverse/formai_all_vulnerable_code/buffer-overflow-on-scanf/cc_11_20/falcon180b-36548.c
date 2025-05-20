//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

int main() {
    int arr[MAX_SIZE];
    int num_elements = 0;
    int choice;
    int i;

    srand(time(NULL));

    do {
        printf("Enter 1 to add an element, 2 to remove an element, 3 to display the array, or 4 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_elements >= MAX_SIZE) {
                    printf("Array is full.\n");
                } else {
                    printf("Enter an integer to add to the array: ");
                    scanf("%d", &arr[num_elements]);
                    num_elements++;
                }
                break;
            case 2:
                if (num_elements == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Enter the index of the element to remove: ");
                    scanf("%d", &i);
                    if (i >= 0 && i < num_elements) {
                        for (int j = i; j < num_elements - 1; j++) {
                            arr[j] = arr[j + 1];
                        }
                        num_elements--;
                    } else {
                        printf("Invalid index.\n");
                    }
                }
                break;
            case 3:
                if (num_elements == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array: ");
                    for (int j = 0; j < num_elements; j++) {
                        printf("%d ", arr[j]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 4);

    return 0;
}