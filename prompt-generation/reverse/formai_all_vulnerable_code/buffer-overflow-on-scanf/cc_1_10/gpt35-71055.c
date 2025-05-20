//FormAI DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define KEY 0x8 // encryption key

int main()
{
    FILE *in_file, *out_file;
    char in_filename[100], out_filename[100], c;

    printf("Enter the input file name: ");
    scanf("%s", in_filename);

    // open input file
    in_file = fopen(in_filename, "r");

    if (in_file == NULL)
    {
        printf("ERROR: Could not open input file!");
        return 1;
    }

    // create output file
    sprintf(out_filename, "%s.encrypted", in_filename);
    out_file = fopen(out_filename, "w");

    if (out_file == NULL)
    {
        printf("ERROR: Could not create output file!");
        return 1;
    }

    // read from input file and write to output file
    while ((c = fgetc(in_file)) != EOF)
    {
        // encrypt character
        c ^= KEY;

        // write encrypted character to output file
        fputc(c, out_file);
    }

    printf("Encryption successful! Encrypted file: %s\n", out_filename);

    // close file pointers
    fclose(in_file);
    fclose(out_file);

    return 0;
}