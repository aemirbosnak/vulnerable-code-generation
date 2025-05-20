//Falcon-180B DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_FILENAME_LENGTH 80

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int age;
    char address[MAX_LINE_LENGTH];
} Person;

int main() {
    FILE *file;
    char filename[MAX_FILENAME_LENGTH];
    Person people[100];
    int num_people = 0;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read in data
    while (fscanf(file, "%s %d %s\n", people[num_people].name, &people[num_people].age, people[num_people].address)!= EOF) {
        num_people++;
    }
    fclose(file);

    // Sort by age
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[i].age > people[j].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Print out data
    printf("Name\tAge\tAddress\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s\t%d\t%s\n", people[i].name, people[i].age, people[i].address);
    }

    return 0;
}