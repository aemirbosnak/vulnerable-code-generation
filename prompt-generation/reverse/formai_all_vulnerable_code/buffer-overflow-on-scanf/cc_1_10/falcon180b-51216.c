//Falcon-180B DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_LINES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

int main() {
    FILE *file;
    char filename[MAX_NAME_LENGTH];
    Person people[MAX_LINES];
    int num_people = 0;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read in data from file
    int i = 0;
    while (fscanf(file, "%s %d\n", people[i].name, &people[i].age) == 2) {
        i++;
        if (i == MAX_LINES) {
            printf("Error: too many lines in file.\n");
            fclose(file);
            return 1;
        }
    }
    num_people = i;

    // Sort people by age
    for (i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[j].age < people[i].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Print out sorted data
    printf("Name\tAge\n");
    for (i = 0; i < num_people; i++) {
        printf("%s\t%d\n", people[i].name, people[i].age);
    }

    // Close file
    fclose(file);

    return 0;
}