//FormAI DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main() {
    // Declare file variables
    FILE *infile, *outfile;
    char inFilename[50], outFilename[50], key[20];
    int numKeys, i, j, k, inFileLength, keyLength;

    // Get input file name
    printf("Enter input file name (including path): ");
    scanf("%s", inFilename);

    // Open input file
    infile = fopen(inFilename, "r");
    if (infile == NULL) {
        printf("Unable to open input file.\n");
        return 0;
    }

    // Get output file name
    printf("Enter output file name (including path): ");
    scanf("%s", outFilename);

    // Open output file
    outfile = fopen(outFilename, "w");
    if (outfile == NULL) {
        printf("Unable to open output file.\n");
        fclose(infile);
        return 0;
    }

    // Get number of keys to use
    printf("Enter number of keys to use (maximum 5): ");
    scanf("%d", &numKeys);

    // Get encryption keys
    for (i = 0; i < numKeys; i++) {
        printf("Enter encryption key %d: ", (i+1));
        scanf("%s", &key[i*4]);
    }
    keyLength = strlen(key);

    // Get input file length
    fseek(infile, 0, SEEK_END);
    inFileLength = ftell(infile);
    fseek(infile, 0, SEEK_SET);

    // Encrypt input file and write to output file
    i = 0;
    j = 0;
    k = 0;
    while (k < inFileLength) {
        int data = fgetc(infile);
        if (data == EOF) {
            break;
        }
        data ^= key[(i%keyLength)*4+j];
        fputc(data, outfile);
        i++;
        if ((i % keyLength) == 0) {
            j++;
            if (j == 4) {
                j = 0;
            }
        }
        k++;
    }

    // Close input and output files
    fclose(infile);
    fclose(outfile);

    printf("File %s has been encrypted with %d keys and written to %s.\n", inFilename, numKeys, outFilename);

    return 0;
}