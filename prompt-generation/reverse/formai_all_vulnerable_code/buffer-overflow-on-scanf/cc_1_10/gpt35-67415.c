//FormAI DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_error(int error_code) {
    switch(error_code) {
        case 1:
            fprintf(stderr, "Error: Invalid input\n");
            break;
        case 2:
            fprintf(stderr, "Error: File not found\n");
            break;
        // Add more error codes and corresponding messages as needed
        default:
            fprintf(stderr, "Error: Unknown error\n");
            break;
    }
}

int main() {
    FILE *fp;
    char filename[50], sentence[100];
    int num;

    // Accept filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file in read mode
    fp = fopen(filename, "r");

    // Check if file was opened successfully
    if(fp == NULL) {
        handle_error(2); // File not found error
        exit(1); // Exit with error code
    }

    // Read an integer from user
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &num);

    // Check if input is valid
    if(num < 1 || num > 10) {
        handle_error(1); // Invalid input error
        exit(1); // Exit with error code
    }

    // Read a sentence from file and print it num times
    while(fgets(sentence, 100, fp) != NULL) {
        for(int i=1; i<=num; i++) {
            printf("%d. %s", i, sentence);
        }
    }

    // Close file
    fclose(fp);

    return 0;
}