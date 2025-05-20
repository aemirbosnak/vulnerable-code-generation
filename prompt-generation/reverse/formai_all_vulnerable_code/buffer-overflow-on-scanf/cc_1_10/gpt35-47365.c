//FormAI DATASET v1.0 Category: Database querying ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void print_contact(Contact c) {
    printf("ID: %d\n", c.id);
    printf("Name: %s\n", c.name);
    printf("Email: %s\n", c.email);
    printf("Phone: %s\n", c.phone);
    printf("\n");
}

void print_contacts(Contact contacts[], int n) {
    for (int i = 0; i < n; i++) {
        print_contact(contacts[i]);
    }
}

int main() {
    // Simulates a database with 5 contacts
    Contact contacts[5] = {
        {1, "John", "john@gmail.com", "123-456-7890"},
        {2, "Mary", "mary@gmail.com", "987-654-3210"},
        {3, "David", "david@yahoo.com", "555-555-5555"},
        {4, "Susan", "susan@hotmail.com", "111-222-3333"},
        {5, "Peter", "peter@aol.com", "777-888-9999"}
    };
    int n = 5; // Number of contacts

    // Query the database
    char search_term[MAX_NAME_LENGTH];
    printf("Enter a name to search for: ");
    scanf("%s", search_term);

    Contact results[n]; // Stores the matching contacts
    int count = 0; // Number of matching contacts

    for (int i = 0; i < n; i++) {
        if (strstr(contacts[i].name, search_term) != NULL) {
            results[count++] = contacts[i];
        }
    }

    // Print the results
    if (count > 0) {
        printf("Found %d matching contacts:\n", count);
        print_contacts(results, count);
    } else {
        printf("No matching contacts found.\n");
    }

    return 0;
}