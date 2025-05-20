//FormAI DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct to hold password details
typedef struct {
    char *website;
    char *username;
    char *password;
} Password;

//function to check if file exists
int fileExists(const char *filename) {
    FILE *file;
    if ((file = fopen(filename, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

int main() {
    printf("Welcome to Brave Password Manager\n");

    char filename[50];

    //prompt user for file name
    printf("Please enter the filename to store your passwords (include .txt extension): ");
    fgets(filename, sizeof(filename), stdin);

    //remove newline character from file name
    filename[strcspn(filename, "\n")] = '\0';

    //check if file exists
    if (fileExists(filename)) {
        printf("\nFile already exists. Do you want to overwrite it? (y/n): ");

        char answer = getchar();

        //if user doesn't want to overwrite file, exit program
        if (answer == 'n' || answer == 'N') {
            printf("\nExiting program...\n");
            return 0;
        }
    }

    printf("\n");

    FILE *file = fopen(filename, "w");

    int numPasswords;

    //prompt user for number of passwords to store
    printf("How many passwords would you like to store? ");
    scanf("%d", &numPasswords);

    //create array of passwords
    Password passwords[numPasswords];

    //iterate over array of passwords and prompt user for details
    for (int i = 0; i < numPasswords; i++) {
        printf("\nPassword %d:\n", i + 1);

        //allocate memory for website string
        passwords[i].website = (char*)malloc(50*sizeof(char));
        printf("Website: ");
        scanf(" %[^\n]", passwords[i].website);

        //allocate memory for username string
        passwords[i].username = (char*)malloc(20*sizeof(char));
        printf("Username: ");
        scanf(" %[^\n]", passwords[i].username);

        //allocate memory for password string
        passwords[i].password = (char*)malloc(20*sizeof(char));
        printf("Password: ");
        scanf(" %[^\n]", passwords[i].password);

        //write password details to file
        fprintf(file, "Website: %s\n", passwords[i].website);
        fprintf(file, "Username: %s\n", passwords[i].username);
        fprintf(file, "Password: %s\n", passwords[i].password);

        printf("\n");
    }

    fclose(file);

    //print out password details to console
    printf("\nYour password details have been saved to %s\n", filename);
    printf("\nHere are your password details:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("\nPassword %d:\n", i + 1);
        printf("Website: %s\n", passwords[i].website);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
    }

    //free memory used by passwords
    for (int i = 0; i < numPasswords; i++) {
        free(passwords[i].website);
        free(passwords[i].username);
        free(passwords[i].password);
    }

    return 0;
}