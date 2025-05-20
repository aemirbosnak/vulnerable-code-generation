//FormAI DATASET v1.0 Category: Database querying ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_RECORDS 10

typedef struct {
    char name[MAX_LEN];
    int age;
    char gender[MAX_LEN];
} Person;

int main() {
    // Declare and initialize an array of Person structs
    Person people[MAX_RECORDS] = {
        {"Alice", 25, "female"},
        {"Bob", 30, "male"},
        {"Charlie", 20, "male"},
        {"Diana", 27, "female"},
        {"Edward", 22, "male"},
        {"Fiona", 29, "female"},
        {"Greg", 35, "male"},
        {"Hannah", 24, "female"},
        {"Isaac", 26, "male"},
        {"Jane", 33, "female"}
    };

    printf("Welcome to the People Database!\n");

    while (1) {
        printf("\nWhat would you like to search for? (name, age, gender, quit): ");
        char query[MAX_LEN];
        fgets(query, MAX_LEN, stdin);
        query[strcspn(query, "\n")] = '\0'; // Remove trailing newline

        if (strcmp(query, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        if (strcmp(query, "name") == 0) {
            printf("Enter the name you would like to search for: ");
            char name[MAX_LEN];
            fgets(name, MAX_LEN, stdin);
            name[strcspn(name, "\n")] = '\0'; // Remove trailing newline

            int count = 0;
            for (int i = 0; i < MAX_RECORDS; i++) {
                if (strcmp(people[i].name, name) == 0) {
                    printf("%s %d %s\n", people[i].name, people[i].age, people[i].gender);
                    count++;
                }
            }

            if (count == 0) {
                printf("No records found for %s\n", name);
            } else {
                printf("Found %d record%s for %s\n", count, count == 1 ? "" : "s", name);
            }
        }

        if (strcmp(query, "age") == 0) {
            printf("Enter the age you would like to search for: ");
            int age;
            scanf("%d", &age);
            getchar(); // Remove trailing newline

            int count = 0;
            for (int i = 0; i < MAX_RECORDS; i++) {
                if (people[i].age == age) {
                    printf("%s %d %s\n", people[i].name, people[i].age, people[i].gender);
                    count++;
                }
            }

            if (count == 0) {
                printf("No records found for age %d\n", age);
            } else {
                printf("Found %d record%s for age %d\n", count, count == 1 ? "" : "s", age);
            }
        }

        if (strcmp(query, "gender") == 0) {
            printf("Enter the gender you would like to search for: ");
            char gender[MAX_LEN];
            fgets(gender, MAX_LEN, stdin);
            gender[strcspn(gender, "\n")] = '\0'; // Remove trailing newline

            int count = 0;
            for (int i = 0; i < MAX_RECORDS; i++) {
                if (strcmp(people[i].gender, gender) == 0) {
                    printf("%s %d %s\n", people[i].name, people[i].age, people[i].gender);
                    count++;
                }
            }

            if (count == 0) {
                printf("No records found for %s\n", gender);
            } else {
                printf("Found %d record%s for %s\n", count, count == 1 ? "" : "s", gender);
            }
        }
    }

    return 0;
}