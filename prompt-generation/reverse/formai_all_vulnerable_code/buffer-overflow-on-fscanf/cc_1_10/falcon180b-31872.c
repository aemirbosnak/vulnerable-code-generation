//Falcon-180B DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_OF_PEOPLE 100

struct person {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
};

void read_people_from_file(struct person *people, FILE *file) {
    int count = 0;
    while (fscanf(file, "%s %d %c\n", people[count].name, &people[count].age, &people[count].gender)!= EOF) {
        count++;
        if (count == MAX_NUMBER_OF_PEOPLE) {
            break;
        }
    }
}

void write_people_to_file(struct person *people, FILE *file) {
    for (int i = 0; i < MAX_NUMBER_OF_PEOPLE; i++) {
        if (people[i].name[0]!= '\0') {
            fprintf(file, "%s %d %c\n", people[i].name, people[i].age, people[i].gender);
        }
    }
}

int main() {
    struct person people[MAX_NUMBER_OF_PEOPLE];
    FILE *file;

    // Open the file for reading
    file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        exit(1);
    }

    // Read the people from the file
    read_people_from_file(people, file);

    // Close the file
    fclose(file);

    // Open the file for writing
    file = fopen("people.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }

    // Write the people to the file
    write_people_to_file(people, file);

    // Close the file
    fclose(file);

    return 0;
}