//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char line[MAX_LINE_LENGTH];
    char input_file[MAX_LINE_LENGTH];
    char output_file[MAX_LINE_LENGTH];
    char temp_line[MAX_LINE_LENGTH];
    char *token;
    FILE *input_ptr;
    FILE *output_ptr;

    // Get input file name from user
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    // Open input file
    input_ptr = fopen(input_file, "r");

    if (input_ptr == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Get output file name from user
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // Open output file
    output_ptr = fopen(output_file, "w");

    if (output_ptr == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Read input file line by line
    while (fgets(line, MAX_LINE_LENGTH, input_ptr)!= NULL) {
        // Convert line to uppercase
        for (int i = 0; line[i]!= '\0'; i++) {
            line[i] = toupper(line[i]);
        }

        // Replace "Romeo" with "My Dearest Love"
        token = strtok(line, " ");
        while (token!= NULL) {
            if (strcmp(token, "Romeo") == 0) {
                strcpy(temp_line, "My Dearest Love");
            } else {
                strcat(temp_line, token);
                strcat(temp_line, " ");
            }
            token = strtok(NULL, " ");
        }

        // Replace "Juliet" with "My Beloved"
        token = strtok(temp_line, " ");
        while (token!= NULL) {
            if (strcmp(token, "Juliet") == 0) {
                strcpy(temp_line, "My Beloved");
            } else {
                strcat(temp_line, token);
                strcat(temp_line, " ");
            }
            token = strtok(NULL, " ");
        }

        // Write modified line to output file
        fprintf(output_ptr, "%s\n", temp_line);
    }

    // Close input and output files
    fclose(input_ptr);
    fclose(output_ptr);

    printf("File manipulation completed successfully!\n");

    return 0;
}