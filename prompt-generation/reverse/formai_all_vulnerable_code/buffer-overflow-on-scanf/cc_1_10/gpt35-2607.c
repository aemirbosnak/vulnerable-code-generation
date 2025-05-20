//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int code;
    char message[50];
} ErrorCode;

void errorHandler(int code) {
    ErrorCode errorCodes[] = {
        {100, "File not found"},
        {200, "Memory allocation error"},
        {300, "Invalid input"}
    };
    
    int size = sizeof(errorCodes) / sizeof(errorCodes[0]);
    for (int i = 0; i < size; i++) {
        if (errorCodes[i].code == code) {
            printf("\nError %d: %s\n", errorCodes[i].code, errorCodes[i].message);
            exit(code);
        }
    }
    
    printf("\nUnknown error occurred\n");
    exit(1);
}

int main() {
    int* arr = NULL;
    int size;

    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        errorHandler(300);
    }

    arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL) {
        errorHandler(200);
    }

    printf("\nEnter the array elements:\n");
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            errorHandler(300);
        }
    }

    FILE* fp = fopen("output.txt", "w");
    if (fp == NULL) {
        errorHandler(100);
    }

    for (int i = 0; i < size; i++) {
        if (fprintf(fp, "%d ", arr[i]) < 0) {
            errorHandler(100);
        }
    }

    printf("\nArray elements written to 'output.txt' file successfully!\n");

    return 0;
}