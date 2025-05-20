//Falcon-180B DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    Person people[100];
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

    // Read file and store data in struct array
    while (fscanf(file, "%s %d\n", people[num_people].name, &people[num_people].age)!= EOF) {
        num_people++;
    }

    // Close file
    fclose(file);

    // Sort array by age
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[i].age > people[j].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Print sorted array
    printf("Sorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s %d\n", people[i].name, people[i].age);
    }

    // Write sorted array to new file
    file = fopen("sorted.txt", "w");
    if (file == NULL) {
        printf("Error: could not create file.\n");
        return 1;
    }

    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
    }

    // Close file
    fclose(file);

    printf("Sorted data written to sorted.txt.\n");

    return 0;
}