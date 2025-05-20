//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    char input_file[100], output_file[100], key[100], ch;
    FILE *fp_in, *fp_out;
    int i, j, k, n, sum;

    // get input file name
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    // get output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // get encryption key
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // open input file
    fp_in = fopen(input_file, "r");
    if (fp_in == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    // open output file
    fp_out = fopen(output_file, "w");
    if (fp_out == NULL) {
        printf("Error opening output file\n");
        fclose(fp_in);
        exit(1);
    }

    // read input file
    n = 0;
    while ((ch = fgetc(fp_in))!= EOF) {
        input_file[n++] = ch;
    }
    input_file[n] = '\0';

    // close input file
    fclose(fp_in);

    // encrypt input file
    for (i = 0; input_file[i]!= '\0'; i++) {
        if (isalpha(input_file[i])) {
            input_file[i] = input_file[i] + (key[i % strlen(key)] - 'a' + 26) % 26;
        } else {
            input_file[i] = input_file[i];
        }
    }

    // write output file
    for (i = 0; input_file[i]!= '\0'; i++) {
        fprintf(fp_out, "%c", input_file[i]);
    }

    // close output file
    fclose(fp_out);

    printf("File encrypted successfully!\n");

    return 0;
}