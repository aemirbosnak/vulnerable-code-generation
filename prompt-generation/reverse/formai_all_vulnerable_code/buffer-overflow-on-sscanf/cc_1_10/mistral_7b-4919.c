//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void bubbleSort(int arr[], int n);
int isValidInput(int *num, int *size);
void printMenu();

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice = 0;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        if (choice == 1 && isValidInput(arr, &size) != 1) {
            printf("Error in input! Please try again.\n");
            continue;
        }

        if (choice == 1) {
            bubbleSort(arr, size);
            printf("Sorted array:\n");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int isValidInput(int *num, int *size) {
    int temp = 0;
    char input[MAX_SIZE];

    printf("Enter the number of elements to input: ");
    fgets(input, MAX_SIZE, stdin);
    size_t len = strlen(input);

    if (len > MAX_SIZE - 1) {
        printf("Input too large! Please try again.\n");
        return 0;
    }

    sscanf(input, "%d%n", size, &temp);

    if (*size <= 0) {
        printf("Invalid size! Please try again.\n");
        return 0;
    }

    printf("Enter %d integers:\n", *size);

    for (int i = 0; i < *size; i++) {
        if (scanf("%d%n", num + i, &temp) != 1) {
            printf("Invalid input! Please try again.\n");
            return 0;
        }
    }

    return 1;
}

void printMenu() {
    printf("\nSorting Menu:\n");
    printf("1. Input and sort an array\n");
    printf("2. Exit\n");
    printf("3. Display this menu\n");
}