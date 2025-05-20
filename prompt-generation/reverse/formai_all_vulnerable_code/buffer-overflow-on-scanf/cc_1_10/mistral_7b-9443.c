//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    char name[SIZE];
    int age;
    float height;
    char occupation[SIZE];
} Person;

void cSearch(Person arr[], char key[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(arr[i].occupation, key) == 0) {
            printf("Person found:\n");
            printf("Name: %s\n", arr[i].name);
            printf("Age: %d\n", arr[i].age);
            printf("Height: %.2f\n", arr[i].height);
            printf("Occupation: %s\n", arr[i].occupation);
            return;
        }
    }
    printf("Person not found.\n");
}

int main() {
    Person people[5];
    char searchKey[SIZE];

    // Input people data
    for (int i = 0; i < 5; i++) {
        printf("Enter name %d: ", i + 1);
        scanf("%s", people[i].name);
        printf("Enter age %d: ", i + 1);
        scanf("%d", &people[i].age);
        printf("Enter height %d: ", i + 1);
        scanf("%f", &people[i].height);
        printf("Enter occupation %d: ", i + 1);
        scanf("%s", people[i].occupation);
    }

    // Input search key
    printf("Enter occupation to search: ");
    scanf("%s", searchKey);

    // Search for the person
    cSearch(people, searchKey, 5);

    return 0;
}