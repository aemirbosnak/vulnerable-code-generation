//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    float height;
} Person;

int compare_name(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char line[1024];
    char delimiter = ',';
    Person *people = NULL;
    int num_people = 0;

    file = fopen("data.csv", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, &delimiter);
        if (token == NULL) {
            continue;
        }

        num_people++;
        people = realloc(people, num_people * sizeof(Person));

        people[num_people - 1].name = token;
        token = strtok(NULL, &delimiter);
        people[num_people - 1].age = atoi(token);
        token = strtok(NULL, &delimiter);
        people[num_people - 1].height = atof(token);
    }

    fclose(file);

    qsort(people, num_people, sizeof(Person), compare_name);

    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old and %.2f meters tall.\n", people[i].name, people[i].age, people[i].height);
    }

    free(people);

    return 0;
}