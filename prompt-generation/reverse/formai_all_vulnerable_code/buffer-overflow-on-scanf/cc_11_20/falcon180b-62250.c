//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j, k, l, m, sum = 0, count = 0, flag = 0;
    int arr[MAX_SIZE];
    int *ptr;
    char choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for the size of the array
    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Initialize the array with random integers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Prompt the user for the operation to be performed
    printf("\nEnter the operation to be performed:\n");
    printf("1. Sum of all elements\n");
    printf("2. Count of even elements\n");
    printf("3. Count of odd elements\n");
    printf("4. Count of prime elements\n");
    scanf("%c", &choice);

    // Perform the selected operation
    switch (choice) {
        case '1':
            for (i = 0; i < n; i++) {
                sum += arr[i];
            }
            printf("\nThe sum of all elements is %d.\n", sum);
            break;

        case '2':
            for (i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) {
                    count++;
                }
            }
            printf("\nThe count of even elements is %d.\n", count);
            break;

        case '3':
            for (i = 0; i < n; i++) {
                if (arr[i] % 2!= 0) {
                    count++;
                }
            }
            printf("\nThe count of odd elements is %d.\n", count);
            break;

        case '4':
            for (i = 0; i < n; i++) {
                flag = 1;
                for (j = 2; j <= arr[i] / 2; j++) {
                    if (arr[i] % j == 0) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    count++;
                }
            }
            printf("\nThe count of prime elements is %d.\n", count);
            break;

        default:
            printf("\nInvalid choice.\n");
    }

    return 0;
}