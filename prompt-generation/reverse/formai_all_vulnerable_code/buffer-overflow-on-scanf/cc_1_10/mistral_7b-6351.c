//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Fruit {
    char name[20];
    int weight;
} Fruit;

void print_array(int arr[], int size) {
    int i;
    printf("Array elements are:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

void print_fruits(Fruit fruits[], int size) {
    int i;
    printf("Fruits and their weights:\n");
    for (i = 0; i < size; i++) {
        printf("%s weighs %d grams\n", fruits[i].name, fruits[i].weight);
    }
}

int main() {
    int arr[MAX_SIZE], i;
    Fruit fruits[MAX_SIZE];

    printf("\nWelcome to the Cheerful Fruit Sorting Program!\n");

    // Initializing the array of integers
    printf("Enter %d integers to be sorted:\n", MAX_SIZE);
    for (i = 0; i < MAX_SIZE; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Sorting the array of integers
    printf("\nSorting the array using Bubble Sort Algorithm:\n");
    bubbleSort(arr, MAX_SIZE);
    print_array(arr, MAX_SIZE);

    // Initializing the array of fruits
    printf("\nNow let's sort some cheerful fruits:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("\nEnter name and weight of fruit %d: ", i + 1);
        scanf("%s", fruits[i].name);
        scanf("%d", &fruits[i].weight);
    }

    // Sorting the array of fruits by their weights
    printf("\nSorting the fruits using Bubble Sort Algorithm:\n");
    bubbleSort(fruits, MAX_SIZE);
    print_fruits(fruits, MAX_SIZE);

    return 0;
}