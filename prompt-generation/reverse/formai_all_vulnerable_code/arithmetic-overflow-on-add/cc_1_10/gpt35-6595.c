//FormAI DATASET v1.0 Category: File handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "secret_file.txt" // name of the file to be created or accessed
#define MAX_LENGTH 50 // maximum length of input strings

void writeToFile(char *string) {
    FILE *fileptr;

    // open the file for writing in binary append mode
    fileptr = fopen(FILENAME, "ab");

    if (fileptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // write the string to the file
    fwrite(string, strlen(string), 1, fileptr);

    // close the file
    fclose(fileptr);
}

void readFromFile() {
    FILE *fileptr;
    char *buffer = NULL;
    int fileSize;

    // open the file for reading in binary read mode
    fileptr = fopen(FILENAME, "rb");

    if (fileptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // get the file size
    fseek(fileptr, 0, SEEK_END);
    fileSize = ftell(fileptr);
    rewind(fileptr);

    // allocate memory for the buffer
    buffer = malloc((fileSize + 1) * sizeof(char));

    // read the entire file into the buffer
    fread(buffer, fileSize, 1, fileptr);
    buffer[fileSize] = '\0';

    // print the contents of the buffer
    printf("%s\n", buffer);

    // free the memory allocated to the buffer
    free(buffer);

    // close the file
    fclose(fileptr);
}

int main() {
    char input[MAX_LENGTH];

    printf("Welcome to the paranoid file handling program. Type 'quit' at any time to exit.\n\n");

    while (1) {
        printf("Enter your secret message: ");
        fgets(input, MAX_LENGTH, stdin);

        // remove the newline at the end of the input string
        strtok(input, "\n");

        if (strcmp(input, "quit") == 0) {
            printf("\nExiting program...\n");
            break;
        }

        // encrypt the input string
        for (int i = 0; i < strlen(input); i++) {
            input[i] = input[i] + 1;
        }

        // write the encrypted string to the file
        writeToFile(input);

        printf("Your message has been securely written to the file.\n");
    }

    printf("\nReading the encrypted messages from the file:\n\n");

    // read the encrypted messages from the file and decrypt them
    readFromFile();

    return 0;
}