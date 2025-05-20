//Falcon-180B DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char name[MAX_LINE_LENGTH];
    int age;
} Person;

int main() {
    FILE *file;
    Person *people = NULL;
    int num_people = 0;
    int max_people = 100;

    file = fopen("people.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int age;
        if (sscanf(line, "%s %d", people[num_people].name, &age)!= 2) {
            printf("Error: Invalid line format.\n");
            return 2;
        }
        people[num_people].age = age;
        num_people++;

        if (num_people == max_people) {
            printf("Error: Reached maximum number of people.\n");
            return 3;
        }
    }

    fclose(file);

    printf("Number of people: %d\n", num_people);

    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }

    free(people);

    return 0;
}