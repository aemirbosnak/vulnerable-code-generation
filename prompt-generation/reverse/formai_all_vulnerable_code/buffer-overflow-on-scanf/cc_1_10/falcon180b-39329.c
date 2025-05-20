//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
} person;

void create_array(person arr[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", arr[i].name);
        printf("Enter age for person %s: ", arr[i].name);
        scanf("%d", &arr[i].age);
    }
}

int binary_search(person arr[], int size, char target_name[]) {
    int left = 0;
    int right = size - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(strcmp(arr[mid].name, target_name) == 0) {
            return mid;
        } else if(strcmp(arr[mid].name, target_name) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    person arr[MAX_SIZE];
    int size;

    printf("Enter number of people: ");
    scanf("%d", &size);

    create_array(arr, size);

    char target_name[MAX_SIZE];
    printf("Enter name to search for: ");
    scanf("%s", target_name);

    int index = binary_search(arr, size, target_name);

    if(index == -1) {
        printf("Name not found.\n");
    } else {
        printf("Name found at index %d.\n", index);
        printf("Name: %s\n", arr[index].name);
        printf("Age: %d\n", arr[index].age);
    }

    return 0;
}