//Falcon-180B DATASET v1.0 Category: Database querying ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_AGE 150

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Person;

int main() {
    Person people[5] = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 35}, {"David", 40}, {"Eve", 45}};
    int num_people = sizeof(people) / sizeof(Person);

    // Sort by age in ascending order
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[j].age < people[i].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Print sorted list
    printf("Sorted by age in ascending order:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }

    // Search for a specific person
    char search_name[MAX_NAME_LEN];
    printf("\nEnter a name to search for: ");
    scanf("%s", search_name);

    Person* found_person = NULL;
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, search_name) == 0) {
            found_person = &people[i];
            break;
        }
    }

    if (found_person!= NULL) {
        printf("\n%s is %d years old.\n", found_person->name, found_person->age);
    } else {
        printf("\n%s not found.\n", search_name);
    }

    return 0;
}