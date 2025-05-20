//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINES 100

typedef struct {
    char* name;
    int age;
    float height;
} Person;

int main() {
    int num_people = 0;
    int num_lines = 0;
    char* line = NULL;
    char* person[MAX_LINES];
    int i = 0;
    int j = 0;
    int k = 0;

    Person people[MAX_LINES];

    while (1) {
        if (scanf("%s", person[i++])!= 1) {
            break;
        }

        if (strcmp(person[i - 1], "END") == 0) {
            num_people++;
            num_lines++;
        }
    }

    for (i = 0; i < num_people; i++) {
        int length = strlen(person[i]);
        int name_length = 0;
        int age_length = 0;
        int height_length = 0;

        if (length >= MAX_LINES) {
            printf("Too many people!\n");
            return 1;
        }

        person[i][length] = '\0';

        name_length = strlen(person[i]) - 1;
        age_length = strlen(person[i]) - name_length - 1;
        height_length = strlen(person[i]) - name_length - age_length - 1;

        people[j].name = malloc(name_length + 1);
        strcpy(people[j].name, person[i]);
        people[j].age = atoi(person[i] + name_length + 1);
        people[j].height = atof(person[i] + name_length + age_length + 1);
        j++;
    }

    printf("Number of people: %d\n", num_people);
    printf("Number of lines: %d\n", num_lines);

    for (i = 0; i < num_people; i++) {
        printf("%s is %d years old and is %.2f cm tall.\n", people[i].name, people[i].age, people[i].height);
    }

    free(line);

    return 0;
}