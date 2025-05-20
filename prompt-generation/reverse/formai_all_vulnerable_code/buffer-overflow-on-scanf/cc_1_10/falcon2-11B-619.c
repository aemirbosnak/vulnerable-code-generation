//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    char name[50];
    int age;
    char occupation[50];
} person;

person people[100];

void insert(person p) {
    int i;
    for (i = 0; i < 100; i++) {
        if (strcmp(p.name, people[i].name) == 0) {
            printf("ERROR: Name already exists\n");
            return;
        }
    }
    strcpy(people[i].name, p.name);
    people[i].age = p.age;
    strcpy(people[i].occupation, p.occupation);
    printf("Person inserted successfully\n");
}

void print() {
    int i;
    for (i = 0; i < 100; i++) {
        printf("%s - %d - %s\n", people[i].name, people[i].age, people[i].occupation);
    }
}

int main() {
    srand(time(NULL));

    char name[50], occupation[50];
    int age;
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter occupation: ");
    scanf("%s", occupation);

    person p = {name, age, occupation};
    insert(p);

    printf("--------------------------------------\n");
    print();

    return 0;
}