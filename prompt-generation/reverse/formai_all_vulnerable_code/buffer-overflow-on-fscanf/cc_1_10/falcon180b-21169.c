//Falcon-180B DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char name[MAX_LINE_LENGTH];
    int age;
} Person;

int main() {
    FILE *file;
    Person people[10];
    int num_people = 0;

    // Open file for reading
    file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read in data from file and store in struct array
    while (fscanf(file, "%s %d\n", people[num_people].name, &people[num_people].age)!= EOF) {
        num_people++;
    }

    // Sort array by age
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[j].age < people[i].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Print sorted data to console
    printf("Sorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s %d\n", people[i].name, people[i].age);
    }

    // Close file
    fclose(file);

    return 0;
}