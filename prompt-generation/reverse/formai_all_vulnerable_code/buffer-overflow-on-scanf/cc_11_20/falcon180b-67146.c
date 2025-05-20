//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARRAY_SIZE 10

int main() {
    int array[ARRAY_SIZE] = {0};
    int i, j, k, num;
    int choice;
    srand(time(NULL));

    do {
        printf("\nWelcome to the Bitwise Operations Game!\n\n");
        printf("1. Generate random array\n");
        printf("2. Sort array in ascending order\n");
        printf("3. Sort array in descending order\n");
        printf("4. Find the largest number in the array\n");
        printf("5. Find the smallest number in the array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Generate random array
                for(i = 0; i < ARRAY_SIZE; i++) {
                    array[i] = rand() % 100;
                }
                printf("\nRandom array generated:\n");
                for(i = 0; i < ARRAY_SIZE; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;

            case 2:
                // Sort array in ascending order
                for(i = 0; i < ARRAY_SIZE - 1; i++) {
                    for(j = 0; j < ARRAY_SIZE - i - 1; j++) {
                        if(array[j] > array[j + 1]) {
                            num = array[j];
                            array[j] = array[j + 1];
                            array[j + 1] = num;
                        }
                    }
                }
                printf("\nArray sorted in ascending order:\n");
                for(i = 0; i < ARRAY_SIZE; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;

            case 3:
                // Sort array in descending order
                for(i = 0; i < ARRAY_SIZE - 1; i++) {
                    for(j = 0; j < ARRAY_SIZE - i - 1; j++) {
                        if(array[j] < array[j + 1]) {
                            num = array[j];
                            array[j] = array[j + 1];
                            array[j + 1] = num;
                        }
                    }
                }
                printf("\nArray sorted in descending order:\n");
                for(i = 0; i < ARRAY_SIZE; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;

            case 4:
                // Find the largest number in the array
                printf("\nLargest number in array: %d\n", array[0]);
                break;

            case 5:
                // Find the smallest number in the array
                printf("\nSmallest number in array: %d\n", array[0]);
                break;

            case 6:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while(choice!= 6);

    return 0;
}