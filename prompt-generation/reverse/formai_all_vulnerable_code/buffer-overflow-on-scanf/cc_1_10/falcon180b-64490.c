//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int age;
    char gender[MAX_LENGTH];
    char address[MAX_LENGTH];
} Person;

void read_csv(FILE *file, Person *people) {
    char line[MAX_LENGTH];
    char *token;
    int i = 0;

    while (fgets(line, MAX_LENGTH, file)!= NULL) {
        token = strtok(line, ",");
        strcpy(people[i].name, token);
        token = strtok(NULL, ",");
        people[i].age = atoi(token);
        token = strtok(NULL, ",");
        strcpy(people[i].gender, token);
        token = strtok(NULL, ",");
        strcpy(people[i].address, token);
        i++;
    }
}

void print_people(Person *people, int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Gender: %s\n", people[i].gender);
        printf("Address: %s\n", people[i].address);
        printf("\n");
    }
}

int main() {
    FILE *file;
    char filename[MAX_LENGTH];
    Person people[MAX_LENGTH];
    int n;

    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    n = 0;
    while (fscanf(file, "%s", people[n].name)!= EOF) {
        n++;
    }

    rewind(file);
    read_csv(file, people);

    printf("Number of records: %d\n", n);
    print_people(people, n);

    fclose(file);

    return 0;
}