//MISTRAL-7B DATASET v1.0 Category: Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE 1024
#define SIZE 5

typedef struct {
    char name[50];
    int age;
    float height;
} Person;

void readFile(char *filename, Person people[SIZE]) {
    int i = 0;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d %f", people[i].name, &people[i].age, &people[i].height) != EOF) {
        i++;
    }

    fclose(file);
}

void displayPeople(Person people[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%s (%d years old, %.2f meters tall)\n", people[i].name, people[i].age, people[i].height);
    }
}

int main() {
    char filename[MAX_LINE];
    Person people[SIZE];

    printf("Enter file name: ");
    scanf("%s", filename);

    readFile(filename, people);

    printf("\nList of people:\n");
    displayPeople(people);

    return 0;
}