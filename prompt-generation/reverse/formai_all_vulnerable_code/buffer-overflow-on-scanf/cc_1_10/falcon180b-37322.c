//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to recover data from a corrupted file
void recoverData(FILE *file, char *output) {
    char ch;
    int count = 0;

    // Read the file until end of file is reached
    while ((ch = fgetc(file))!= EOF) {
        if (ch!= 0) {
            // Write the non-zero character to the output file
            fprintf(output, "%c", ch);
            count++;
        }
    }

    // Print the number of characters recovered
    printf("Total characters recovered: %d\n", count);
}

int main() {
    FILE *input, *output;
    char inputName[100], outputName[100], ch;

    // Prompt the user to enter the names of the input and output files
    printf("Enter the name of the input file: ");
    scanf("%s", inputName);
    printf("Enter the name of the output file: ");
    scanf("%s", outputName);

    // Open the input file in read mode and the output file in write mode
    input = fopen(inputName, "r");
    if (input == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }
    output = fopen(outputName, "w");
    if (output == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }

    // Recover data from the corrupted file
    recoverData(input, output);

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}