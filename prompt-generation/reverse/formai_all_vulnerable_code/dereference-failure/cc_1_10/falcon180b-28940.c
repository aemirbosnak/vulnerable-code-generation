//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    char *occupation;
    int age;
} Person;

Person *generate_person(void) {
    static char *names[] = {"John", "Jane", "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Heidi"};
    static char *occupations[] = {"doctor", "lawyer", "engineer", "teacher", "artist", "musician", "writer", "programmer", "chef", "scientist"};
    Person *person = malloc(sizeof(Person));
    person->name = names[rand() % 10];
    person->occupation = occupations[rand() % 10];
    person->age = rand() % 101;
    return person;
}

void print_person(const Person *person) {
    printf("%s, a %s aged %d.\n", person->name, person->occupation, person->age);
}

int main(void) {
    srand(time(NULL));
    Person *victim = generate_person();
    Person *culprit = generate_person();
    printf("In the small town of ");
    for (int i = 0; i < 5; i++) {
        printf("%c", rand() % 26 + 'A');
    }
    printf(" lived two individuals: ");
    print_person(victim);
    printf(" and ");
    print_person(culprit);
    printf("\n");
    printf("One day, ");
    printf("%s was found dead in their home.", victim->name);
    printf("\n");
    printf("The local constable, baffled by the case, enlisted the help of the renowned detective, Sherlock Holmes.\n");
    printf("After a thorough investigation, Holmes deduced that the culprit was none other than ");
    print_person(culprit);
    printf("\n");
    printf("When confronted with the evidence, ");
    printf("%s confessed to the crime.", culprit->name);
    printf("\n");
    printf("The motive? A petty argument over a ");
    switch (rand() % 6) {
        case 0:
            printf("book");
            break;
        case 1:
            printf("painting");
            break;
        case 2:
            printf("piece of jewelry");
            break;
        case 3:
            printf("recipe");
            break;
        case 4:
            printf("musical instrument");
            break;
        case 5:
            printf("scientific discovery");
            break;
    }
    printf(".\n");
    printf("Justice was served, and the town of ");
    for (int i = 0; i < 5; i++) {
        printf("%c", rand() % 26 + 'A');
    }
    printf(" could rest easy once more.\n");
    return 0;
}