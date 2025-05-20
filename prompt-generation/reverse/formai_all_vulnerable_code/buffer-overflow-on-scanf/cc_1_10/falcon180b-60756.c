//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure of the element to be stored in the array
typedef struct {
    char name[50];
    int age;
} Person;

// Function to compare two elements
int compare(const void* a, const void* b) {
    Person* personA = (Person*)a;
    Person* personB = (Person*)b;

    if(personA->age < personB->age) {
        return -1;
    } else if(personA->age > personB->age) {
        return 1;
    } else {
        return 0;
    }
}

// Function to search for an element in the array
int search(Person arr[], int size, int age) {
    int result;
    qsort(arr, size, sizeof(Person), compare);

    for(int i=0; i<size; i++) {
        if(arr[i].age == age) {
            result = i;
            break;
        }
    }

    return result;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    Person arr[MAX_SIZE];
    printf("Enter the elements:\n");
    for(int i=0; i<size; i++) {
        scanf("%s %d", arr[i].name, &arr[i].age);
    }

    int age;
    printf("Enter the age to search for: ");
    scanf("%d", &age);

    int result = search(arr, size, age);

    if(result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at position %d.\n", result+1);
    }

    return 0;
}