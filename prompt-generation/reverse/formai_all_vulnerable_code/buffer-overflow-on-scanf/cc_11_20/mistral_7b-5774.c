//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int numbers[SIZE], i, sum = 0, search, index;
    int *ptr1, *ptr2;

    srand(time(NULL));

    // Assign random numbers to array elements
    for(i = 0; i < SIZE; i++) {
        numbers[i] = rand() % 11;
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    // Calculate sum of array elements
    for(i = 0; i < SIZE; i++) {
        sum += numbers[i];
    }

    printf("\nSum of array elements: %d\n", sum);

    // Print elements in random order
    for(i = SIZE - 1; i >= 0; i--) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    // Search for a number in array
    do {
        printf("\nEnter a number to search for: ");
        scanf("%d", &search);

        for(i = 0; i < SIZE; i++) {
            if(numbers[i] == search) {
                index = i;
                break;
            }
        }

        if(index == SIZE) {
            printf("Number not found\n");
        } else {
            printf("Number %d found at index %d\n", search, index);
        }

    } while(1);

    // Swap elements using pointers
    ptr1 = &numbers[3];
    ptr2 = &numbers[6];

    *ptr1 = numbers[3];
    numbers[3] = numbers[6];
    numbers[6] = *ptr1;

    // User input for different actions
    int choice;

    switch(choice) {
        case 1:
            printf("Print array elements\n");
            break;
        case 2:
            printf("Calculate sum of array elements\n");
            break;
        case 3:
            printf("Search for a number in array\n");
            break;
        case 4:
            printf("Swap positions of two elements\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}