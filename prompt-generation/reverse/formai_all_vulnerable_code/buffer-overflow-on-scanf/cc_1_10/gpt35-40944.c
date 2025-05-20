//FormAI DATASET v1.0 Category: Data recovery tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

int main() {
    FILE *fp;
    Person person;
    int numRecords, i, idNum;
    char temp[50];

    // Open the file
    fp = fopen("data.dat", "rb");

    // Check file exists
    if (fp == NULL) {
        printf("Error: File does not exist.\n");
        exit(1);
    }

    // Find the number of records in the file
    fseek(fp, 0, SEEK_END);
    numRecords = ftell(fp) / sizeof(Person);
    rewind(fp);

    // Prompt user for ID number
    printf("Enter the ID number to retrieve data: ");
    scanf("%d", &idNum);

    // Search for the matching ID number
    for (i = 0; i < numRecords; i++) {
        fread(&person, sizeof(Person), 1, fp);
        if (person.id == idNum) {
            printf("ID: %d\nName: %s\nAge: %d\n", 
                person.id, person.name, person.age);
            break;
        }
    }

    // If ID number not found
    if (i == numRecords) {
        printf("Error: ID number not found.\n");
    }

    // Close the file
    fclose(fp);

    return 0;
}