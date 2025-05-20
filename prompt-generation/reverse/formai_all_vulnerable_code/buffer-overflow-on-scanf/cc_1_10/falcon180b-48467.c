//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_SIZE 100000
#define VIRUS_SIGNATURE "I am a virus"

// Function to check if a file contains a virus
int check_virus(FILE *file) {
    char buffer[FILE_SIZE];
    int count = 0;
    while (fgets(buffer, FILE_SIZE, file)!= NULL) {
        if (strstr(buffer, VIRUS_SIGNATURE)!= NULL) {
            count++;
        }
    }
    if (count > 0) {
        printf("Virus found in file\n");
        return 1;
    } else {
        printf("File is clean\n");
        return 0;
    }
}

int main() {
    FILE *file;
    char filename[50];

    // Prompt user to enter filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");

    // Check if file exists
    if (file == NULL) {
        printf("File not found\n");
        return 1;
    }

    // Check if file contains virus
    check_virus(file);

    // Close file
    fclose(file);

    return 0;
}