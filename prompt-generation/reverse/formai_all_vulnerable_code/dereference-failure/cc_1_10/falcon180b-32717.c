//Falcon-180B DATASET v1.0 Category: Email Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000
#define DELIMITER ","

typedef struct {
    char first_name[MAX_LINE_LENGTH];
    char last_name[MAX_LINE_LENGTH];
    char email[MAX_LINE_LENGTH];
} Contact;

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int num_lines = 0;
    Contact contacts[MAX_NUM_LINES];

    // Open the file for reading
    file = fopen("contacts.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read in each line of the file
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        num_lines++;

        // Parse the line into first name, last name, and email
        char *token = strtok(line, DELIMITER);
        strcpy(contacts[num_lines-1].first_name, token);

        token = strtok(NULL, DELIMITER);
        strcpy(contacts[num_lines-1].last_name, token);

        token = strtok(NULL, DELIMITER);
        strcpy(contacts[num_lines-1].email, token);
    }

    // Close the file
    fclose(file);

    // Print the list of contacts
    for (int i = 0; i < num_lines; i++) {
        printf("Name: %s %s\n", contacts[i].first_name, contacts[i].last_name);
        printf("Email: %s\n\n", contacts[i].email);
    }

    return 0;
}