//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>

typedef struct {
    char name[20];
    char address[50];
    int phone;
}Person;

void add_person(Person *people, int *num_people) {
    printf("Enter name: ");
    scanf("%s", people[*num_people].name);
    printf("Enter address: ");
    scanf("%s", people[*num_people].address);
    printf("Enter phone number: ");
    scanf("%d", &people[*num_people].phone);
    (*num_people)++;
}

void print_person(Person person) {
    printf("Name: %s\n", person.name);
    printf("Address: %s\n", person.address);
    printf("Phone number: %d\n", person.phone);
}

void search_person(Person *people, int num_people, char *name) {
    int i;
    for(i=0; i<num_people; i++) {
        if(strcmp(people[i].name, name) == 0) {
            print_person(people[i]);
            return;
        }
    }
    printf("Person not found.\n");
}

int main() {
    Person people[100];
    int num_people = 0;

    add_person(people, &num_people);
    add_person(people, &num_people);
    add_person(people, &num_people);

    printf("Enter name to search: ");
    char name[20];
    scanf("%s", name);

    search_person(people, num_people, name);

    return 0;
}