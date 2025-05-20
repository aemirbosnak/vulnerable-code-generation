//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

int search(Person* people, int num_people, char* name) {
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        printf("Enter name (or type 'done' to finish): ");
        char name[MAX_SIZE];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter age: ");
        int age;
        scanf("%d", &age);

        strcpy(people[num_people].name, name);
        people[num_people].age = age;
        num_people++;
    }

    char search_name[MAX_SIZE];
    printf("Enter name to search for: ");
    scanf("%s", search_name);

    int result = search(people, num_people, search_name);

    if (result == -1) {
        printf("Name not found.\n");
    } else {
        printf("Name found at index %d.\n", result);
    }

    return 0;
}