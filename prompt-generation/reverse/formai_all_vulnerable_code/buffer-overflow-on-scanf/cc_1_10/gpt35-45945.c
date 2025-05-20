//FormAI DATASET v1.0 Category: Database querying ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold data of a person
typedef struct {
    int id;
    char name[20];
    int age;
    char address[50];
} Person;

// Function to print the details of a person
void printPersonDetails(Person person) {
    printf("\nID: %d\nName: %s\nAge: %d\nAddress: %s", person.id, person.name, person.age, person.address);
}
 
int main() {

    // Create a database of people
    Person people[5] = {
        { 1, "John Doe", 32, "123 Main Street, Anytown, USA" },
        { 2, "Jane Smith", 25, "456 High Street, Anytown, USA" },
        { 3, "Bob Jones", 40, "789 Low Street, Anytown, USA" },
        { 4, "Samantha Lee", 28, "101 North Street, Anytown, USA" },
        { 5, "Tom Wilson", 35, "202 South Street, Anytown, USA" }
    };

    // Display all the people in the database
    for(int i = 0; i < 5; i++) {
        printf("\n\nPerson %d:", i+1);
        printPersonDetails(people[i]);
    }

    printf("\n\n");

    // Query the database for a person with a specific name
    char queryName[20];
    printf("Enter name to search for: ");
    scanf("%s", queryName);
    
    int found = 0; // Flag to indicate whether a person has been found or not
    for(int i = 0; i < 5; i++) {
        if(strcmp(people[i].name, queryName) == 0) {
            printf("\nPerson found:\n");
            printPersonDetails(people[i]);
            found = 1; // Set flag to indicate person has been found
            break; // Exit the loop
        }
    }

    if(!found) {
        printf("\nNo person found with that name.\n");
    }

    return 0; 
}