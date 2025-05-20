//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_file[100];
    char output_file[100];
    FILE *fp_in, *fp_out;
    int ch;
    int sum = 0;
    int i;

    // Prompt user for input file name
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Open input file
    fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("Error opening file %s\n", input_file);
        exit(1);
    }

    // Prompt user for output file name
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open output file
    fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) {
        printf("Error opening file %s\n", output_file);
        exit(1);
    }

    // Calculate checksum
    while ((ch = fgetc(fp_in))!= EOF) {
        sum += ch;
    }

    // Write checksum to output file
    fprintf(fp_out, "%d\n", sum);

    // Close files
    fclose(fp_in);
    fclose(fp_out);

    printf("Checksum calculated successfully.\n");

    return 0;
}