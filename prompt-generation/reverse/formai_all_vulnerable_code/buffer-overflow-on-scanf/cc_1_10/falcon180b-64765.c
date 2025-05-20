//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int main(int argc, char *argv[]) {
    char input_file[MAX_LENGTH];
    char output_file[MAX_LENGTH];
    FILE *fp_in, *fp_out;
    char ch;
    int sum = 0;

    // Get input file name from command line argument
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Open input file
    fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Get output file name from input file name
    strcpy(output_file, input_file);
    strcat(output_file, ".chk");

    // Open output file
    fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) {
        printf("Error opening output file.\n");
        fclose(fp_in);
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

    printf("Checksum calculated and saved to %s.\n", output_file);

    return 0;
}