//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];
    FILE *fp_in, *fp_out;
    char c;
    int sum, i, j;

    printf("Enter the input file name: ");
    scanf("%s", input_file);

    printf("Enter the output file name: ");
    scanf("%s", output_file);

    fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) {
        printf("Error: could not open output file.\n");
        fclose(fp_in);
        exit(1);
    }

    sum = 0;
    while ((c = fgetc(fp_in))!= EOF) {
        sum += (int)c;
    }

    rewind(fp_in);
    rewind(fp_out);

    fprintf(fp_out, "Checksum: %d\n", sum);

    for (i = 0; i < strlen(input_file); i++) {
        if (isalpha(input_file[i])) {
            input_file[i] = tolower(input_file[i]);
        }
    }

    for (i = 0; i < strlen(output_file); i++) {
        if (isalpha(output_file[i])) {
            output_file[i] = tolower(output_file[i]);
        }
    }

    if (strcmp(input_file, output_file) == 0) {
        printf("Error: input and output file names are the same.\n");
        fclose(fp_in);
        fclose(fp_out);
        remove(output_file);
        exit(1);
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}