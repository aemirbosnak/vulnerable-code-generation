//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

int main() {
    char input[SIZE];
    char output[SIZE];
    int key, i, j;

    // Get input file name
    printf("Enter the name of the input file: ");
    scanf("%s", input);

    // Get encryption key
    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);

    // Open input file
    FILE* fp = fopen(input, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", input);
        return 1;
    }

    // Read input file
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* buffer = malloc(size + 1);
    fread(buffer, size, 1, fp);
    fclose(fp);

    // Encrypt buffer
    for (i = 0; i < size; i++) {
        if (isalpha(buffer[i])) {
            if (isupper(buffer[i])) {
                buffer[i] = (char) (buffer[i] + key - 65);
            } else {
                buffer[i] = (char) (buffer[i] + key - 97);
            }
        }
    }

    // Write encrypted buffer to output file
    strcpy(output, input);
    strcat(output, ".enc");
    fp = fopen(output, "w");
    if (fp == NULL) {
        printf("Error: Could not create file %s\n", output);
        return 1;
    }
    fwrite(buffer, size, 1, fp);
    fclose(fp);

    // Print success message
    printf("File %s encrypted successfully!\n", input);
    return 0;
}