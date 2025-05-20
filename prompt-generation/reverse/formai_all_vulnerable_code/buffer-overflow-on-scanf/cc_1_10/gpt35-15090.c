//FormAI DATASET v1.0 Category: Database querying ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a struct to represent a database record
typedef struct {
    int id;
    char name[20];
    char email[50];
    int age;
} Record;

// Function to query the database recursively
void queryDatabase(Record records[], int size, int start, int end, char searchString[]) {
    // We need not look further if the start index becomes greater than the end index
    if (start > end) {
        return;
    }

    // Calculating the middle index
    int mid = (start + end) / 2;

    // Checking if the search string is present in the name of the middle record
    if (strstr(records[mid].name, searchString) != NULL) {
        // Printing the record details if the search string is present
        printf("ID: %d\nName: %s\nEmail: %s\nAge: %d\n\n",
            records[mid].id, records[mid].name, records[mid].email, records[mid].age);
    }

    // Recursively querying the left half of the database
    queryDatabase(records, size, start, mid-1, searchString);

    // Recursively querying the right half of the database
    queryDatabase(records, size, mid+1, end, searchString);
}

int main() {
    // Creating an array of records to represent the database
    Record records[] = {
        {1, "John Smith", "johnsmith@gmail.com", 25},
        {2, "Emma Brown", "emma.brown@yahoo.com", 37},
        {3, "Taylor Davis", "taylor_davis@gmail.com", 31},
        {4, "Oliver Johnson", "oliverj@gmail.com", 45},
        {5, "Sophia Lee", "sophia_lee@gmail.com", 28},
        {6, "Benjamin Scott", "ben_scott@yahoo.com", 19},
        {7, "Ava Martinez", "ava.martinez@gmail.com", 26},
        {8, "William Jones", "william.jones@yahoo.com", 33}
    };

    // Calculating the size of the records array
    int size = sizeof(records) / sizeof(Record);

    // Getting the search string from the user
    char searchString[20];
    printf("Enter the name to search for: ");
    scanf("%s", searchString);

    // Querying the database recursively
    queryDatabase(records, size, 0, size-1, searchString);

    return 0;
}