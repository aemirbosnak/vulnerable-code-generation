//FormAI DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[100], line[100];
    FILE *fp;
    int num_lines = 0, i;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    /* Count the number of lines in the file */
    while (fgets(line, 100, fp) != NULL) {
        num_lines++;
    }

    /* Allocate memory for storing the lines */
    char **lines = (char **) malloc(num_lines * sizeof(char *));
    for (i = 0; i < num_lines; i++) {
        lines[i] = (char *) malloc(100 * sizeof(char));
    }

    /* Rewind the file pointer */
    fseek(fp, 0, SEEK_SET);

    /* Copy each line into the allocated memory */
    i = 0;
    while (fgets(line, 100, fp) != NULL) {
        strcpy(lines[i], line);
        i++;
    }

    /* Close the file */
    fclose(fp);

    /* Print out the contents of the file */
    for (i = 0; i < num_lines; i++) {
        printf("%s", lines[i]);
    }

    /* Free the dynamically allocated memory */
    for (i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}