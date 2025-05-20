//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int age;
    char phone[MAX_LENGTH];
    int appointment_time;
} person_t;

void add_person(person_t *people, int num_people) {
    char name[MAX_LENGTH];
    int age;
    char phone[MAX_LENGTH];
    int appointment_time;

    printf("Enter name: ");
    scanf("%s", name);
    strcpy(people[num_people].name, name);

    printf("Enter age: ");
    scanf("%d", &age);
    people[num_people].age = age;

    printf("Enter phone number: ");
    scanf("%s", phone);
    strcpy(people[num_people].phone, phone);

    printf("Enter appointment time (in minutes): ");
    scanf("%d", &appointment_time);
    people[num_people].appointment_time = appointment_time;
}

int compare_appointment_time(const void *a, const void *b) {
    const person_t *person1 = a;
    const person_t *person2 = b;

    if (person1->appointment_time < person2->appointment_time) {
        return -1;
    } else if (person1->appointment_time > person2->appointment_time) {
        return 1;
    } else {
        return 0;
    }
}

void print_person(const person_t *person) {
    printf("%s (%d years old) - %s\n", person->name, person->age, person->phone);
}

int main() {
    int num_people;
    person_t people[100];

    printf("Enter number of people: ");
    scanf("%d", &num_people);

    for (int i = 0; i < num_people; i++) {
        add_person(people, i);
    }

    qsort(people, num_people, sizeof(person_t), compare_appointment_time);

    printf("People sorted by appointment time:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    return 0;
}