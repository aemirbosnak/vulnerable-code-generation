//Falcon-180B DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int size;
    int *ptr = NULL;
    int choice;

    while(1) {
        printf("Enter 1 to allocate memory\n");
        printf("Enter 2 to deallocate memory\n");
        printf("Enter 3 to exit\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the size of memory to be allocated: ");
                scanf("%d",&size);
                ptr = (int *)malloc(size*sizeof(int)); // Allocate memory
                if(ptr == NULL) {
                    printf("Memory not allocated\n");
                }
                else {
                    printf("Memory allocated\n");
                }
                break;

            case 2:
                if(ptr!= NULL) {
                    free(ptr); // Deallocate memory
                    ptr = NULL;
                    printf("Memory deallocated\n");
                }
                else {
                    printf("Memory not allocated\n");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}