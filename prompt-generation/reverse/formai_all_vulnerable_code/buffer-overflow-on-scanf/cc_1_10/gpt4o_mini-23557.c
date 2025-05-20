//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_array(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr = NULL;
    int n = 0;
    int choice;

    do {
        printf("\nWelcome to the C Sorting Program!\n");
        printf("1. Input numbers to sort\n");
        printf("2. Sort numbers using Bubble Sort\n");
        printf("3. Print the sorted array\n");
        printf("4. Exit the program\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many numbers do you want to input? ");
                scanf("%d", &n);
                arr = (int*)malloc(n * sizeof(int));
                if (arr == NULL) {
                    fprintf(stderr, "Memory allocation failed!\n");
                    exit(1);
                }

                printf("Enter %d numbers:\n", n);
                for (int i = 0; i < n; i++) {
                    printf("Number %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                if (arr == NULL) {
                    printf("No numbers to sort! Please input numbers first.\n");
                } else {
                    bubble_sort(arr, n);
                    printf("Array sorted using Bubble Sort.\n");
                }
                break;

            case 3:
                if (arr == NULL) {
                    printf("No numbers to display! Please input numbers first.\n");
                } else {
                    print_array(arr, n);
                }
                break;

            case 4:
                printf("Thank you for using the sorting program! Goodbye!\n");
                free(arr);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}