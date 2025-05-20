//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to embed digital watermark
void embedWatermark(char *inputFile, char *outputFile, char *watermark) {

    // Open input and output files
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");

    if(inFile == NULL || outFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read the entire file contents into buffer
    char buffer[MAX_SIZE];
    size_t bytesRead = fread(buffer, sizeof(char), MAX_SIZE, inFile);

    // Close input file
    fclose(inFile);

    // Embed digital watermark into buffer
    strcat(buffer, watermark);

    // Write the buffer to output file
    size_t bytesWritten = fwrite(buffer, sizeof(char), bytesRead + strlen(watermark), outFile);

    if(bytesWritten != bytesRead + strlen(watermark)) {
        printf("Error writing to file!\n");
        exit(1);
    }

    // Close output file
    fclose(outFile);

    printf("Digital watermarking complete!\n");
}

// Function to extract digital watermark
void extractWatermark(char *inputFile, char *outputFile) {

    // Open input and output files
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");

    if(inFile == NULL || outFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read the entire file contents into buffer
    char buffer[MAX_SIZE];
    size_t bytesRead = fread(buffer, sizeof(char), MAX_SIZE, inFile);

    // Close input file
    fclose(inFile);

    // Find the end of the original file
    char *endOfFile = strstr(buffer, "---END OF FILE---");

    if(endOfFile == NULL) {
        printf("Error extracting watermark!\n");
        exit(1);
    }

    // Extract digital watermark from buffer
    size_t bytesWritten = fwrite(endOfFile + strlen("---END OF FILE---"), sizeof(char), bytesRead - (endOfFile - buffer) - strlen("---END OF FILE---"), outFile);

    if(bytesWritten != bytesRead - (endOfFile - buffer) - strlen("---END OF FILE---")) {
        printf("Error writing to file!\n");
        exit(1);
    }

    // Close output file
    fclose(outFile);

    printf("Digital watermark extracted!\n");
}

int main() {

    // Variables to store input file, output file, and digital watermark
    char input[MAX_SIZE], output[MAX_SIZE], watermark[MAX_SIZE];

    // Intro statement
    printf("Welcome to the story of Romeo and Juliet!\n");
    printf("We will be using digital watermarking to embed secret messages into the story!\n");
    printf("Please enter the name of the input file (e.g. romeo_juliet.txt): ");
    scanf("%s", input);
  
    // Embed the first part of the digital watermark into the story
    strcpy(watermark, "My love for Juliet is like a rose in the Spring,");
    embedWatermark(input, "romeo_juliet_watermarked.txt", watermark);

    // Print the first part of the digital watermark
    printf("Digital watermarking complete! Here is the first part of the secret message:\n");
    printf("My love for Juliet is like a rose in the Spring,\n");

    // Prompt the user for the second part of the digital watermark
    printf("Please enter the second part of the secret message: ");
    scanf(" %[^\n]", watermark);

    // Embed the second part of the digital watermark into the story
    embedWatermark("romeo_juliet_watermarked.txt", "romeo_juliet_watermarked_twice.txt", watermark);

    // Print the second part of the digital watermark
    printf("Digital watermarking complete! Here is the second part of the secret message:\n");
    printf("%s\n", watermark);

    // Display final instructions
    printf("The story has been watermarked with your secret message!\n");
    printf("To extract the watermark, please enter the name of the output file (e.g. romeo_juliet_secret.txt): ");
    scanf("%s", output);
    printf("Press any key to extract the watermark!\n");
    getchar();

    // Extract the digital watermark from the story
    extractWatermark("romeo_juliet_watermarked_twice.txt", output);

    // Outro statement
    printf("Thank you for using this digital watermarking program!\n");
    printf("May your love be as strong as that of Romeo and Juliet!\n");

    return 0;
}