//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        printf("Enter 1 to add an element, 2 to remove an element, 3 to print the array, 0 to exit:\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(size == MAX_SIZE) {
                    printf("Error: Array is full.\n");
                }
                else {
                    printf("Enter the element:\n");
                    scanf("%d", &arr[size]);
                    size++;
                }
                break;

            case 2:
                if(size == 0) {
                    printf("Error: Array is empty.\n");
                }
                else {
                    printf("Enter the element to remove:\n");
                    scanf("%d", &arr[--size]);
                }
                break;

            case 3:
                printf("Array:\n");
                for(int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 0);

    return 0;
}