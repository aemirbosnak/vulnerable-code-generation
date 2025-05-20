//Falcon-180B DATASET v1.0 Category: Memory management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000

int main() {
    int *arr = NULL;
    int size = 0;
    int option = 0;
    int element = 0;
    int i = 0;

    srand(time(NULL));

    while(option!= 4) {
        printf("1. Allocate memory\n");
        printf("2. Deallocate memory\n");
        printf("3. Modify element\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                if(size == MAX_SIZE) {
                    printf("Can't allocate more memory!\n");
                } else {
                    arr = realloc(arr, sizeof(int) * ++size);
                    arr[size-1] = rand() % 100;
                    printf("Allocated memory successfully!\n");
                }
                break;
            case 2:
                if(size == 0) {
                    printf("No memory to deallocate!\n");
                } else {
                    free(arr);
                    arr = NULL;
                    size = 0;
                    printf("Deallocated memory successfully!\n");
                }
                break;
            case 3:
                if(size == 0) {
                    printf("No memory to modify!\n");
                } else {
                    printf("Enter the element to modify: ");
                    scanf("%d", &element);
                    for(i=0; i<size; i++) {
                        if(arr[i] == element) {
                            arr[i] = rand() % 100;
                            printf("Modified element successfully!\n");
                            break;
                        }
                    }
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}