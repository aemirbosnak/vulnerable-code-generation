//FormAI DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main() {
    // create file pointer
    FILE *fp;
    char filename[100], c;

    // get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // open file with write mode
    fp = fopen(filename, "w");

    // check if file exists
    if (fp == NULL) {
        printf("Could not open file %s", filename);
        exit(1);
    }

    // write data to file
    fprintf(fp, "This is an example program for file handling in C\n");
    fprintf(fp, "We can use fprintf() to write data to file\n");
    fprintf(fp, "We can also use fputs() to write data to file\n");

    fputs("fputs() function is used for writing data to file\n", fp);

    // close file
    fclose(fp);

    // open file with read mode
    fp = fopen(filename, "r");

    // check if file exists
    if (fp == NULL) {
        printf("Could not open file %s", filename);
        exit(1);
    }

    // read data from file
    printf("Data from %s:\n", filename);

    c = fgetc(fp);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fp);
    }

    // close file
    fclose(fp);

    return 0;
}