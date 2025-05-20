//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: paranoid
#include<stdio.h>
#include<string.h>

// Define a constant for maximum file name length
#define MAX_FILE_NAME_LENGTH 100

// Define a function to check for viruses in a given file
void scanFile(char fileName[MAX_FILE_NAME_LENGTH]) {

    // Define an array of virus signatures to compare with
    char *virusSignatures[] = {"malware", "trojan", "virus", "worm"};

    // Define a variable to keep track of the number of viruses found
    int virusesFound = 0;

    // Open the file for reading
    FILE *file = fopen(fileName, "r");

    // If the file can't be opened, throw an error and exit
    if(file == NULL) {
        printf("Error: unable to open file.\n");
        exit(1);
    }

    // Declare a character array to store each line of the file
    char line[256];

    // Read each line of the file
    while(fgets(line, 256, file)) {

        // Check if any of the virus signatures are found in the line
        for(int i = 0; i < 4; i++) {
            if(strstr(line, virusSignatures[i]) != NULL) {
                virusesFound++;
            }
        }

        // If we've found more than one virus, print the filename and exit
        if(virusesFound > 1) {
            printf("Warning: multiple viruses found in file %s.\n", fileName);
            fclose(file);
            return;
        }
    }

    // Print a message indicating that the file is clean
    printf("File %s is clean.\n", fileName);

    // Close the file
    fclose(file);
}

// Define the main function
int main() {

    // Declare an array to hold the file name
    char fileName[MAX_FILE_NAME_LENGTH];

    // Prompt the user for the file name
    printf("Enter file name: ");
    scanf("%s", fileName);

    // Scan the file for viruses
    scanFile(fileName);

    // Exit successfully
    return 0;
}