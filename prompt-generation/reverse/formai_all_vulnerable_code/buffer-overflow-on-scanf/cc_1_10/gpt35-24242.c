//FormAI DATASET v1.0 Category: Log analysis ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototypes
void analyze_log(char fname[]);
void print_results(int total_lines, int error_lines, int warning_lines, int info_lines);

int main()
{
    char filename[100];
    printf("Enter the name of the log file: ");
    scanf("%s", filename);
    analyze_log(filename);
    return 0;
}

void analyze_log(char fname[])
{
    FILE *fp;
    char line[1000];
    int total_lines = 0, error_lines = 0, warning_lines = 0, info_lines = 0;

    //open the log file
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("Error opening file.");
        exit(1);
    }

    //read each line of the log file
    while (fgets(line, sizeof(line), fp))
    {
        total_lines++;

        //check for error, warning, or info messages
        if (strstr(line, "ERROR"))
            error_lines++;
        else if (strstr(line, "WARNING"))
            warning_lines++;
        else if (strstr(line, "INFO"))
            info_lines++;
    }

    //print the results
    print_results(total_lines, error_lines, warning_lines, info_lines);

    //close the log file
    fclose(fp);
}

void print_results(int total_lines, int error_lines, int warning_lines, int info_lines)
{
    printf("Total lines in log file: %d\n", total_lines);
    printf("Error lines in log file: %d\n", error_lines);
    printf("Warning lines in log file: %d\n", warning_lines);
    printf("Info lines in log file: %d\n", info_lines);

    //calculate percentage of error, warning, and info messages
    float error_percent = ((float)error_lines / total_lines) * 100;
    float warning_percent = ((float)warning_lines / total_lines) * 100;
    float info_percent = ((float)info_lines / total_lines) * 100;

    printf("Percentage of error messages: %.2f%%\n", error_percent);
    printf("Percentage of warning messages: %.2f%%\n", warning_percent);
    printf("Percentage of info messages: %.2f%%\n", info_percent);
}