//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUMBERS_PER_PERSON 3
#define MAX_PEOPLE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_numbers;
    int numbers[MAX_NUMBERS_PER_PERSON];
} Person;

int main() {
    Person people[MAX_PEOPLE];
    int num_people = 0;

    while (num_people < MAX_PEOPLE) {
        printf("Enter name (or 'done' to finish): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);
        if (strcmp(name, "done") == 0) {
            break;
        }
        num_people++;
        strcpy(people[num_people-1].name, name);
        people[num_people-1].num_numbers = 0;
    }

    printf("Enter phone numbers for each person:\n");
    for (int i = 0; i < num_people; i++) {
        printf("Enter phone numbers for %s (or 'done' to finish): ", people[i].name);
        int num_numbers = 0;
        while (num_numbers < MAX_NUMBERS_PER_PERSON && num_people < MAX_PEOPLE) {
            int num;
            scanf("%d", &num);
            people[i].numbers[num_numbers] = num;
            num_numbers++;
        }
        people[i].num_numbers = num_numbers;
    }

    printf("Phone book:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s: ", people[i].name);
        for (int j = 0; j < people[i].num_numbers; j++) {
            printf("%d ", people[i].numbers[j]);
        }
        printf("\n");
    }

    return 0;
}