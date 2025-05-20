//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 1000

int main() {
    int num_elements = 0;
    double *arr = NULL;
    int choice;

    while(true) {
        printf("Enter your choice:\n");
        printf("1. Enter an element\n");
        printf("2. Calculate sum\n");
        printf("3. Calculate average\n");
        printf("4. Calculate standard deviation\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_elements >= MAX_SIZE) {
                    printf("Array is full. Cannot add more elements.\n");
                    break;
                }
                printf("Enter an element:\n");
                scanf("%lf", &arr[num_elements]);
                num_elements++;
                break;
            case 2:
                if(num_elements == 0) {
                    printf("Array is empty.\n");
                    break;
                }
                double sum = 0;
                for(int i=0; i<num_elements; i++) {
                    sum += arr[i];
                }
                printf("Sum: %lf\n", sum);
                break;
            case 3:
                if(num_elements == 0) {
                    printf("Array is empty.\n");
                    break;
                }
                double avg = 0;
                for(int i=0; i<num_elements; i++) {
                    avg += arr[i];
                }
                avg /= num_elements;
                printf("Average: %lf\n", avg);
                break;
            case 4:
                if(num_elements < 2) {
                    printf("Array should have at least two elements.\n");
                    break;
                }
                double std_dev = 0;
                double mean = 0;
                for(int i=0; i<num_elements; i++) {
                    mean += arr[i];
                }
                mean /= num_elements;
                for(int i=0; i<num_elements; i++) {
                    std_dev += (arr[i] - mean) * (arr[i] - mean);
                }
                std_dev = sqrt(std_dev / (num_elements - 1));
                printf("Standard deviation: %lf\n", std_dev);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}