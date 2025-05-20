//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_QUERY_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
} Person;

int main() {
    FILE *db = fopen("romeo_and_juliet.db", "r");
    if (db == NULL) {
        printf("Error: could not open database.\n");
        return 1;
    }

    Person *people = (Person *) malloc(100 * sizeof(Person));
    int num_people = 0;

    char query[MAX_QUERY_LENGTH];
    while (fgets(query, MAX_QUERY_LENGTH, db)!= NULL) {
        if (query[0] == 'I') { // Insertion query
            char name[MAX_NAME_LENGTH];
            int age;
            char gender;
            sscanf(query, "I %s %d %c", name, &age, &gender);
            strcpy(people[num_people].name, name);
            people[num_people].age = age;
            people[num_people].gender = gender;
            num_people++;
        } else if (query[0] == 'S') { // Selection query
            char name[MAX_NAME_LENGTH];
            sscanf(query, "S %s", name);
            int i;
            for (i = 0; i < num_people; i++) {
                if (strcmp(people[i].name, name) == 0) {
                    printf("Name: %s\nAge: %d\nGender: %c\n", people[i].name, people[i].age, people[i].gender);
                    break;
                }
            }
        }
    }

    fclose(db);
    return 0;
}