//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[])
{
    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];
    FILE *fp_in, *fp_out;
    char buffer[MAX_SIZE];
    int i, j, checksum;

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input file for reading
    fp_in = fopen(input_file, "rb");
    if (fp_in == NULL)
    {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open output file for writing
    fp_out = fopen(output_file, "wb");
    if (fp_out == NULL)
    {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Initialize checksum to 0
    checksum = 0;

    // Read input file in chunks
    while (fread(buffer, sizeof(char), MAX_SIZE, fp_in) > 0)
    {
        // Update checksum for each byte in chunk
        for (i = 0; i < strlen(buffer); i++)
        {
            checksum += buffer[i];
        }

        // Write chunk to output file
        fwrite(buffer, sizeof(char), strlen(buffer), fp_out);
    }

    // Close input and output files
    fclose(fp_in);
    fclose(fp_out);

    // Print checksum
    printf("Checksum: %d\n", checksum);

    return 0;
}