//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 120

struct person {
    char name[MAX_NAME_LENGTH];
    int age;
};

void init_person(struct person *person) {
    person->name[0] = '\0';
    person->age = 0;
}

int get_name(struct person *person, char *buffer) {
    printf("Enter your name: ");
    fgets(buffer, MAX_NAME_LENGTH, stdin);
    return strlen(buffer);
}

int get_age(struct person *person) {
    printf("Enter your age: ");
    scanf("%d", &person->age);
    return person->age;
}

void print_person(struct person person) {
    printf("Name: %s\nAge: %d\n", person.name, person.age);
}

int main() {
    struct person person;
    init_person(&person);

    // Try to get the name and age
    int name_len = get_name(&person, person.name);
    if (name_len == 0) {
        printf("Error: No name entered\n");
        return 1;
    }

    int age = get_age(&person);
    if (age == 0) {
        printf("Error: No age entered\n");
        return 1;
    }

    // Check if the name is too long
    if (name_len > MAX_NAME_LENGTH) {
        printf("Error: Name too long (max %d characters)\n", MAX_NAME_LENGTH);
        return 1;
    }

    // Check if the age is too high
    if (age > MAX_AGE) {
        printf("Error: Age too high (max %d years)\n", MAX_AGE);
        return 1;
    }

    // Print the person's details
    print_person(person);

    return 0;
}