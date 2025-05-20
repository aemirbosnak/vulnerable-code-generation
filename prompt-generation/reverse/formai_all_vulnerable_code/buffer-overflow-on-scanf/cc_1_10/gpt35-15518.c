//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the surreal world of Greedy Algorithms!\n\n");

    int num_elements;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &num_elements);

    int* arr = (int*) malloc(num_elements * sizeof(int));

    printf("\nEnter the elements of the array: ");

    for(int i=0; i<num_elements; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nCalculating the maximum sum using Greedy Algorithm...");

    // Let's sort the array in descending order
    for(int i=0; i<num_elements; i++) {
        for(int j=i+1; j<num_elements; j++) {
            if(arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int max_sum = 0;
    int j = 0;

    while(j < num_elements) {
        if(j+1 < num_elements && arr[j+1] > arr[j]) {
            max_sum += arr[j+1];
            j += 2;
        }
        else {
            max_sum += arr[j];
            j++;
        }
    }

    printf("\nThe maximum sum using Greedy Algorithm is: %d", max_sum);

    free(arr);
    return 0;
}