//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random password
void generatePassword(char *password, int length) {
    int i;
    const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789";
    const int alphanum_length = sizeof(alphanum) - 1;
    for (i = 0; i < length; ++i) {
        password[i] = alphanum[rand() % alphanum_length];
    }
    password[length] = '\0';
}

int main() {
    int choice, length;
    char password[100], file_name[100];
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Get the password length from the user
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    
    // Generate a random password
    generatePassword(password, length);
    
    // Ask the user if they want to save the password to a file
    printf("Do you want to save the password to a file? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        // Get the file name from the user
        printf("Enter the file name: ");
        scanf("%s", file_name);
        
        // Open the file for writing
        FILE *fp = fopen(file_name, "w");
        
        if (fp == NULL) {
            printf("Error: Could not open file %s for writing\n", file_name);
        } else {
            fprintf(fp, "Password: %s\n", password);
            fclose(fp);
            printf("Password saved to file %s\n", file_name);
        }
    }
    
    printf("Your password is: %s\n", password);
    
    return 0;
}