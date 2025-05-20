//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

int main() {
    int *ptr;
    int i, j;
    double pi = 3.14159265358979323846;
    double sum = 0.0;
    int count = 0;
    int *arr[SIZE];
    int size = 0;
    int max_size = 0;
    int min_size = SIZE;
    int avg_size = 0;
    int total_size = 0;

    printf("Alan Turing's RAM Usage Monitor\n");
    printf("---------------------------------\n");

    for (i = 0; i < SIZE; i++) {
        arr[i] = (int *) malloc(10 * sizeof(int));
        if (arr[i] == NULL) {
            printf("Error: Unable to allocate memory!\n");
            exit(1);
        }
    }

    while (1) {
        printf("\nCurrent RAM usage: %.2f MB\n", (double) total_size / (1024 * 1024));
        printf("---------------------------------\n");
        printf("Enter 1 to allocate memory\n");
        printf("Enter 2 to free memory\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &i);

        switch (i) {
            case 1:
                printf("Enter the size of the array: ");
                scanf("%d", &j);
                ptr = (int *) malloc(j * sizeof(int));
                if (ptr == NULL) {
                    printf("Error: Unable to allocate memory!\n");
                    exit(1);
                }
                arr[size] = ptr;
                size++;
                total_size += j * sizeof(int);
                break;

            case 2:
                printf("Enter the index of the array to free: ");
                scanf("%d", &j);
                if (j >= 0 && j < SIZE) {
                    free(arr[j]);
                    arr[j] = NULL;
                    total_size -= 10 * sizeof(int);
                    size--;
                }
                break;

            case 3:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }

        if (size > max_size) {
            max_size = size;
        }

        if (size < min_size) {
            min_size = size;
        }

        avg_size = (int) ((double) total_size / SIZE);

        for (j = 0; j < SIZE; j++) {
            if (arr[j]!= NULL) {
                sum += 10;
            }
        }

        count = size;
    }

    return 0;
}