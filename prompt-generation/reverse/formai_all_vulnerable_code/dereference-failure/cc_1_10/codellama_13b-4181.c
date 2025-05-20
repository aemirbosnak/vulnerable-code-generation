//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
/*
* CSV Reader Example Program
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define DELIMITER ','

typedef struct {
    char* name;
    int age;
    float height;
} Person;

void read_csv(char* filename, Person* people, int num_people) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: unable to open file %s\n", filename);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int i = 0;
    while (fgets(buffer, BUFFER_SIZE, file) != NULL && i < num_people) {
        char* token = strtok(buffer, DELIMITER);
        people[i].name = token;
        token = strtok(NULL, DELIMITER);
        people[i].age = atoi(token);
        token = strtok(NULL, DELIMITER);
        people[i].height = atof(token);
        i++;
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    int num_people = 10;
    Person people[num_people];

    read_csv(filename, people, num_people);

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s, Age: %d, Height: %.2f\n", people[i].name, people[i].age, people[i].height);
    }

    return 0;
}