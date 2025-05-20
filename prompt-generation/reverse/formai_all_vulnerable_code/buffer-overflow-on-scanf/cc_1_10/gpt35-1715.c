//FormAI DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

void print_memory_status(int* array, int size) {
    printf("The current values in memory are: ");
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
    printf("The total memory allocated is: %d\n", size*sizeof(int));
}

int main() {
    int* array = NULL;
    int size = 0;
    int option;

    do {
        printf("\n");
        printf("--------MENU--------\n");
        printf("1. Allocate memory\n");
        printf("2. Reallocate memory\n");
        printf("3. Free memory\n");
        printf("4. Exit\n");
        printf("---------------------\n");
        printf("Enter your option: ");

        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter the size of the array to be allocated: ");
                scanf("%d", &size);

                array = (int*) malloc(size * sizeof(int));
                if(array != NULL) {
                    printf("Memory allocation successful!\n");
                    for(int i = 0; i < size; i++) {
                        printf("Enter the value for element %d: ", i);
                        scanf("%d", &array[i]);
                    }
                    print_memory_status(array, size);
                } else {
                    printf("Memory allocation failure!\n");
                }
                break;
            case 2:
                printf("\nEnter the new size of the array to be reallocated: ");
                scanf("%d", &size);

                array = (int*) realloc(array, size * sizeof(int));
                if(array != NULL) {
                    printf("Memory reallocation successful!\n");
                    if(size > 0) {
                        for(int i = 0; i < size; i++) {
                            if(i < size-sizeof(array)/sizeof(int)) {
                                printf("Enter the new value for element %d: ", i);
                                scanf("%d", &array[i]);
                            } else {
                                printf("The value of element %d retained: %d\n", i, array[i]);
                            }
                        }
                        print_memory_status(array, size);
                    } else {
                        printf("All memory freed!\n");
                        array = NULL;
                    }
                } else {
                    printf("Memory reallocation failure!\n");
                }
                break;
            case 3:
                free(array);
                printf("Memory has been freed!\n");
                size = 0;
                array = NULL;
                break;
            case 4:
                free(array);
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid option. Please choose again.\n");
        }

    } while(option != 4);

    return 0;
}