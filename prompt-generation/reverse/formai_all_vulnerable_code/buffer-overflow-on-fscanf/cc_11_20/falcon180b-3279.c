//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

int main() {
    FILE *file;
    Contact contacts[100];
    int num_contacts = 0;

    // Open the mailing list file
    file = fopen("mailing_list.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open mailing list file.\n");
        return 1;
    }

    // Read in the contacts from the file
    while (fscanf(file, "%s %s\n", contacts[num_contacts].name, contacts[num_contacts].email)!= EOF) {
        num_contacts++;
        if (num_contacts >= 100) {
            printf("Error: Mailing list is too large.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    // Display the contacts
    printf("Mailing list:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s (%s)\n", contacts[i].name, contacts[i].email);
    }

    // Sort the contacts alphabetically by name
    for (int i = 0; i < num_contacts - 1; i++) {
        for (int j = i + 1; j < num_contacts; j++) {
            if (strcmp(contacts[i].name, contacts[j].name) > 0) {
                Contact temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }

    // Display the sorted contacts
    printf("\nSorted mailing list:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s (%s)\n", contacts[i].name, contacts[i].email);
    }

    // Save the sorted contacts to a new file
    file = fopen("sorted_mailing_list.txt", "w");

    if (file == NULL) {
        printf("Error: Could not open sorted mailing list file.\n");
        return 1;
    }

    for (int i = 0; i < num_contacts; i++) {
        fprintf(file, "%s %s\n", contacts[i].name, contacts[i].email);
    }

    fclose(file);

    printf("Sorted mailing list saved to sorted_mailing_list.txt.\n");

    return 0;
}