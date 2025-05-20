//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    int phone_number;
} Person;

int main() {
    // Initialize an array of people
    Person people[MAX_SIZE];
    int num_people = 0;

    // Read in the data from a file
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error reading file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        int phone_number = atoi(strtok(NULL, ","));

        // Check if we need to resize the array
        if (num_people >= MAX_SIZE) {
            printf("Error: Array is full.\n");
            exit(1);
        }

        // Add the person to the array
        people[num_people].name = strdup(name);
        people[num_people].age = age;
        people[num_people].phone_number = phone_number;
        num_people++;
    }

    fclose(file);

    // Sort the array by age
    for (int i = 0; i < num_people; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[i].age > people[j].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Search for a person by name
    char search_name[100];
    printf("Enter a name to search for: ");
    scanf("%s", search_name);

    int index = -1;
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, search_name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Person not found.\n");
    } else {
        printf("Name: %s\n", people[index].name);
        printf("Age: %d\n", people[index].age);
        printf("Phone number: %d\n", people[index].phone_number);
    }

    return 0;
}