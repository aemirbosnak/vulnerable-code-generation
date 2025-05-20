//Gemma-7B DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main()
{
    char **data = NULL;
    int i, j, k, l, num_records, num_attributes;
    FILE *fp;

    // Open the data file
    fp = fopen("data.txt", "r");

    // Allocate memory for the data
    data = (char **)malloc(MAX * sizeof(char *));

    // Read the number of records and attributes
    fscanf(fp, "%d %d", &num_records, &num_attributes);

    // Read the data
    for (i = 0; i < num_records; i++)
    {
        data[i] = (char *)malloc(num_attributes * sizeof(char));
        fscanf(fp, "%s", data[i]);
    }

    // Close the data file
    fclose(fp);

    // Print the data
    for (i = 0; i < num_records; i++)
    {
        for (j = 0; j < num_attributes; j++)
        {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < num_records; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}