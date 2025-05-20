//FormAI DATASET v1.0 Category: Log analysis ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[100];
    char line[300];

    printf("Enter the name of the log file to analyze: ");
    scanf("%s", filename);

    // Opening the log file
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error opening file! \n");
        exit(0);
    }

    int num_of_requests = 0;
    int num_of_successful_reqs = 0;
    int num_of_failed_reqs = 0;
    int total_bytes_sent = 0;

    // Reading each line of the log file
    while (fgets(line, sizeof(line), fp))
    {
        // Analyzing each log request
        char *request = strtok(line, " ");

        if (strcmp(request, "GET") == 0 || strcmp(request, "POST") == 0 || strcmp(request, "PUT") == 0 || strcmp(request, "DELETE") == 0)
        {
            num_of_requests++;

            char *status_code = strtok(NULL, " ");

            if (strcmp(status_code, "200") == 0)
            {
                num_of_successful_reqs++;

                char *bytes_sent = strtok(NULL, " ");
                total_bytes_sent += atoi(bytes_sent);
            }
            else
            {
                num_of_failed_reqs++;
            }
        }
    }

    // Printing the analysis report
    printf("\n\n");
    printf("Log Analysis Report\n");
    printf("Total number of requests: %d \n", num_of_requests);
    printf("Number of successful requests: %d \n", num_of_successful_reqs);
    printf("Number of failed requests: %d \n", num_of_failed_reqs);
    printf("Total number of bytes sent: %d \n", total_bytes_sent);

    fclose(fp);

    return 0;
}