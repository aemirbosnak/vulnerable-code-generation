//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

int main() {
    Person *people = NULL;
    int num_people = 0;
    char line[100];

    // Read in the number of people
    printf("Enter the number of people: ");
    scanf("%d", &num_people);

    // Allocate memory for the people array
    people = (Person *) malloc(num_people * sizeof(Person));

    // Read in the data for each person
    for (int i = 0; i < num_people; i++) {
        printf("Enter name for person %d: ", i+1);
        scanf("%s", line);
        people[i].name = strdup(line);

        printf("Enter age for person %d: ", i+1);
        scanf("%d", &people[i].age);

        printf("Enter gender for person %d (M/F): ", i+1);
        scanf("%s", line);
        people[i].gender = strdup(line);
    }

    // Print out the data for each person
    printf("\nName\tAge\tGender\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s\t%d\t%s\n", people[i].name, people[i].age, people[i].gender);
    }

    // Free the memory used by the people array
    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
        free(people[i].gender);
    }
    free(people);

    return 0;
}