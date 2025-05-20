//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10000
#define KEY_SIZE 16

int main() {
    char input_file[MAX_SIZE], output_file[MAX_SIZE], key[KEY_SIZE];
    FILE *input, *output;
    int i, j, n;

    printf("Enter the path of the input file: ");
    scanf("%s", input_file);

    printf("Enter the path of the output file: ");
    scanf("%s", output_file);

    printf("Enter the encryption key (maximum 16 characters): ");
    scanf("%s", key);

    input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: Unable to open output file.\n");
        exit(1);
    }

    for (i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }

    n = 0;
    while ((fgetc(input)!= EOF)) {
        if (isalpha(fgetc(input))) {
            if (isupper(fgetc(input))) {
                fputc(fgetc(input) + (n % 26) - 2, output);
            } else {
                fputc(fgetc(input) + (n % 26), output);
            }
        } else {
            fputc(fgetc(input), output);
        }
        n++;
    }

    fclose(input);
    fclose(output);

    printf("File encrypted successfully!\n");

    return 0;
}