//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char line[MAX_LINE_LENGTH];
    char* file_path;
    FILE* file;
    int sum = 0;
    int len = 0;
    int i;

    // Get the file path from the user
    printf("Enter file path: ");
    scanf("%s", file_path);

    // Open the file
    file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        len = strlen(line);
        for (i = 0; i < len; i++) {
            sum += line[i];
        }
    }

    // Calculate the checksum
    sum = (sum % 256) + 256;
    sum = (sum % 256) + 256;
    sum = (sum % 256) + 256;
    sum = (sum % 256) + 256;
    sum = (sum % 256) + 256;
    sum = (sum % 256) + 256;
    sum = (sum % 256) + 256;
    sum = (sum % 256) + 256;

    // Print the checksum
    printf("Checksum: %d\n", sum);

    // Close the file
    fclose(file);

    return 0;
}