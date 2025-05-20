//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    Person data[MAX_SIZE];
    int num_entries = 0;
    char choice;
    char search_name[50];

    do {
        printf("Enter your choice:\n");
        printf("1. Add a new person\n");
        printf("2. Search for a person\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", data[num_entries].name);
                printf("Enter age: ");
                scanf("%d", &data[num_entries].age);
                num_entries++;
                break;
            case '2':
                printf("Enter name to search: ");
                scanf("%s", search_name);
                int index = search(data, num_entries, search_name);
                if (index!= -1) {
                    printf("Name: %s\n", data[index].name);
                    printf("Age: %d\n", data[index].age);
                } else {
                    printf("Person not found.\n");
                }
                break;
            case '3':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');

    return 0;
}

int search(Person data[], int num_entries, char name[]) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(data[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}