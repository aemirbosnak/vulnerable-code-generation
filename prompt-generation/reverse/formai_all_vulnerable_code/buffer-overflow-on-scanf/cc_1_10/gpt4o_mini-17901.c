//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void convertToHex(int num) {
    if (num < 0) {
        printf("Negative numbers cannot be converted to hexadecimal.\n");
        return;
    }
    
    char hex[20];
    int i = 0;

    while (num != 0) {
        int temp = num % 16;

        if (temp < 10) {
            hex[i] = temp + 48; // Convert to ASCII
        } else {
            hex[i] = temp + 87; // Convert to ASCII ('a' starts from 97)
        }
        num /= 16;
        i++;
    }

    // Printing in reverse
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    putchar('\n');
}

void convertIntegerArrayToHex(int *arr, int size) {
    for (int index = 0; index < size; index++) {
        printf("Integer %d in Hex: ", arr[index]);
        convertToHex(arr[index]);
    }
}

void getInput() {
    int size;

    printf("Enter the number of integers you wish to convert: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    int *arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input detected. Exiting.\n");
            free(arr);
            exit(EXIT_FAILURE);
        }
    }

    convertIntegerArrayToHex(arr, size);
    free(arr);
}

int main() {
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("This program converts integers to their hexadecimal representation.\n");
    getInput();
    return 0;
}