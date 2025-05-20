//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000
#define MAX_COLUMNS 10
#define MAX_ROWS 10

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

Person *create_person(char *name, int age, char *email) {
    Person *person = (Person*)malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->email = strdup(email);
    return person;
}

int compare_names(const void *a, const void *b) {
    char *name1 = ((Person*)a)->name;
    char *name2 = ((Person*)b)->name;
    return strcmp(name1, name2);
}

int compare_ages(const void *a, const void *b) {
    int age1 = ((Person*)a)->age;
    int age2 = ((Person*)b)->age;
    return age1 - age2;
}

int compare_emails(const void *a, const void *b) {
    char *email1 = ((Person*)a)->email;
    char *email2 = ((Person*)b)->email;
    return strcmp(email1, email2);
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Email: %s\n", person->email);
}

int main() {
    Person *people[MAX_ROWS];
    int num_people = 0;

    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line[MAX_SIZE];
    char *token;
    while (fgets(line, MAX_SIZE, file)!= NULL) {
        token = strtok(line, ",");
        char *name = strdup(token);
        token = strtok(NULL, ",");
        int age = atoi(token);
        token = strtok(NULL, ",");
        char *email = strdup(token);

        Person *person = create_person(name, age, email);
        people[num_people++] = person;
    }

    fclose(file);

    qsort(people, num_people, sizeof(Person*), compare_names);
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    return 0;
}