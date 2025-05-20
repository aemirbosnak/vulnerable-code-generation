//Falcon-180B DATASET v1.0 Category: Memory management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *title;
    int *skills;
    int num_skills;
} Person;

void create_person(Person *person) {
    person->name = (char *) malloc(MAX_SIZE * sizeof(char));
    person->age = 0;
    person->title = (char *) malloc(MAX_SIZE * sizeof(char));
    person->skills = (int *) malloc(MAX_SIZE * sizeof(int));
    person->num_skills = 0;
}

void destroy_person(Person *person) {
    free(person->name);
    free(person->title);
    free(person->skills);
}

void set_name(Person *person, char *name) {
    strcpy(person->name, name);
}

void set_age(Person *person, int age) {
    person->age = age;
}

void set_title(Person *person, char *title) {
    strcpy(person->title, title);
}

void add_skill(Person *person, int skill) {
    person->skills[person->num_skills++] = skill;
}

int main() {
    Person king;
    create_person(&king);

    set_name(&king, "King Arthur");
    set_age(&king, 35);
    set_title(&king, "King of Camelot");

    add_skill(&king, 1); //sword fighting
    add_skill(&king, 2); //horse riding
    add_skill(&king, 3); //leadership

    printf("Name: %s\n", king.name);
    printf("Age: %d\n", king.age);
    printf("Title: %s\n", king.title);
    printf("Skills:\n");

    for(int i = 0; i < king.num_skills; i++) {
        printf("%d ", king.skills[i]);
    }

    destroy_person(&king);

    return 0;
}