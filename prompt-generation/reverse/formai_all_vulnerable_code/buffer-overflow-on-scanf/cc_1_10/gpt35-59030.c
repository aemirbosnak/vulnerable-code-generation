//FormAI DATASET v1.0 Category: Log analysis ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char log_file_name[50], buffer[100];
    int line_count = 0, error_count = 0, warning_count = 0;
    FILE *log_file;

    printf("Enter the name of the log file: ");
    scanf("%s", log_file_name);

    log_file = fopen(log_file_name, "r");

    if (log_file == NULL)
    {
        printf("\nUnable to open log file. Program terminated.\n");
        exit(1);
    }

    // Reading each line of the log file
    while (fgets(buffer, 100, log_file) != NULL)
    {
        line_count++;

        if (strstr(buffer, "ERROR") != NULL)
        {
            error_count++;
            printf("Line %d: %s", line_count, buffer);
        }

        if (strstr(buffer, "WARNING") != NULL)
        {
            warning_count++;
            printf("Line %d: %s", line_count, buffer);
        }
    }

    printf("\n");
    printf("Total lines in the log file: %d\n", line_count);
    printf("Total errors in the log file: %d\n", error_count);
    printf("Total warnings in the log file: %d\n", warning_count);

    fclose(log_file);

    printf("\nProgram executed successfully! :) \n\n");

    return 0;
}