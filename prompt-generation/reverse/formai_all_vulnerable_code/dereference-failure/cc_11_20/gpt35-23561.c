//FormAI DATASET v1.0 Category: File Encyptor ; Style: happy
#include <stdio.h>
#include <string.h>

int main()
{
    int key = 7; // set your encryption key here
    char input[1000];
    char output[1000];
    FILE *inFile;
    FILE *outFile;

    printf("Welcome to Happy C File Encryptor!\n");
    printf("Please enter the filename to encrypt: ");
    scanf("%s", input);

    inFile = fopen(input, "r");
    if (inFile == NULL) {
        printf("Error opening file! Please make sure the file exists and try again.\n");
        return 1;
    }

    printf("Please enter the name of the output file: ");
    scanf("%s", output);

    outFile = fopen(output, "w");
    if (outFile == NULL) {
        printf("Error creating output file! Please try again.\n");
        return 1;
    }

    // read each character from input file, encrypt it, and write it to output file
    while (fgets(input, 1000, inFile)) {
        for(int i = 0; i < strlen(input); i++) {
            char c = input[i];
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) { // check if character is a letter
                if(c >= 'a' && c <= 'z') { // check if character is lowercase
                    c = (((c - 'a') + key) % 26) + 'a'; // shift character by key positions and wrap around if necessary
                } else { // character is uppercase
                    c = (((c - 'A') + key) % 26) + 'A'; // shift character by key positions and wrap around if necessary
                }
            }
            fputc((int)c, outFile); // write encrypted character to output file
        }
    }

    fclose(inFile);
    fclose(outFile);
    printf("Success! File encryption is complete.\n");

    return 0;
}