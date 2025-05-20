//FormAI DATASET v1.0 Category: Database querying ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char address[50];
} Person;

int main() {
    int n, choice;
    printf("Enter the number of persons: ");
    scanf("%d", &n);

    Person *persons = (Person *) malloc(n * sizeof(Person));

    for (int i = 0; i < n; i++) {
        printf("Enter details for Person %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &persons[i].id);
        printf("Name: ");
        scanf("%s", persons[i].name);
        printf("Age: ");
        scanf("%d", &persons[i].age);
        printf("Address: ");
        scanf("%s", persons[i].address);
    }

    printf("\nSelect a search category:\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("3. Search by Age\n");
    printf("4. Search by Address\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter the ID to search: ");
            int idSearch;
            scanf("%d", &idSearch);
            for (int i = 0; i < n; i++) {
                if (persons[i].id == idSearch) {
                    printf("Person found!\n");
                    printf("ID: %d\n", persons[i].id);
                    printf("Name: %s\n", persons[i].name);
                    printf("Age: %d\n", persons[i].age);
                    printf("Address: %s\n", persons[i].address);
                }
            }
            break;
        case 2:
            printf("\nEnter the name to search: ");
            char nameSearch[50];
            scanf("%s", nameSearch);
            for (int i = 0; i < n; i++) {
                if (strcmp(persons[i].name, nameSearch) == 0) {
                    printf("Person found!\n");
                    printf("ID: %d\n", persons[i].id);
                    printf("Name: %s\n", persons[i].name);
                    printf("Age: %d\n", persons[i].age);
                    printf("Address: %s\n", persons[i].address);
                }
            }
            break;
        case 3:
            printf("\nEnter the age to search: ");
            int ageSearch;
            scanf("%d", &ageSearch);
            for (int i = 0; i < n; i++) {
                if (persons[i].age == ageSearch) {
                    printf("Person found!\n");
                    printf("ID: %d\n", persons[i].id);
                    printf("Name: %s\n", persons[i].name);
                    printf("Age: %d\n", persons[i].age);
                    printf("Address: %s\n", persons[i].address);
                }
            }
            break;
        case 4:
            printf("\nEnter the address to search: ");
            char addressSearch[50];
            scanf("%s", addressSearch);
            for (int i = 0; i < n; i++) {
                if (strcmp(persons[i].address, addressSearch) == 0) {
                    printf("Person found!\n");
                    printf("ID: %d\n", persons[i].id);
                    printf("Name: %s\n", persons[i].name);
                    printf("Age: %d\n", persons[i].age);
                    printf("Address: %s\n", persons[i].address);
                }
            }
            break;
    }

    free(persons);

    return 0;
}