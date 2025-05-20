//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 10

typedef struct {
    char name[30];
    int age;
    char gender;
    char email[50];
} Person;

void print_menu();
void add_person(Person *people, int *num_people);
void remove_person(Person *people, int *num_people);
void find_person(Person *people, int num_people);

int main() {
    Person people[MAX_ROWS];
    int num_people = 0;
    char input;

    while (1) {
        print_menu();
        scanf("%c", &input);

        switch (input) {
            case 'a':
                add_person(people, &num_people);
                break;
            case 'r':
                remove_person(people, &num_people);
                break;
            case 'f':
                find_person(people, num_people);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid input\n");
                break;
        }
    }

    return 0;
}

void print_menu() {
    printf("Menu:\n");
    printf("a. Add person\n");
    printf("r. Remove person\n");
    printf("f. Find person\n");
    printf("q. Quit\n");
}

void add_person(Person *people, int *num_people) {
    printf("Enter name: ");
    scanf("%s", people[*num_people].name);
    printf("Enter age: ");
    scanf("%d", &people[*num_people].age);
    printf("Enter gender: ");
    scanf(" %c", &people[*num_people].gender);
    printf("Enter email: ");
    scanf("%s", people[*num_people].email);

    (*num_people)++;
}

void remove_person(Person *people, int *num_people) {
    int index;

    printf("Enter index of person to remove: ");
    scanf("%d", &index);

    if (index >= 0 && index < *num_people) {
        for (int i = index; i < *num_people - 1; i++) {
            people[i] = people[i + 1];
        }
        (*num_people)--;
    } else {
        printf("Invalid index\n");
    }
}

void find_person(Person *people, int num_people) {
    int index;

    printf("Enter index of person to find: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_people) {
        printf("Person %d: %s, %d, %c, %s\n", index, people[index].name, people[index].age, people[index].gender, people[index].email);
    } else {
        printf("Invalid index\n");
    }
}