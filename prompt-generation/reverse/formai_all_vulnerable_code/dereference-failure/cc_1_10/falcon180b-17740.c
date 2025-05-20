//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

int search_person(Person *persons, int num_persons, char *name) {
    for (int i = 0; i < num_persons; i++) {
        if (strcmp(persons[i].name, name) == 0) {
            printf("Age of %s is %d\n", persons[i].name, persons[i].age);
            return i;
        }
    }
    printf("Person not found\n");
    return -1;
}

int main() {
    Person persons[MAX_SIZE];
    int num_persons = 0;

    FILE *fp = fopen("persons.txt", "r");
    if (fp == NULL) {
        printf("File not found\n");
        return 1;
    }

    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, fp)!= NULL) {
        if (num_persons == MAX_SIZE) {
            printf("Maximum limit reached\n");
            break;
        }
        char *token = strtok(line, ",");
        strcpy(persons[num_persons].name, token);
        token = strtok(NULL, ",");
        persons[num_persons].age = atoi(token);
        num_persons++;
    }

    fclose(fp);

    int choice, search_result;
    do {
        printf("1. Search by name\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char search_name[MAX_SIZE];
            printf("Enter name to search: ");
            scanf("%s", search_name);
            search_result = search_person(persons, num_persons, search_name);
        }
    } while (choice!= 2);

    return 0;
}