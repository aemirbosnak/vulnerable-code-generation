//Falcon-180B DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char name[20];
    int age;
    float height;
} Person;

void read_csv_file(FILE *file, Person *people, int num_people) {
    char line[MAX_LINE_SIZE];
    int i = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, ",");
        strcpy(people[i].name, token);
        token = strtok(NULL, ",");
        people[i].age = atoi(token);
        token = strtok(NULL, ",");
        people[i].height = atof(token);
        i++;
    }
}

void write_csv_file(FILE *file, Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d,%f\n", people[i].name, people[i].age, people[i].height);
    }
}

void sort_people_by_age(Person *people, int num_people) {
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[i].age > people[j].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
}

int main() {
    FILE *input_file = fopen("data.csv", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE *output_file = fopen("sorted_data.csv", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    Person people[100];
    int num_people = 0;

    read_csv_file(input_file, people, 100);
    num_people = 100;

    sort_people_by_age(people, num_people);

    write_csv_file(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    return 0;
}