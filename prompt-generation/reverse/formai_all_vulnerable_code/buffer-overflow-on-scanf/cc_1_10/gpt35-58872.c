//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CSV reader example program in C */

int main() {

    printf("Welcome to the CSV reader!\n");

    char filename[100];
    printf("Enter the name of the file you want to read: ");
    scanf("%s", filename);

    /* Open the file */
    FILE *fp;
    fp = fopen(filename, "r");

    if (!fp) {
        printf("Unable to open the file %s. Make sure it exists and try again.\n", filename);
        return 1;
    }

    /* Read the file */
    char line[1000];
    int lines_read = 0;
    while (fgets(line, 1000, fp)) {

        /* Remove the newline character */
        char *pos;
        if ((pos=strchr(line, '\n')) != NULL) {
            *pos = '\0';
        }

        /* Split the line into an array of strings */
        char *field;
        char *fields[100];
        int field_count = 0;
        char *delimiter = ",";

        field = strtok(line, delimiter);
        while (field != NULL) {
            fields[field_count++] = field;
            field = strtok(NULL, delimiter);
        }

        /* Print the values */
        printf("Line %d: ", ++lines_read);
        for (int i = 0; i < field_count; i++) {
            printf("%s\t", fields[i]);
        }
        printf("\n");
    }

    /* Close the file */
    fclose(fp);

    printf("Done reading CSV file!\n");

    return 0;
}