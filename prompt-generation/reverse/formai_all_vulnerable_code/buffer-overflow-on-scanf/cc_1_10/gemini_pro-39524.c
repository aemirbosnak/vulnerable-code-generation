//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
    char name[20];
    char family[20];
    int age;
    char address[50];
    char phone[20];
} person_t;

// Define the database
person_t database[] = {
    {"Romeo", "Montague", 16, "Verona, Italy", "+39 045 800 9000"},
    {"Juliet", "Capulet", 14, "Verona, Italy", "+39 045 800 9001"},
    {"Tybalt", "Capulet", 20, "Verona, Italy", "+39 045 800 9002"},
    {"Mercutio", "Montague", 22, "Verona, Italy", "+39 045 800 9003"},
    {"Nurse", "Capulet", 50, "Verona, Italy", "+39 045 800 9004"},
    {"Friar Laurence", "Franciscan", 60, "Verona, Italy", "+39 045 800 9005"},
    {"Escalus", "Prince of Verona", 40, "Verona, Italy", "+39 045 800 9006"}
};

// Define the number of records in the database
#define NUM_RECORDS (sizeof(database) / sizeof(person_t))

// Main function
int main() {
    // Print the database
    printf("Romeo and Juliet Database\n");
    printf("------------------------\n");
    for (int i = 0; i < NUM_RECORDS; i++) {
        printf("%s %s, %d, %s, %s\n",
               database[i].name,
               database[i].family,
               database[i].age,
               database[i].address,
               database[i].phone);
    }

    // Prompt the user for a name to search for
    char name[20];
    printf("Enter a name to search for: ");
    scanf("%s", name);

    // Search for the name in the database
    int found = 0;
    for (int i = 0; i < NUM_RECORDS; i++) {
        if (strcmp(database[i].name, name) == 0) {
            found = 1;

            // Print the record
            printf("Record found:\n");
            printf("%s %s, %d, %s, %s\n",
                   database[i].name,
                   database[i].family,
                   database[i].age,
                   database[i].address,
                   database[i].phone);
            break;
        }
    }

    // If the name was not found, print an error message
    if (!found) {
        printf("No record found for %s\n", name);
    }

    return 0;
}