//FormAI DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

typedef struct {
    char name[MAX_SIZE];
    int age;
    float height;
} Person;

void write_to_file(FILE *file, Person person)
{
    fprintf(file, "%s %d %f\n", person.name, person.age, person.height);
}

void read_from_file(FILE *file, Person *person)
{
    fscanf(file, "%s %d %f", person->name, &person->age, &person->height);
}

int main()
{
    FILE *file;
    Person person1, person2;
    
    // Write to file
    file = fopen("people.txt", "w");
    if (file == NULL) {
        printf("Error: can't open file for writing\n");
        exit(1);
    }
    
    strcpy(person1.name, "John");
    person1.age = 30;
    person1.height = 180.5;
    write_to_file(file, person1);
    
    strcpy(person2.name, "Mary");
    person2.age = 25;
    person2.height = 165.8;
    write_to_file(file, person2);
    
    fclose(file);
    
    // Read from file
    file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error: can't open file for reading\n");
        exit(1);
    }
    
    read_from_file(file, &person1);
    read_from_file(file, &person2);
    
    fclose(file);
    
    // Print persons
    printf("Person 1: %s, %d, %.2f\n", person1.name, person1.age, person1.height);
    printf("Person 2: %s, %d, %.2f\n", person2.name, person2.age, person2.height);
    
    return 0;
}