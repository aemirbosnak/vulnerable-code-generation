//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int generate_checksum(char *data, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

int main() {
    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];
    char data[MAX_SIZE];
    int size;

    printf("Enter the input file name: ");
    scanf("%s", input_file);
    printf("Enter the output file name: ");
    scanf("%s", output_file);

    FILE *fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fseek(fp_in, 0, SEEK_END);
    size = ftell(fp_in);
    rewind(fp_in);

    fread(data, size, 1, fp_in);
    fclose(fp_in);

    int checksum = generate_checksum(data, size);

    FILE *fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    fprintf(fp_out, "%.8X\n", checksum);
    fwrite(data, size, 1, fp_out);
    fclose(fp_out);

    printf("Checksum calculated and written to output file.\n");

    return 0;
}