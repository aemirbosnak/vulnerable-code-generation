//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_LINE_LEN 1000

int main(int argc, char *argv[])
{
    // Check if a filename is provided
    if (argc != 2)
    {
        printf("Usage: csvreader <filename>\n");
        return 1;
    }

    // Open the file
    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    // Read the first line to get the column headers
    char line[MAX_LINE_LEN];
    if (!fgets(line, MAX_LINE_LEN, fp))
    {
        printf("Error: Cannot read file %s\n", argv[1]);
        return 1;
    }
    line[strlen(line) - 1] = '\0'; // Remove the newline character at the end

    // Split the line into column headers
    char *col[MAX_COLS];
    int num_cols = 0;
    char *tok = strtok(line, ",");
    while (tok != NULL && num_cols < MAX_COLS)
    {
        col[num_cols++] = tok;
        tok = strtok(NULL, ",");
    }

    // Read the remaining lines and parse the values
    while (fgets(line, MAX_LINE_LEN, fp))
    {
        line[strlen(line) - 1] = '\0'; // Remove the newline character at the end

        // Split the line into values
        char *val[MAX_COLS];
        int num_vals = 0;
        tok = strtok(line, ",");
        while (tok != NULL && num_vals < num_cols)
        {
            val[num_vals++] = tok;
            tok = strtok(NULL, ",");
        }

        // Output the parsed values
        for (int i = 0; i < num_cols; i++)
        {
            printf("%s=%s ", col[i], val[i]);
        }
        printf("\n");
    }

    // Close the file
    fclose(fp);

    return 0;
}