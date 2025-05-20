//Falcon-180B DATASET v1.0 Category: File handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

struct person {
    char name[50];
    int age;
    char gender[10];
};

int main() {
    FILE *file;
    char filename[50];
    int num_people = 0;
    struct person people[100];

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    // Read file
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        struct person *person = &people[num_people];
        char *token = strtok(line, ",");
        strcpy(person->name, token);
        token = strtok(NULL, ",");
        person->age = atoi(token);
        token = strtok(NULL, ",");
        strcpy(person->gender, token);
        num_people++;
    }

    // Close file
    fclose(file);

    // Sort by age
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[i].age > people[j].age) {
                struct person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Print results
    printf("Name\tAge\tGender\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s\t%d\t%s\n", people[i].name, people[i].age, people[i].gender);
    }

    // Free memory
    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
        free(people[i].gender);
    }
    free(people);

    return 0;
}