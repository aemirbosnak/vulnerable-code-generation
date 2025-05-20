//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
    float height;
} Person;

int main() {
    FILE *file;
    Person people[5];
    char fileName[30];
    int i;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    file = fopen(fileName, "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter 5 people's information:\n");

    for (i = 0; i < 5; i++) {
        printf("Name %d: ", i + 1);
        scanf("%s", people[i].name);
        printf("Age: ");
        scanf("%d", &people[i].age);
        printf("Height: ");
        scanf("%f", &people[i].height);

        fprintf(file, "%s,%d,%.2f\n", people[i].name, people[i].age, people[i].height);
    }

    fclose(file);
    printf("People's information saved to %s.\n", fileName);

    printf("\nReading data from the file:\n");

    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s,%d,%f", people[i].name, &people[i].age, &people[i].height) != EOF) {
        printf("Name: %s, Age: %d, Height: %.2f\n", people[i].name, people[i].age, people[i].height);
        i++;
    }

    fclose(file);

    return 0;
}