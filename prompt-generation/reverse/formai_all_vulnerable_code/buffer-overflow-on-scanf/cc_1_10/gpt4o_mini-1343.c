//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int age;
} Person;

void printMenu() {
    printf("\n--- Sorting Menu ---\n");
    printf("1. Sort by Name\n");
    printf("2. Sort by Age\n");
    printf("3. Display List\n");
    printf("4. Exit\n");
    printf("--------------------\n");
}

int compareByName(const void *a, const void *b) {
    return strcmp(((Person *)a)->name, ((Person *)b)->name);
}

int compareByAge(const void *a, const void *b) {
    return ((Person *)a)->age - ((Person *)b)->age;
}

void displayPeople(Person people[], int size) {
    printf("\nDisplaying People:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }
}

void sortAndDisplayMenu() {
    Person people[MAX_SIZE];
    int count = 0;
    int choice = 0;

    printf("Welcome to the Sorting Program!\n");
    
    while (1) {
        printf("Please enter the number of people (max %d): ", MAX_SIZE);
        scanf("%d", &count);
        if (count <= 0 || count > MAX_SIZE) {
            printf("Invalid number! Please enter a value between 1 and %d.\n", MAX_SIZE);
            continue;
        }
        break;
    }

    for (int i = 0; i < count; i++) {
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", people[i].name);
        printf("Enter age for person %d: ", i + 1);
        scanf("%d", &people[i].age);
    }

    while (choice != 4) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                qsort(people, count, sizeof(Person), compareByName);
                printf("Sorted by Name:\n");
                displayPeople(people, count);
                break;
            case 2:
                qsort(people, count, sizeof(Person), compareByAge);
                printf("Sorted by Age:\n");
                displayPeople(people, count);
                break;
            case 3:
                displayPeople(people, count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    sortAndDisplayMenu();
    return 0;
}