//Falcon-180B DATASET v1.0 Category: File handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

int main() {
    FILE *file;
    char filename[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    char *token;
    Person *people = NULL;
    int num_people = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            if (num_people == 0) {
                people = malloc(sizeof(Person));
                num_people++;
            } else {
                people = realloc(people, sizeof(Person) * num_people);
            }

            if (people == NULL) {
                printf("Error allocating memory.\n");
                exit(1);
            }

            if (num_people == 1) {
                strcpy(people->name, token);
            } else if (num_people == 2) {
                people->age = atoi(token);
            } else if (num_people == 3) {
                strcpy(people->gender, token);
            }

            token = strtok(NULL, ",");
        }
        num_people++;
    }

    fclose(file);

    printf("Name\tAge\tGender\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s\t%d\t%s\n", people[i].name, people[i].age, people[i].gender);
    }

    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
        free(people[i].gender);
    }
    free(people);

    return 0;
}