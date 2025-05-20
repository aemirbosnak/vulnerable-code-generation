//Falcon-180B DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void error_handling(int error_code) {
    switch(error_code) {
        case 1:
            printf("Error: Invalid input.\n");
            break;
        case 2:
            printf("Error: Insufficient memory.\n");
            break;
        case 3:
            printf("Error: File not found.\n");
            break;
        case 4:
            printf("Error: Invalid file format.\n");
            break;
        case 5:
            printf("Error: Operation failed.\n");
            break;
        default:
            printf("Error: Unknown error.\n");
            break;
    }
    exit(1);
}

int main() {
    char filename[MAX_SIZE];
    FILE *file;
    int num_lines = 0;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        error_handling(3);
    }

    // Read file and count lines
    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, file)!= NULL) {
        num_lines++;
    }

    // Close file
    if (fclose(file)!= 0) {
        error_handling(2);
    }

    // Print result
    printf("File '%s' contains %d lines.\n", filename, num_lines);

    return 0;
}