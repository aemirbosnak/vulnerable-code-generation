//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    // ask user for file name
    printf("Enter file name: ");
    char filename[20];
    scanf("%s", filename);

    // create file pointer
    FILE *fileptr;
    fileptr = fopen(filename, "w");

    // check if file was created successfully
    if (fileptr == NULL) {
        printf("Error creating file\n");
        exit(1);
    }

    // ask user how many integers they want to write to file
    printf("How many integers do you want to write? ");
    int count;
    scanf("%d", &count);

    // write integers to file
    printf("Enter %d integers:\n", count);
    int num;
    for (int i = 0; i < count; i++) {
        scanf("%d", &num);
        fprintf(fileptr, "%d ", num);
    }
    fprintf(fileptr, "\n"); // add newline character at end of file

    // close file
    fclose(fileptr);

    // re-open file in read mode and read integers back
    fileptr = fopen(filename, "r");
    if (fileptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    printf("Integers in file %s: ", filename);
    while (fscanf(fileptr, "%d", &num) != EOF) {
        printf("%d ", num);
    }
    printf("\n");

    // close file
    fclose(fileptr);

    return 0;
}