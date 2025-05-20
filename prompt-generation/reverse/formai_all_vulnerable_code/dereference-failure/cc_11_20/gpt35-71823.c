//FormAI DATASET v1.0 Category: Database querying ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_RESULTS 10

typedef struct {
    int id;
    char name[MAX_STRING_LENGTH];
    int age;
} Person;

int main() {
    FILE *fp;
    char filename[MAX_STRING_LENGTH];
    int num_people;
    Person *people;
    char query[MAX_STRING_LENGTH];
    int results[MAX_RESULTS];
    int num_results = 0;
    int i;

    // Read in the filename and number of people
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter number of people: ");
    scanf("%d", &num_people);

    // Allocate memory for people array
    people = malloc(num_people * sizeof(Person));
    if (people == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    // Read in the people from the file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fread(people, sizeof(Person), num_people, fp);
    fclose(fp);

    // Prompt for query and find results
    printf("Enter query (in the format key=value): ");
    scanf("%s", query);
    for (i = 0; i < num_people; i++) {
        if (strcmp(query, "id=0") == 0) {
            results[num_results++] = i;
        } else if (strcmp(query, "age<30") == 0 && people[i].age < 30) {
            results[num_results++] = i;
        } else if (strcmp(query, "name=John") == 0 && strcmp(people[i].name, "John") == 0) {
            results[num_results++] = i;
        } else if (strcmp(query, "id=3") == 0 && people[i].id == 3) {
            results[num_results++] = i;
        } else if (strcmp(query, "age>40") == 0 && people[i].age > 40) {
            results[num_results++] = i;
        }
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < num_results; i++) {
        printf("id: %d, name: %s, age: %d\n", people[results[i]].id, people[results[i]].name, people[results[i]].age);
    }

    // Free memory
    free(people);

    return 0;
}