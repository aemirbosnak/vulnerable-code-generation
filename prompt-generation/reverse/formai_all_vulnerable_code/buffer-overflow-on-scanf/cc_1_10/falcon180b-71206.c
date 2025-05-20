//Falcon-180B DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *infile, *outfile;
    char filename[50], input[100], output[100];
    int i, j, n, key;
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    
    infile = fopen(filename, "r");
    
    if (infile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    
    fseek(infile, 0, SEEK_END);
    n = ftell(infile);
    rewind(infile);
    
    fclose(infile);
    
    strcat(filename, ".enc");
    outfile = fopen(filename, "w");
    
    if (outfile == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }
    
    while ((fscanf(infile, "%s", input))!= EOF) {
        for (i = 0; input[i]!= '\0'; i++) {
            if (isalpha(input[i])) {
                if (isupper(input[i])) {
                    output[i] = ((input[i] + key) % 26) + 'A';
                } else {
                    output[i] = ((input[i] + key) % 26) + 'a';
                }
            } else {
                output[i] = input[i];
            }
        }
        output[i] = '\0';
        fprintf(outfile, "%s", output);
    }
    
    fclose(outfile);
    
    printf("Encryption completed successfully.\n");
    
    return 0;
}