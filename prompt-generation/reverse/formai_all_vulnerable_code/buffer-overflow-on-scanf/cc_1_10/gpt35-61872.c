//FormAI DATASET v1.0 Category: Database querying ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
    char city[30];
} Person;

void add_person(char *name, int age, char *city) {
    FILE *fp;
    fp = fopen("people.db", "ab");

    if (fp == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    Person person;
    strcpy(person.name, name);
    person.age = age;
    strcpy(person.city, city);

    fwrite(&person, sizeof(Person), 1, fp);
    fclose(fp);
}

void search_person(char *name) {
    FILE *fp;
    fp = fopen("people.db", "rb");

    if (fp == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    int found = 0;
    Person person;

    while (fread(&person, sizeof(Person), 1, fp)) {
        if (strcmp(person.name, name) == 0) {
            printf("Name: %s\nAge: %d\nCity: %s\n\n", person.name, person.age, person.city);
            found = 1;
        }
    }

    if (!found) {
        printf("No record found for %s\n", name);
    }

    fclose(fp);
}

int main() {
    char choice;
    char name[30], city[30];
    int age;

    printf("Distributed Database Querying\n");
    printf("=============================\n\n");

    while (1) {
        printf("Enter choice:\n");
        printf("1. Add person\n");
        printf("2. Search person\n");
        printf("3. Quit\n\n");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter city: ");
                scanf("%s", city);

                add_person(name, age, city);
                break;
                
            case '2':
                printf("Enter name to search: ");
                scanf("%s", name);

                search_person(name);
                break;
                
            case '3':
                exit(0);
                
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}