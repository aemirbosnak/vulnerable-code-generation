//Falcon-180B DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void print_person(Person *p) {
    printf("Name: %s | Age: %d\n", p->name, p->age);
}

int main() {
    FILE *file;
    char filename[MAX_SIZE];
    char line[MAX_SIZE];
    Person people[MAX_SIZE];
    int num_people = 0;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read file line by line
    while (fgets(line, MAX_SIZE, file)!= NULL) {
        // Parse line into name and age
        char *name = strtok(line, " ");
        int age = atoi(strtok(NULL, " "));

        // Check if there is enough space for another person
        if (num_people >= MAX_SIZE) {
            printf("Error: Too many people.\n");
            fclose(file);
            return 1;
        }

        // Add person to array
        people[num_people].name = strdup(name);
        people[num_people].age = age;
        num_people++;
    }

    // Close file
    fclose(file);

    // Print people
    printf("People:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    return 0;
}