//Falcon-180B DATASET v1.0 Category: Memory management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    char name[20];
    int age;
} Person;

int main() {
    int num_people = 0;
    Person *people = (Person *)malloc(MAX_SIZE * sizeof(Person));

    while (1) {
        printf("Enter 1 to add a person, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            if (num_people >= MAX_SIZE) {
                printf("Error: Maximum number of people reached.\n");
            } else {
                printf("Enter the person's ID: ");
                int id;
                scanf("%d", &id);

                printf("Enter the person's name: ");
                scanf("%s", people[num_people].name);

                printf("Enter the person's age: ");
                scanf("%d", &people[num_people].age);

                num_people++;
            }
        } else {
            printf("Invalid choice.\n");
        }
    }

    for (int i = 0; i < num_people; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", people[i].id, people[i].name, people[i].age);
    }

    free(people);
    return 0;
}