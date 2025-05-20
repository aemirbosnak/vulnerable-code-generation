//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[50], output_filename[50];
    char ch;
    int i, j, key, count = 0;

    // get input file name
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    // open input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // get output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    // open output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // get encryption key
    printf("Enter the encryption key (0-255): ");
    scanf("%d", &key);

    // read input file
    while ((ch = fgetc(input_file))!= EOF) {
        // encrypt character
        if (isalpha(ch)) {
            count++;
        }
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = ch + key - 65;
            } else {
                ch = ch + key - 97;
            }
        }
        fprintf(output_file, "%c", ch);
    }

    // close input and output files
    fclose(input_file);
    fclose(output_file);

    // print number of characters encrypted
    printf("Number of characters encrypted: %d\n", count);

    return 0;
}