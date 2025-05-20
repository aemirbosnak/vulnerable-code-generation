//Falcon-180B DATASET v1.0 Category: Educational ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice = 0;
    int num = 0;

    srand(time(NULL));

    do {
        printf("Enter your choice:\n");
        printf("1. Add an element\n");
        printf("2. Remove an element\n");
        printf("3. Display the array\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &num);
                arr[size] = num;
                size++;
                printf("%d added to the array.\n", num);
                break;

            case 2:
                printf("Enter the element to be removed: ");
                scanf("%d", &num);
                for(int i=0;i<size;i++) {
                    if(arr[i] == num) {
                        for(int j=i;j<size;j++) {
                            arr[j] = arr[j+1];
                        }
                        size--;
                        break;
                    }
                }
                printf("%d removed from the array.\n", num);
                break;

            case 3:
                printf("The array is: ");
                for(int i=0;i<size;i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}