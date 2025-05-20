//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define ARRAY_SIZE 5

void printArray(int arr[], int size);

int main() {
    int num1, num2, sum, product;
    char str[MAX_LEN];
    FILE *file;
    int arr[ARRAY_SIZE];

    printf("Enter two integers: ");
    scanf("%d%d", &num1, &num2);

    sum = num1 + num2;
    product = num1 * num2;

    printf("Sum = %d, Product = %d\n", sum, product);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i * 2;
    }

    printArray(arr, ARRAY_SIZE);

    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    if (strlen(str) > 10) {
        printf("String is too long.\n");
    } else {
        printf("Length of the string is %d.\n", strlen(str));
    }

    file = fopen("file.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fprintf(file, "Hello World\n");
    fclose(file);

    file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[MAX_LEN];
    fgets(line, MAX_LEN, file);
    printf("%s", line);
    fclose(file);

    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}