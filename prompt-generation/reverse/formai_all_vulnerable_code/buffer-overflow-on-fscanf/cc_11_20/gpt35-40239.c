//FormAI DATASET v1.0 Category: File handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare file pointer and variables
    FILE *fp;
    char filename[50], name[20], email[30], c;
    int option, flag = 0;

    // Prompt user for filename
    printf("Enter file name: ");
    scanf("%s", filename);

    // Open file to read and write
    fp = fopen(filename, "r+");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Display options to user and prompt for choice
    printf("\nSelect an option:\n");
    printf("1. Add a contact\n");
    printf("2. Search for a contact\n");
    printf("3. Exit program\n");
    printf("Option: ");
    scanf("%d", &option);

    // Implement selected option
    switch(option) {
        case 1: // Add a contact
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            fprintf(fp, "%s %s\n", name, email);
            printf("Contact added successfully!\n");
            break;

        case 2: // Search for a contact
            printf("Enter name to search for: ");
            scanf("%s", name);
            while((c = fgetc(fp)) != EOF) {
                if(c == '\n') {
                    flag = 0;
                }
                if(flag == 1) {
                    continue;
                }
                if(c == name[0]) {
                    fseek(fp, -1, SEEK_CUR);
                    fscanf(fp, "%s %s", name, email);
                    if(strcmp(name, name) == 0) {
                        printf("Contact found:\n");
                        printf("Name : %s\nEmail: %s\n", name, email);
                        flag = 1;
                    }
                }
            }
            if(flag == 0) {
                printf("No matching contact found!\n");
            }
            break;

        case 3: // Exit program
            printf("Exiting program!\n");
            exit(0);
            break;

        default: // Invalid option
            printf("Invalid option selected!\n");
            break;
    }

    // Close file
    fclose(fp);

    return 0;
}