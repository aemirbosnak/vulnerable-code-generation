//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// function to search for a string in an array of strings
int searchArray(char *arr[], int size, char *searchStr) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(arr[i], searchStr) == 0) {
            return i;
        }
    }
    return -1; // string not found
}

// function to sort an array of strings in alphabetical order
void sortArray(char *arr[], int size) {
    int i, j;
    char temp[MAX_SIZE];
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main() {
    int i, j, size;
    char inputStr[MAX_SIZE];
    char searchStr[MAX_SIZE];
    char *arr[MAX_SIZE];

    // prompt user for input
    printf("Enter a list of strings, separated by spaces:\n");
    scanf("%s", inputStr);

    // split input string into array of strings
    size = 0;
    char *token = strtok(inputStr, " ");
    while (token!= NULL) {
        arr[size++] = token;
        token = strtok(NULL, " ");
    }

    // sort array of strings
    sortArray(arr, size);

    // prompt user for search string
    printf("Enter a string to search for:\n");
    scanf("%s", searchStr);

    // search for string in array
    int index = searchArray(arr, size, searchStr);
    if (index == -1) {
        printf("String not found.\n");
    } else {
        printf("String found at index %d.\n", index);
    }

    return 0;
}