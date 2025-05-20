//Falcon-180B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct {
    char name[50];
    int age;
} person;

person *create_person(char *name, int age) {
    person *p = (person *)malloc(sizeof(person));
    if (p == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    strcpy(p->name, name);
    p->age = age;
    return p;
}

void delete_person(person *p) {
    free(p);
    printf("Person %s deleted.\n", p->name);
}

void display_people(person *people, int num_people) {
    printf("People:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }
}

int main() {
    person *people[SIZE];
    int num_people = 0;

    while (num_people < SIZE) {
        char name[50];
        int age;
        printf("Enter a name and age for a person:\n");
        scanf("%s %d", name, &age);
        people[num_people] = create_person(name, age);
        num_people++;
    }

    printf("Displaying people:\n");
    display_people(people, num_people);

    while (1) {
        char choice;
        printf("Enter D to delete a person, E to exit:\n");
        scanf(" %c", &choice);
        if (choice == 'D' || choice == 'd') {
            int index;
            printf("Enter the index of the person to delete:\n");
            scanf("%d", &index);
            if (index >= 0 && index < num_people) {
                delete_person(people[index]);
                num_people--;
                for (int i = index; i < num_people; i++) {
                    people[i] = people[i+1];
                }
            }
        } else if (choice == 'E' || choice == 'e') {
            break;
        }
    }

    for (int i = 0; i < num_people; i++) {
        delete_person(people[i]);
    }

    return 0;
}