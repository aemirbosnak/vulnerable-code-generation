//FormAI DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 16 // Change this to adjust password length
#define MAX_FILENAME_LENGTH 50

void generatePassword(char *password, int length)
{
    int i;
    srand(time(NULL)); // Initialize random seed
    for(i = 0; i < length; i++)
    {
        password[i] = rand() % 94 + 33; // Generate a character between ASCII values 33 and 126
    }
    password[length] = '\0'; // Add null terminator to end of string
}

void storePassword(char *filename, char *password)
{
    FILE *file;
    file = fopen(filename, "a"); // Open file in append mode
    if(file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%s\n", password); // Write password to file
    fclose(file); // Close file
}

void listPasswords(char *filename)
{
    FILE *file;
    char password[PASSWORD_LENGTH + 1];
    file = fopen(filename, "r"); // Open file in read mode
    if(file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    printf("Passwords:\n");
    while(fgets(password, PASSWORD_LENGTH + 1, file)) // Read passwords line by line
    {
        printf("%s", password); // Print password
    }
    fclose(file); // Close file
}

int main()
{
    char filename[MAX_FILENAME_LENGTH], password[PASSWORD_LENGTH + 1], choice;
    while(1)
    {
        printf("\nMenu:\n1) Generate password\n2) Store password\n3) List passwords\n4) Exit\n");
        scanf(" %c", &choice);
        switch(choice)
        {
            case '1': // Generate password
                generatePassword(password, PASSWORD_LENGTH);
                printf("Generated password: %s\n", password);
                break;
            case '2': // Store password
                printf("Enter filename to store password: ");
                scanf("%s", filename);
                storePassword(filename, password);
                printf("Password stored in %s.\n", filename);
                break;
            case '3': // List passwords
                printf("Enter filename containing passwords: ");
                scanf("%s", filename);
                listPasswords(filename);
                break;
            case '4': // Exit
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}