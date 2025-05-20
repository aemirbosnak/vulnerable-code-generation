//FormAI DATASET v1.0 Category: Database querying ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_NAME_LENGTH 128
#define MAX_PHONE_LENGTH 16

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

int main() {
    // Open the database file
    FILE *fp;
    fp = fopen("contacts.db", "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open database file.\n");
        return EXIT_FAILURE;
    }

    // Read the number of contacts in the database
    int numContacts;
    fread(&numContacts, sizeof(int), 1, fp);
    printf("Number of contacts in database: %d\n", numContacts);

    // Read all the contacts into an array
    Contact *contacts = malloc(sizeof(Contact) * numContacts);
    for (int i = 0; i < numContacts; i++) {
        fread(&contacts[i], sizeof(Contact), 1, fp);
    }

    // Close the database file
    fclose(fp);

    // Parse the user's query
    char query[MAX_QUERY_LENGTH];
    printf("Enter a query: ");
    fgets(query, MAX_QUERY_LENGTH, stdin);

    // Remove trailing newline character from query string
    query[strcspn(query, "\n")] = '\0';

    // Split the query into keywords
    char *keywords[10];
    int numKeywords = 0;
    char *token = strtok(query, " ");
    while (token != NULL && numKeywords < 10) {
        keywords[numKeywords++] = token;
        token = strtok(NULL, " ");
    }

    // Filter contacts that match the keywords
    int numMatches = 0;
    Contact *matches = malloc(sizeof(Contact) * numMatches);
    for (int i = 0; i < numContacts; i++) {
        int match = 0;
        for (int j = 0; j < numKeywords; j++) {
            if (strstr(contacts[i].name, keywords[j]) != NULL ||
                strstr(contacts[i].phone, keywords[j]) != NULL) {
                match = 1;
            }
            else {
                match = 0;
                break;
            }
        }
        if (match) {
            matches = realloc(matches, sizeof(Contact) * (++numMatches));
            matches[numMatches - 1] = contacts[i];
        }
    }

    // Print the matching contacts
    if (numMatches == 0) {
        printf("No matches found.\n");
    }
    else {
        printf("Matches:\n");
        for (int i = 0; i < numMatches; i++) {
            printf("%s, %s\n", matches[i].name, matches[i].phone);
        }
    }

    // Free dynamically allocated memory
    free(contacts);
    free(matches);

    return EXIT_SUCCESS;
}