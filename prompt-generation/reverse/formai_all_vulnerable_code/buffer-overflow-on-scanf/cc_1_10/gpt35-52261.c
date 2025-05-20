//FormAI DATASET v1.0 Category: Database simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    int age;
    char address[MAX_LENGTH];
} Person;

int main() {
    int option;
    Person *people = NULL;
    int num_people = 0;

    while (1) {
        printf("Options:\n");
        printf("1. Add person\n");
        printf("2. Remove person\n");
        printf("3. Print all people\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                Person person;

                printf("Enter name: ");
                scanf("%s", person.name);
                printf("Enter age: ");
                scanf("%d", &person.age);
                printf("Enter address: ");
                scanf("%s", person.address);

                people = realloc(people, (num_people + 1) * sizeof(Person));
                people[num_people] = person;
                num_people++;

                printf("Person added successfully!\n");
                break;
            }
            case 2: {
                int index;

                printf("Enter index to remove: ");
                scanf("%d", &index);

                if (index < 0 || index >= num_people) {
                    printf("Invalid index!\n");
                    break;
                }

                for (int i = index; i < num_people - 1; i++) {
                    people[i] = people[i + 1];
                }

                people = realloc(people, (num_people - 1) * sizeof(Person));
                num_people--;

                printf("Person removed successfully!\n");
                break;
            }
            case 3: {
                printf("Total people: %d\n", num_people);

                for (int i = 0; i < num_people; i++) {
                    printf("%d. %s, %d, %s\n", i, people[i].name, people[i].age, people[i].address);
                }

                break;
            }
            case 4: {
                printf("Exiting, goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid option selected!\n");
                break;
            }
        }
    }

    return 0;
}