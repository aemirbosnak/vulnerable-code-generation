//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a given string is a palindrome
int isPalindrome(char *str) {
    int i, j;
    char temp;

    // Convert the string to lowercase
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = tolower(str[i]);
    }

    // Check if the string is a palindrome
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0;
        }
    }

    return 1;
}

// Function to scan a file for viruses
void scanFile(FILE *file, char *virus) {
    char line[1024];
    int found = 0;

    // Read the file line by line
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Convert the line to lowercase
        for (int i = 0; line[i]!= '\0'; i++) {
            line[i] = tolower(line[i]);
        }

        // Check if the line contains the virus
        if (strstr(line, virus)!= NULL) {
            found = 1;
            break;
        }
    }

    // Print the result
    if (found) {
        printf("Virus found in file!\n");
    } else {
        printf("File is clean.\n");
    }
}

int main() {
    // Declare variables
    char fileName[1024];
    char virusName[1024];

    // Get the file name from the user
    printf("Enter the name of the file you want to scan: ");
    scanf("%s", fileName);

    // Get the virus name from the user
    printf("Enter the name of the virus you want to scan for: ");
    scanf("%s", virusName);

    // Open the file for reading
    FILE *file = fopen(fileName, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Scan the file for viruses
    scanFile(file, virusName);

    // Close the file
    fclose(file);

    return 0;
}