//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char line[1000];
    char field[100];
    char delimiter = ',';
    char quote = '"';
    int field_count = 0;
    int line_count = 0;

    // Open the file
    if ((fp = fopen("data.csv", "r")) == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Read lines from the file
    while (fgets(line, sizeof(line), fp)!= NULL)
    {
        // Count the number of fields in each line
        line_count++;

        // Read fields from the line
        for (int i = 0; i < strlen(line); i++)
        {
            // If the field contains a comma or a quote, then it's a new field
            if (line[i] == delimiter || line[i] == quote)
            {
                // Check if the previous field was a quote
                if (line[i - 1] == quote)
                {
                    // Add the quote to the field
                    field[field_count++] = quote;
                }

                // Add the field to the list
                strcpy(field + field_count, line + i);
                field_count++;

                // Reset the field count
                field_count = 0;
            }
        }
    }

    // Close the file
    fclose(fp);

    // Print the number of lines and fields
    printf("Lines: %d\n", line_count);
    printf("Fields: %d\n", field_count);

    // Print the first line
    printf("First line:\n");
    for (int i = 0; i < field_count; i++)
    {
        printf("%s ", field + i);
    }
    printf("\n");

    return 0;
}