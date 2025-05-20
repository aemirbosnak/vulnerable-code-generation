//Falcon-180B DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

void write_data(FILE *file, Person *person) {
    fprintf(file, "%s %d\n", person->name, person->age);
}

Person read_data(FILE *file) {
    Person person;
    fscanf(file, "%s %d", person.name, &person.age);
    return person;
}

int main() {
    FILE *file;
    Person person;
    char filename[MAX_SIZE];
    int choice;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        exit(1);
    }

    do {
        printf("\n");
        printf("1. Add data\n");
        printf("2. Read data\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", person.name);
                printf("Enter age: ");
                scanf("%d", &person.age);
                write_data(file, &person);
                break;
            case 2:
                person = read_data(file);
                printf("Name: %s\n", person.name);
                printf("Age: %d\n", person.age);
                break;
            case 3:
                fclose(file);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}