//Falcon-180B DATASET v1.0 Category: Database querying ; Style: relaxed
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
    FILE *fp;
    Person *people = NULL;
    int num_people = 0;
    int i;

    // Open the database file
    fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Error opening database file.\n");
        exit(1);
    }

    // Read in the number of people in the database
    if (fscanf(fp, "%d", &num_people)!= 1) {
        printf("Error reading number of people.\n");
        exit(1);
    }

    // Allocate memory for the people array
    people = malloc(num_people * sizeof(Person));
    if (people == NULL) {
        printf("Error allocating memory for people array.\n");
        exit(1);
    }

    // Read in the people from the database
    for (i = 0; i < num_people; i++) {
        if (fscanf(fp, "%s %d", people[i].name, &people[i].age)!= 2) {
            printf("Error reading person %d.\n", i);
            exit(1);
        }
    }

    // Close the database file
    fclose(fp);

    // Sort the people by age
    for (i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[j].age < people[i].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Print the sorted list of people
    printf("Sorted list of people:\n");
    for (i = 0; i < num_people; i++) {
        printf("%s %d\n", people[i].name, people[i].age);
    }

    // Free the memory allocated for the people array
    free(people);

    return 0;
}