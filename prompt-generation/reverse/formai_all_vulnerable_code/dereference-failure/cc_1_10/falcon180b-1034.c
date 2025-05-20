//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int *arr;
    int size = 0;
    int choice;
    int sum = 0;

    srand(time(NULL));

    do {
        printf("\n");
        printf("Welcome to the Future Math Exercise Program\n");
        printf("---------------------------------------------\n");
        printf("Please select an option:\n");
        printf("1. Generate a random array\n");
        printf("2. Calculate the sum of an array\n");
        printf("3. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                arr = (int *)malloc(sizeof(int) * MAX_SIZE);
                size = rand() % MAX_SIZE + 1;

                for(int i=0; i<size; i++) {
                    arr[i] = rand() % 100;
                }

                printf("\n");
                printf("Random array generated:\n");
                for(int i=0; i<size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2:
                printf("\n");
                printf("Enter the elements of the array (separated by space):\n");
                for(int i=0; i<size; i++) {
                    scanf("%d", &arr[i]);
                    sum += arr[i];
                }

                printf("\n");
                printf("The sum of the array is: %d\n", sum);
                break;

            case 3:
                printf("\n");
                printf("Exiting program...\n");
                break;

            default:
                printf("\n");
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while(choice!= 3);

    free(arr);
    return 0;
}