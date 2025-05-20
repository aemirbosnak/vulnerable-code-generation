//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100

// Function to compare two files and synchronize their contents
void file_synchronizer(char *file1, char *file2) {
    FILE *fp1, *fp2;
    char ch1, ch2;
    int count = 0;

    // Open the files in read mode
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    // Check if files are opened successfully
    if (fp1 == NULL || fp2 == NULL) {
        printf("Error: Could not open files.\n");
        exit(1);
    }

    // Initialize variables for synchronization
    while ((ch1 = fgetc(fp1))!= EOF || (ch2 = fgetc(fp2))!= EOF) {
        // Compare the contents of the files character by character
        if (ch1!= ch2) {
            // If characters are different, print the line number and character position
            printf("Line %d, character %d: ", count + 1, count % MAX_FILE_NAME_LEN + 1);
            printf("%c in file1, %c in file2\n", ch1, ch2);
        }
        count++;
    }

    // Close the files
    fclose(fp1);
    fclose(fp2);
}

int main() {
    char file1[MAX_FILE_NAME_LEN], file2[MAX_FILE_NAME_LEN];

    // Get the file names from the user
    printf("Enter the name of the first file: ");
    scanf("%s", file1);
    printf("Enter the name of the second file: ");
    scanf("%s", file2);

    // Call the file synchronizer function
    file_synchronizer(file1, file2);

    return 0;
}