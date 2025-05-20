//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBERS_PER_PERSON 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS_PER_PERSON][20];
    int num_numbers;
} person_t;

int main() {
    int num_people = 0;
    person_t *people = NULL;

    while (1) {
        printf("Enter a name (or type 'q' to quit): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "q") == 0) {
            break;
        }

        people = realloc(people, sizeof(person_t) * ++num_people);
        strcpy(people[num_people - 1].name, name);
        people[num_people - 1].num_numbers = 0;
    }

    for (int i = 0; i < num_people; i++) {
        printf("Enter a phone number for %s (or type 'q' to finish): ", people[i].name);
        char number[20];
        scanf("%s", number);

        if (strcmp(number, "q") == 0) {
            break;
        }

        strcpy(people[i].numbers[people[i].num_numbers++], number);
    }

    printf("Phone Book:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s:\n", people[i].name);
        for (int j = 0; j < people[i].num_numbers; j++) {
            printf("\t%s\n", people[i].numbers[j]);
        }
    }

    free(people);
    return 0;
}