//Falcon-180B DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    char gender;
} Person;

void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;

    if (p1->age < p2->age) {
        return -1;
    } else if (p1->age > p2->age) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Person data[MAX_SIZE];
    int num_people = 0;

    FILE *input = fopen("data.txt", "r");

    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fscanf(input, "%s %d %c", data[num_people].name, &data[num_people].age, &data[num_people].gender)!= EOF) {
        num_people++;
    }

    fclose(input);

    qsort(data, num_people, sizeof(Person), compare);

    for (int i = 0; i < num_people; i++) {
        printf("%s %d %c\n", data[i].name, data[i].age, data[i].gender);
    }

    return 0;
}