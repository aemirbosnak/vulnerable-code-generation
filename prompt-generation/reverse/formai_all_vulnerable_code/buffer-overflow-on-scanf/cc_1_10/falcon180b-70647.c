//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char input_line[MAX_LINE_LENGTH];
    char *filename;
    FILE *file;
    char checksum[33]; // 32-character hexadecimal string + null terminator
    int i, j, k;
    int line_count = 0;
    int total_checksum = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(input_line, MAX_LINE_LENGTH, file)!= NULL) {
        line_count++;
        for (i = 0; input_line[i]!= '\0'; i++) {
            if (input_line[i] >= 'a' && input_line[i] <= 'z') {
                input_line[i] = input_line[i] - 'a' + 'A'; // convert to uppercase
            }
        }
        total_checksum += strlen(input_line);
    }

    rewind(file);

    while (fgets(input_line, MAX_LINE_LENGTH, file)!= NULL) {
        for (i = 0; input_line[i]!= '\0'; i++) {
            if (input_line[i] >= 'A' && input_line[i] <= 'Z') {
                total_checksum += (int)input_line[i] - 65; // convert to numeric value and add to checksum
            }
        }
    }

    fclose(file);

    sprintf(checksum, "%08X", total_checksum); // convert to hexadecimal string with leading zeros

    printf("Checksum for file %s: %s\n", filename, checksum);

    return 0;
}