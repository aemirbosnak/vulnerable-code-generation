//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int option;
    
    do {
        printf("Enter 1 to add an element to the array\n");
        printf("Enter 2 to remove an element from the array\n");
        printf("Enter 3 to print the array\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                if(size == MAX_SIZE) {
                    printf("Array is full\n");
                } else {
                    printf("Enter the element to be added: ");
                    scanf("%d", &arr[size]);
                    size++;
                }
                break;
                
            case 2:
                if(size == 0) {
                    printf("Array is empty\n");
                } else {
                    printf("Enter the element to be removed: ");
                    int element;
                    scanf("%d", &element);
                    
                    int i;
                    for(i = 0; i < size; i++) {
                        if(arr[i] == element) {
                            arr[i] = arr[size - 1];
                            size--;
                            break;
                        }
                    }
                    
                    if(i == size) {
                        printf("Element not found\n");
                    }
                }
                break;
                
            case 3:
                printf("Array: ");
                for(int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
                
            case 4:
                printf("Exiting program\n");
                break;
                
            default:
                printf("Invalid option\n");
        }
    } while(option!= 4);
    
    return 0;
}