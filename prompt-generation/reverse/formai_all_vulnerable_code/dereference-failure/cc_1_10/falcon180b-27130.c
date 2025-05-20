//Falcon-180B DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_NUM_ELEMS 100

typedef struct {
    char* str;
    int len;
} String;

typedef struct {
    int* nums;
    int numElems;
    int maxElems;
} IntArray;

// Function to initialize an IntArray with a given size
void initIntArray(IntArray* arr, int size) {
    arr->nums = (int*)malloc(size * sizeof(int));
    arr->numElems = 0;
    arr->maxElems = size;
}

// Function to add an integer to an IntArray
void addInt(IntArray* arr, int num) {
    if (arr->numElems >= arr->maxElems) {
        printf("Error: IntArray is full.\n");
        return;
    }
    arr->nums[arr->numElems++] = num;
}

// Function to print the contents of an IntArray
void printIntArray(IntArray* arr) {
    printf("IntArray: ");
    for (int i = 0; i < arr->numElems; i++) {
        printf("%d ", arr->nums[i]);
    }
    printf("\n");
}

// Function to free the memory used by an IntArray
void freeIntArray(IntArray* arr) {
    free(arr->nums);
}

// Function to initialize a String with a given string
void initString(String* str, char* s) {
    str->str = (char*)malloc(strlen(s) + 1);
    str->len = strlen(s);
    strcpy(str->str, s);
}

// Function to print the contents of a String
void printString(String* str) {
    printf("String: %s\n", str->str);
}

// Function to free the memory used by a String
void freeString(String* str) {
    free(str->str);
}

int main() {
    String s1;
    initString(&s1, "Hello, world!");
    printString(&s1);

    String s2;
    initString(&s2, "This is a longer string that will require more memory.");
    printString(&s2);

    IntArray arr;
    initIntArray(&arr, 5);
    addInt(&arr, 1);
    addInt(&arr, 2);
    addInt(&arr, 3);
    addInt(&arr, 4);
    addInt(&arr, 5);
    printIntArray(&arr);

    freeString(&s1);
    freeString(&s2);
    freeIntArray(&arr);

    return 0;
}