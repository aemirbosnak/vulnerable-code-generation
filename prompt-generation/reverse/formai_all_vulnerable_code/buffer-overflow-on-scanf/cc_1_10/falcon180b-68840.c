//Falcon-180B DATASET v1.0 Category: Database querying ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_ROWS_PER_QUERY 5

typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

Person people[MAX_ROWS];
int num_people = 0;

void add_person(char *name, int age, char *gender) {
    if (num_people >= MAX_ROWS) {
        printf("Sorry, database is full!\n");
        return;
    }
    people[num_people++] = (Person) {.name = name,.age = age,.gender = gender};
}

void print_person(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Gender: %s\n", person.gender);
}

int main() {
    char input[100];
    while (1) {
        printf("Enter command (add, list, quit): ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            char name[100];
            int age;
            char gender[10];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter age: ");
            scanf("%d", &age);
            printf("Enter gender: ");
            scanf("%s", gender);
            add_person(name, age, gender);
        } else if (strcmp(input, "list") == 0) {
            int start_row = 0;
            int num_rows = num_people > MAX_ROWS_PER_QUERY? MAX_ROWS_PER_QUERY : num_people;
            printf("Enter starting row (0-%d): ", num_rows - 1);
            scanf("%d", &start_row);
            for (int i = start_row; i < start_row + num_rows; i++) {
                if (i >= num_people) {
                    printf("No data found!\n");
                    break;
                }
                print_person(people[i]);
            }
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }
    return 0;
}