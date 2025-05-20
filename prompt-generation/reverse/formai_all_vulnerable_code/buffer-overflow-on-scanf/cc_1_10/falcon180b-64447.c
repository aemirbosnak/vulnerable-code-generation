//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    while(1) {
        printf("Enter 1 to add an element to the array\n");
        printf("Enter 2 to remove an element from the array\n");
        printf("Enter 3 to print the array\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to add:\n");
                scanf("%d", &arr[size]);
                size++;
                break;
            case 2:
                if(size == 0) {
                    printf("Array is empty\n");
                } else {
                    printf("Enter the element to remove:\n");
                    scanf("%d", &arr[0]);
                    for(int i=0; i<size; i++) {
                        if(arr[i]!= arr[0]) {
                            arr[i] = arr[i+1];
                        }
                    }
                    size--;
                }
                break;
            case 3:
                printf("Array:\n");
                for(int i=0; i<size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}