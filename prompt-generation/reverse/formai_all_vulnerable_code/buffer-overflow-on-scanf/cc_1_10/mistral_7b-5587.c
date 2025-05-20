//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_LINE_LEN 255

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char occupation[MAX_NAME_LEN];
} Person;

void printPerson(Person p) {
    printf("%s, %d years old, %s\n", p.name, p.age, p.occupation);
}

void readPerson(Person *p) {
    char name[MAX_NAME_LEN];
    int age;
    char occupation[MAX_NAME_LEN];

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    strcpy(p->name, name);

    printf("Enter age: ");
    scanf("%d", &age);
    p->age = age;

    printf("Enter occupation: ");
    fgets(occupation, sizeof(occupation), stdin);
    occupation[strcspn(occupation, "\n")] = '\0';
    strcpy(p->occupation, occupation);
}

int main() {
    Person suspects[10];
    int num_suspects = 0;

    while (num_suspects < 10) {
        if (num_suspects > 0) {
            printf("\n--- NEW SUSPECT ---\n");
        }

        Person suspect;
        readPerson(&suspect);

        printf("\nNew suspect:\n");
        printPerson(suspect);

        suspects[num_suspects++] = suspect;
    }

    printf("\n--- ANALYSIS ---\n");

    for (int i = 0; i < num_suspects; i++) {
        printf("\nSuspect %d:\n", i + 1);
        printPerson(suspects[i]);

        // Add some analysis here...
    }

    return 0;
}