//Code Llama-13B DATASET v1.0 Category: Database querying ; Style: creative
/*
 * Created by [Your Name]
 * A unique C database querying example program in a creative style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 256
#define MAX_DB_SIZE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char gender;
} Person;

void print_person(Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Gender: %c\n", p.gender);
}

int main() {
    Person database[MAX_DB_SIZE];
    int num_people = 0;

    while (1) {
        printf("Enter a person's information (name, age, gender): ");
        char name[MAX_NAME_LEN];
        int age;
        char gender;
        scanf("%s %d %c", name, &age, &gender);

        Person p = {name, age, gender};
        database[num_people] = p;
        num_people++;

        printf("Enter another person's information (type 'exit' to stop): ");
        if (strcmp(name, "exit") == 0) {
            break;
        }
    }

    printf("--- Database Contents ---\n");
    for (int i = 0; i < num_people; i++) {
        print_person(database[i]);
    }

    return 0;
}