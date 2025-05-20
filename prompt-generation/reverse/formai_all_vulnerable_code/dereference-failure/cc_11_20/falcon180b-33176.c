//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int *arr;
    int size = 0;
    int choice;

    do {
        printf("Enter 1 to allocate memory, 2 to deallocate memory, 3 to check memory usage, 4 to exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the amount of memory you want to allocate in bytes:\n");
                scanf("%d", &size);

                if(size <= 0 || size > MAX_SIZE) {
                    printf("Invalid size. Please enter a valid size.\n");
                } else {
                    arr = (int*)malloc(size);
                    if(arr == NULL) {
                        printf("Not enough memory available.\n");
                    } else {
                        printf("Memory allocated successfully.\n");
                    }
                }
                break;

            case 2:
                if(arr!= NULL) {
                    free(arr);
                    arr = NULL;
                    printf("Memory deallocated successfully.\n");
                } else {
                    printf("No memory allocated yet.\n");
                }
                break;

            case 3:
                if(arr!= NULL) {
                    printf("Current memory usage: %d bytes\n", size);
                } else {
                    printf("No memory allocated yet.\n");
                }
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}