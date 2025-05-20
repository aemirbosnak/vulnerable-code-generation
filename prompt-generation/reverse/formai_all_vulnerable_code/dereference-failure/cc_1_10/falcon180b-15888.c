//Falcon-180B DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char name[MAX_LINE_LENGTH];
    int age;
    float height;
} Person;

void read_csv_file(FILE *file, Person people[], int max_people) {
    char line[MAX_LINE_LENGTH];
    int count = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",");
        strcpy(people[count].name, token);
        people[count].age = atoi(strtok(NULL, ","));
        people[count].height = atof(strtok(NULL, ","));
        count++;

        if (count == max_people) {
            break;
        }
    }
}

void write_csv_file(FILE *file, Person people[], int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%d,%.2f\n", people[i].name, people[i].age, people[i].height);
    }
}

int main() {
    FILE *input_file, *output_file;
    Person people[100];
    int count = 0;

    input_file = fopen("input.csv", "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    read_csv_file(input_file, people, 100);

    output_file = fopen("output.csv", "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    write_csv_file(output_file, people, count);

    fclose(input_file);
    fclose(output_file);

    return 0;
}