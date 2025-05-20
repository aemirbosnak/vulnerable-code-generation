//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the given array in a jolly way
void print_jolly(int *arr, int size) {
    printf("Welcome to Memo the Clown's Jolly Jamboree!\n");
    printf("Here are your jolly numbers:\n");
    for (int i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
        if (i % 5 == 4) {
            printf("\nBoom! A clown sneezed.\n");
        }
    }
    printf("\nNow remember them, hehehe!\n");
}

// Function to check if two arrays are identical
int arrays_are_identical(int *arr1, int *arr2, int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to generate random arrays
void generate_arrays(int *arr1, int *arr2, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr1[i] = rand() % 10 + 1;
        arr2[i] = arr1[i]; // Both arrays are identical at the beginning
    }
}

int main() {
    int size, attempts = 0;

    printf("How many jolly numbers do you want to remember, kiddos?\n");
    scanf("%d", &size);

    int *arr1 = (int *)malloc(size * sizeof(int));
    int *arr2 = (int *)malloc(size * sizeof(int));

    generate_arrays(arr1, arr2, size);
    print_jolly(arr1, size);

    int *attempt = (int *)malloc(size * sizeof(int));

    while (1) {
        printf("\nNow, try to recall these jolly numbers in the same order: \n");
        for (int i = 0; i < size; i++) {
            scanf("%d", &attempt[i]);
        }

        if (arrays_are_identical(arr1, attempt, size)) {
            printf("Bravo! You've made Memo the Clown laugh! Try another round? (1 for Yes, 0 for No)\n");
            attempts = 0;
        } else {
            printf("Try again, little ones! You'll get it right eventually!\n");
            attempts++;
            if (attempts > 3) {
                printf("Sorry, you've run out of attempts. Better luck next time!\n");
                free(arr1);
                free(arr2);
                free(attempt);
                return 0;
            }
        }

        // Shuffle the arrays for the next round
        int temp;
        for (int i = 0; i < size; i++) {
            int j = rand() % size;
            temp = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp;
        }
    }

    free(arr1);
    free(arr2);
    free(attempt);

    return 0;
}