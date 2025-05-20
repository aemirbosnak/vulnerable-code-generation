//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char filename[100], output_filename[100];
    int key, i, j, ch, count = 0;
    char text[1000];

    // Generate random key
    srand(time(0));
    key = rand() % 26 + 'a';

    // Get input file name
    printf("Enter input file name: ");
    scanf("%s", filename);

    // Open input file
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Create output file name
    strcpy(output_filename, filename);
    strcat(output_filename, ".enc");

    // Open output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file and encrypt each character
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                j = ch - 'A' - key;
                if (j < 0) {
                    j += 26;
                }
                ch = j + 'A';
            } else {
                j = ch - 'a' - key;
                if (j < 0) {
                    j += 26;
                }
                ch = j + 'a';
            }
        }
        fprintf(output_file, "%c", ch);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");
    return 0;
}