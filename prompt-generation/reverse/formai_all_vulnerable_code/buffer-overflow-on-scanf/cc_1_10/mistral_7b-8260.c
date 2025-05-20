//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // Packing structures to byte boundary

typedef struct {
    char name[20];
    int age;
    float weight;
} Person;

void readFile(const char *filename) {
    FILE *file;
    Person person;
    int numPeople = 0;

    file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file.");
        return;
    }

    while (fread(&person, sizeof(Person), 1, file) > 0) {
        if (strcmp(person.name, "END") == 0) {
            break;
        }
        numPeople++;
        printf("Name: %s, Age: %d, Weight: %.2f\n", person.name, person.age, person.weight);
    }

    fclose(file);

    if (feof(file)) {
        printf("Reached end of file.\n");
    } else if (ferror(file)) {
        perror("Error reading file.");
    }

    printf("Number of people read: %d\n", numPeople);
}

void writeFile(const char *filename) {
    FILE *file;
    Person people[3];
    int i;

    file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file.");
        return;
    }

    for (i = 0; i < 3; i++) {
        strcpy(people[i].name, "John Doe");
        people[i].age = i * 10;
        people[i].weight = i + 1.5;
        fwrite(&people[i], sizeof(Person), 1, file);
    }

    strcpy(people[2].name, "END");
    fwrite(&people[2], sizeof(Person), 1, file);

    fclose(file);

    if (feof(file)) {
        printf("File written successfully.\n");
    } else if (ferror(file)) {
        perror("Error writing to file.");
    }
}

int main() {
    char filename[20];

    printf("Enter filename: ");
    scanf("%s", filename);

    strcat(filename, ".dat");

    writeFile(filename);
    readFile(filename);

    return 0;
}