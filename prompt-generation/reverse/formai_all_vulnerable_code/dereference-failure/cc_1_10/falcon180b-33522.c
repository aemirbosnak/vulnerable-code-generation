//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for tolower()

int main() {
    char input_file[100], output_file[100], ch;
    FILE *fpin, *fpout;

    // Get input file name from user
    printf("Enter the name of input file: ");
    scanf("%s", input_file);

    // Open input file
    fpin = fopen(input_file, "r");
    if (fpin == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    // Get output file name from user
    printf("Enter the name of output file: ");
    scanf("%s", output_file);

    // Open output file
    fpout = fopen(output_file, "w");
    if (fpout == NULL) {
        printf("Error: Unable to open output file.\n");
        exit(1);
    }

    // Loop through input file
    while ((ch = fgetc(fpin))!= EOF) {
        if (isalpha(ch)) {
            // Convert character to lowercase
            ch = tolower(ch);
            // Check if character is a letter
            if (ch >= 'a' && ch <= 'z') {
                // Convert character to ASCII art
                switch (ch) {
                    case 'a':
                        fprintf(fpout, "___\n|   |\n|   |\n|___|");
                        break;
                    case 'b':
                        fprintf(fpout, "_____\n|   | |\n|   | |\n|   | |\n|___| |");
                        break;
                    case 'c':
                        fprintf(fpout, "_____\n|   | |\n|   | |\n|   | |\n|   | |");
                        break;
                    // Add more cases for other letters
                }
            }
        } else {
            // Write non-letter characters as is
            fprintf(fpout, "%c", ch);
        }
    }

    // Close files
    fclose(fpin);
    fclose(fpout);

    printf("ASCII art generated successfully and saved to %s.\n", output_file);

    return 0;
}