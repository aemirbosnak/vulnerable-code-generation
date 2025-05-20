//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void generate_checksum(char* data, int size, char* checksum) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    sprintf(checksum, "%02X", sum % 256);
}

int main() {
    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];
    char data[MAX_SIZE];
    char checksum[3];

    printf("Enter input file name: ");
    scanf("%s", input_file);

    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fseek(input, 0, SEEK_END);
    int size = ftell(input);
    rewind(input);

    fread(data, size, 1, input);
    fclose(input);

    generate_checksum(data, size, checksum);

    strcat(output_file, input_file);
    strcat(output_file, ".chk");

    FILE* output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    fprintf(output, "%s\n", data);
    fprintf(output, "Checksum: %s\n", checksum);

    fclose(output);

    printf("Checksum calculated and saved to %s.\n", output_file);

    return 0;
}