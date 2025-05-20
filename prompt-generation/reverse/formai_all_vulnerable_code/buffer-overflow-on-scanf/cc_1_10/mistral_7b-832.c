//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

typedef struct {
    char name[50];
    int age;
    float height;
} Person;

void print_array(Person arr[], int n) {
    printf("\n***** Happy Search Results *****\n");
    for (int i = 0; i < n; i++) {
        printf("\nName: %s", arr[i].name);
        printf("\nAge : %d", arr[i].age);
        printf("\nHeight: %.2f", arr[i].height);
    }
}

int HappySearch(Person arr[], int low, int high, char *name_to_search, int *compares) {
    int mid;
    int comp = 0;

    if (low > high) {
        printf("\nPerson not found in the array!\n");
        return -1;
    }

    mid = (low + high) / 2;

    comp++;

    if (strcmp(arr[mid].name, name_to_search) == 0) {
        printf("\nHurray! Person found at position %d!\n", mid + 1);
        print_array(arr, mid + 1);
        return mid;
    }

    if (strcmp(arr[mid].name, name_to_search) > 0) {
        HappySearch(arr, low, mid - 1, name_to_search, compares);
    } else {
        HappySearch(arr, mid + 1, high, name_to_search, compares);
    }
}

int main() {
    Person arr[MAX];
    int n, i, choice, search_choice, compares = 0;
    char name[50];

    printf("\nWelcome to Happy Search!\n");
    printf("\nEnter the number of people to be added: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter name %d: ", i + 1);
        scanf("%s", arr[i].name);
        arr[i].age = rand() % 100 + 1;
        arr[i].height = (float) rand() / 100.0;

        printf("\nName: %s", arr[i].name);
        printf("\nAge : %d", arr[i].age);
        printf("\nHeight: %.2f\n", arr[i].height);
    }

    while (1) {
        printf("\n1. Search by name\n2. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter name to search: ");
            scanf("%s", name);

            HappySearch(arr, 0, n - 1, name, &compares);
        } else {
            printf("\nThank you for using Happy Search! Have a great day!\n");
            break;
        }
    }

    return 0;
}