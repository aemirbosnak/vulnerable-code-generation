//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;

    if (personA->age > personB->age) {
        return 1;
    } else if (personA->age < personB->age) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    Person data[MAX_SIZE];
    int numOfData = 0;
    int choice;
    char name[MAX_SIZE];
    int age;

    do {
        printf("Enter 1 to add data\nEnter 2 to search data\nEnter 3 to display data\nEnter 4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter age: ");
            scanf("%d", &age);

            strcpy(data[numOfData].name, name);
            data[numOfData].age = age;
            numOfData++;
            break;

        case 2:
            printf("Enter name to search: ");
            scanf("%s", name);

            if (numOfData == 0) {
                printf("No data found.\n");
            } else {
                qsort(data, numOfData, sizeof(Person), compare);

                for (int i = 0; i < numOfData; i++) {
                    if (strcmp(data[i].name, name) == 0) {
                        printf("Name: %s\nAge: %d\n", data[i].name, data[i].age);
                    }
                }
            }
            break;

        case 3:
            if (numOfData == 0) {
                printf("No data found.\n");
            } else {
                printf("Data:\n");
                for (int i = 0; i < numOfData; i++) {
                    printf("Name: %s\nAge: %d\n", data[i].name, data[i].age);
                }
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }

    } while (1);

    return 0;
}