//Falcon-180B DATASET v1.0 Category: File handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum string size

typedef struct {
    char name[MAX_SIZE];
    int age;
    char gender;
} Person;

int main() {
    FILE *file;
    Person people[MAX_SIZE];
    int num_people = 0;

    // open file for reading
    file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // read header line
    char header[MAX_SIZE];
    fscanf(file, "%s", header);

    // read each person's data
    while (fscanf(file, "%s %d %c", people[num_people].name, &people[num_people].age, &people[num_people].gender)!= EOF) {
        num_people++;
    }

    // close file
    fclose(file);

    // sort people by age
    for (int i = 0; i < num_people; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[i].age > people[j].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // print sorted list of people
    printf("Sorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s %d %c\n", people[i].name, people[i].age, people[i].gender);
    }

    // open file for writing
    file = fopen("sorted_people.txt", "w");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // write header line
    fprintf(file, "Sorted by age:\n");

    // write each person's data
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s %d %c\n", people[i].name, people[i].age, people[i].gender);
    }

    // close file
    fclose(file);

    return 0;
}