//FormAI DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = malloc(sizeof(int) * 5);
    int i, choice, index, newValue;
    for(i=0; i<5; i++){
        arr[i] = i+1;
    }
    printf("Current array: ");
    for(i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    do{
        printf("What do you want to do?\n");
        printf("1. Add a new element\n");
        printf("2. Delete an existing element\n");
        printf("3. Update an existing element\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the index where you want to add new element: ");
                scanf("%d", &index);
                arr = realloc(arr, sizeof(int) * 6); // increase size to accommodate new element
                printf("Enter the new value: ");
                scanf("%d", &newValue);
                for(i=5; i>=index; i--){
                    arr[i] = arr[i-1];
                }
                arr[index] = newValue;
                printf("New array: ");
                for(i=0; i<6; i++){
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2:
                printf("Enter the index of the element you want to delete: ");
                scanf("%d", &index);
                for(i=index; i<5; i++){
                    arr[i] = arr[i+1];
                }
                arr = realloc(arr, sizeof(int) * 4); // decrease size to remove deleted element
                printf("New array: ");
                for(i=0; i<4; i++){
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                printf("Enter the index of the element you want to update: ");
                scanf("%d", &index);
                printf("Enter the new value: ");
                scanf("%d", &newValue);
                arr[index] = newValue;
                printf("New array: ");
                for(i=0; i<5; i++){
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice, try again\n");
        }

    }while(choice!=4);

    free(arr);
    return 0;
}