//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SIZE 1000000

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    char buffer[MAX_SIZE];
    int i, j, k, key, len;
    
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);
    
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);
    
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    
    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        exit(1);
    }
    
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    
    while (fgets(buffer, MAX_SIZE, input_file)!= NULL) {
        len = strlen(buffer);
        for (i = 0; i < len; i++) {
            if (isalpha(buffer[i])) {
                buffer[i] = (buffer[i] + key) % 26;
                if (isupper(buffer[i])) {
                    buffer[i] = tolower(buffer[i]);
                }
            }
        }
        fputs(buffer, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
    
    printf("Encryption completed successfully.\n");
    return 0;
}