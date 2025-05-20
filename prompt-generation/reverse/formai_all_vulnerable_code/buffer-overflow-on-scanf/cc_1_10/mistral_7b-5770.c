//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 50

void print_menu();
void bubble_sort(int arr[], int n);
bool is_valid_input(char str[], int *num);

int main() {
    int arr[MAX_SIZE];
    int n, i;
    char input_str[MAX_SIZE];

    print_menu();

    while (true) {
        scanf("%s", input_str);

        if (strcmp(input_str, "quit") == 0) {
            break;
        }

        if (!is_valid_input(input_str, &n)) {
            printf("Invalid input. Please enter a valid number of elements.\n");
            continue;
        }

        printf("Enter %d integers:\n", n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        bubble_sort(arr, n);

        printf("Sorted array: ");

        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n");
    }

    return 0;
}

void print_menu() {
    printf("\nBubble Sort Program\n");
    printf("--------------------\n");
    printf("Enter the number of elements and then enter the elements separated by spaces.\n");
    printf("For example: 5 3 2 1 0\n");
    printf("Enter 'quit' to exit.\n");
}

void bubble_sort(int arr[], int n) {
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

bool is_valid_input(char str[], int *num) {
    char *end;
    int n;

    *num = strtol(str, &end, 10);

    if (*end != '\0') {
        return false;
    }

    if (*num < 0 || *num > MAX_SIZE) {
        return false;
    }

    return true;
}