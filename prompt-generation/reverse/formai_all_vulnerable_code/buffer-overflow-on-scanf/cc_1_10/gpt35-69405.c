//FormAI DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 

typedef struct {
    char name[MAX_SIZE];
    int age;
    char gender[MAX_SIZE];
} Person;

void writeToFile(char* fileName, Person* person) {
    FILE* fp;
    fp = fopen(fileName, "a+");
    if(fp) {
        fprintf(fp, "%s,%d,%s\n", person->name, person->age, person->gender);
        printf("Successfully written to file!\n");
        fclose(fp);
    } else {
        printf("Error: Could not open file.\n");
    }
}

void readFromFile(char* fileName) {
    FILE* fp;
    fp = fopen(fileName, "r");
    if(fp) {
        char buffer[MAX_SIZE];
        while(fgets(buffer, MAX_SIZE, fp)) {
            char* name = strtok(buffer, ",");
            int age = atoi(strtok(NULL, ","));
            char* gender = strtok(NULL, ",");
            printf("Name: %s\nAge: %d\nGender: %s\n\n", name, age, gender);
        }
        fclose(fp);
    } else {
        printf("Error: Could not open file.\n");
    }
}

int main() {
    printf("File Handling Example Program\n");

    Person person;
    printf("\nEnter name: ");
    fgets(person.name, MAX_SIZE, stdin);
    person.name[strcspn(person.name, "\n")] = '\0'; // remove newline character from input buffer

    printf("Enter age: ");
    scanf("%d", &person.age);

    printf("Enter gender: ");
    getchar(); // consume newline character left in input buffer
    fgets(person.gender, MAX_SIZE, stdin);
    person.gender[strcspn(person.gender, "\n")] = '\0'; // remove newline character from input buffer

    writeToFile("person.txt", &person);
    readFromFile("person.txt");

    return 0;
}