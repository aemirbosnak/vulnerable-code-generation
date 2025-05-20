//FormAI DATASET v1.0 Category: Database querying ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 20
#define MAX_DATA_ROWS 100

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int age;
} Person;

int main() {

    // initialize an array of Person objects
    Person people[MAX_DATA_ROWS] = {
        {1, "John", 23},
        {2, "Jane", 32},
        {3, "Mike", 45}
    };

    // get user input for query parameters
    int id;
    char name[MAX_NAME_LEN];
    int age;

    printf("Enter search parameters:\n");
    printf("ID (enter 0 if not searching by ID): ");
    scanf("%d", &id);
    printf("Name (enter 'none' if not searching by name): ");
    scanf("%s", name);
    printf("Age (enter 0 if not searching by age): ");
    scanf("%d", &age);

    // initialize an array to hold matching results
    Person results[MAX_DATA_ROWS];
    int count = 0;

    // loop through the data array to find matches
    for (int i = 0; i < MAX_DATA_ROWS; i++) {
        if (id > 0 && people[i].id == id) {
            results[count] = people[i];
            count++;
        }
        if (strcmp(name, "none") != 0 && strcmp(people[i].name, name) == 0) {
            results[count] = people[i];
            count++;
        }
        if (age > 0 && people[i].age == age) {
            results[count] = people[i];
            count++;
        }

        // break loop if no more matches can be found
        if (id > 0 && people[i].id > id) break;
        if (strcmp(name, "none") != 0 && strcmp(people[i].name, name) > 0) break;
        if (age > 0 && people[i].age > age) break;
    }

    // print out the matching results
    printf("%d match(es) found.\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d. ID: %d, Name: %s, Age: %d\n", i+1, results[i].id, results[i].name, results[i].age);
    }

    return 0;
}