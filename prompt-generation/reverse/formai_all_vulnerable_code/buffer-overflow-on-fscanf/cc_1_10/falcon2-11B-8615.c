//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the header line from the CSV file and store it in the buffer
void read_header(char *buffer, FILE *fp) {
    char c;

    // Read each character of the header line until a newline is found
    while ((c = fgetc(fp))!= EOF && c!= '\n') {
        // Append the character to the buffer
        buffer[strlen(buffer)] = c;
    }

    // Terminate the buffer with a null character
    buffer[strlen(buffer)] = '\0';

    // Print the header line
    printf("Header line: %s\n", buffer);
}

// Function to read each line of data from the CSV file and store it in the buffer
void read_line(char *buffer, FILE *fp) {
    char c;

    // Read each character of the line until a newline or a comma is found
    while ((c = fgetc(fp))!= EOF && (c!= ',' || c!= '\n')) {
        // Append the character to the buffer
        buffer[strlen(buffer)] = c;
    }

    // Terminate the buffer with a null character
    buffer[strlen(buffer)] = '\0';

    // Print the line of data
    printf("Line of data: %s\n", buffer);
}

int main() {
    char buffer[100]; // Buffer to store the header and each line of data
    FILE *fp; // File pointer to read from the CSV file

    // Open the CSV file
    if ((fp = fopen("example.csv", "r")) == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    // Read the header line
    read_header(buffer, fp);

    // Read each line of data
    while (fscanf(fp, "%s", buffer) == 1) {
        read_line(buffer, fp);
    }

    // Close the file
    fclose(fp);

    return 0;
}