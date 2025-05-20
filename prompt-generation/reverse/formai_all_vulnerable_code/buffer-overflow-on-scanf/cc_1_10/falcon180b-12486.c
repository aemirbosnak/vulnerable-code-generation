//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the size of the array
#define SIZE 10

// define the structure of the element in the array
struct element {
    char name[30];
    int value;
};

// define the function to search for an element in the array
void search(struct element arr[], char name[], int *index) {
    int i;
    for(i = 0; i < SIZE; i++) {
        if(strcmp(arr[i].name, name) == 0) {
            *index = i;
            return;
        }
    }
    *index = -1; // if the element is not found, set the index to -1
}

int main() {
    int i, choice, index;
    char name[30];
    struct element arr[SIZE];

    // initialize the array with some elements
    strcpy(arr[0].name, "apple");
    arr[0].value = 1;
    strcpy(arr[1].name, "banana");
    arr[1].value = 2;
    strcpy(arr[2].name, "cherry");
    arr[2].value = 3;
    strcpy(arr[3].name, "date");
    arr[3].value = 4;
    strcpy(arr[4].name, "elderberry");
    arr[4].value = 5;
    strcpy(arr[5].name, "fig");
    arr[5].value = 6;
    strcpy(arr[6].name, "grape");
    arr[6].value = 7;
    strcpy(arr[7].name, "honeydew");
    arr[7].value = 8;
    strcpy(arr[8].name, "kiwi");
    arr[8].value = 9;
    strcpy(arr[9].name, "lemon");
    arr[9].value = 10;

    // display the menu
    printf("Enter your choice:\n");
    printf("1. Search for an element\n");
    printf("2. Exit\n");
    scanf("%d", &choice);

    // if the choice is to search for an element
    if(choice == 1) {
        printf("Enter the name of the element to search for:\n");
        scanf("%s", name);
        search(arr, name, &index);
        if(index == -1) {
            printf("Element not found!\n");
        }
        else {
            printf("Element found at index %d with value %d\n", index, arr[index].value);
        }
    }
    // if the choice is to exit
    else if(choice == 2) {
        exit(0);
    }
    // if the choice is invalid
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}