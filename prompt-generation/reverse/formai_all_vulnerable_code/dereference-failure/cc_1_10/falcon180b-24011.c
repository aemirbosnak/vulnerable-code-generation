//Falcon-180B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 80
#define MAX_NAME_SIZE 20

typedef struct {
    char name[MAX_NAME_SIZE];
    char address[MAX_LINE_SIZE];
    char phone[MAX_LINE_SIZE];
} Person;

void read_file(FILE *file, Person *people, int *num_people) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        int i = 0;
        while (line[i]!= '\n' && line[i]!= '\r') {
            if (line[i] == ',') {
                line[i] = '\0';
                strcpy(people[*num_people].name, &line[0]);
                i++;
            }
            else {
                i++;
            }
        }
        i++;
        strcpy(people[*num_people].address, &line[i]);
        i += strlen(people[*num_people].address) + 1;
        strcpy(people[*num_people].phone, &line[i]);
        i += strlen(people[*num_people].phone) + 1;
        (*num_people)++;
    }
}

void write_file(FILE *file, Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%s,%s\n", people[i].name, people[i].address, people[i].phone);
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    Person people[100];
    int num_people = 0;

    read_file(input_file, people, &num_people);

    for (int i = 0; i < num_people; i++) {
        printf("%s %s %s\n", people[i].name, people[i].address, people[i].phone);
    }

    write_file(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    return 0;
}