//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: calm
// Program to demonstrate unique C memory management
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Dynamic memory allocation
    int *arr = (int *)malloc(sizeof(int) * 5);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    // Freeing memory
    free(arr);

    // Allocating memory for a string
    char *str = (char *)malloc(sizeof(char) * 10);
    strcpy(str, "Hello World");

    // Freeing memory
    free(str);

    // Allocating memory for a 2D array
    int **mat = (int **)malloc(sizeof(int *) * 5);
    for (int i = 0; i < 5; i++) {
        mat[i] = (int *)malloc(sizeof(int) * 5);
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            mat[i][j] = i * j;
        }
    }

    // Freeing memory
    for (int i = 0; i < 5; i++) {
        free(mat[i]);
    }
    free(mat);

    // Allocating memory for a struct
    struct Person {
        int age;
        char name[10];
    };
    struct Person *p = (struct Person *)malloc(sizeof(struct Person));
    p->age = 25;
    strcpy(p->name, "John");

    // Freeing memory
    free(p);

    return 0;
}