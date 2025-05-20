//FormAI DATASET v1.0 Category: Database querying ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

int main() {
    // Define a person struct to hold the query result
    Person person;
    
    // Prompt user for the person's ID to retrieve
    int search_id;
    printf("Please enter the person's ID: ");
    scanf("%d", &search_id);
    
    // Open the database file for reading
    FILE *fd = fopen("people.db", "r");
    if (fd == NULL) {
        printf("Error opening database file.\n");
        exit(1);
    }
    
    // Loop through the file to find the person with the specified ID
    int found = 0;
    while (fread(&person, sizeof(Person), 1, fd)) {
        if (person.id == search_id) {
            found = 1;
            break;
        }
    }
    
    // Close the database file
    fclose(fd);
    
    // If the person was found, print their information
    if (found) {
        printf("Person found!\n");
        printf("ID: %d\n", person.id);
        printf("Name: %s\n", person.name);
        printf("Age: %d\n", person.age);
    } else {
        printf("Person not found.\n");
    }
    
    return 0;
}