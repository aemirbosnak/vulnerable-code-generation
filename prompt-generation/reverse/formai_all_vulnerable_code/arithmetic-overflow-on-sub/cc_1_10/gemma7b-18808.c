//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SITES 10

int main()
{
    int i, site_num, status_code, uptime_minutes;
    char site_name[20];
    time_t t_start, t_end;
    FILE *fp;

    // Open the site status file
    fp = fopen("site_status.txt", "r");

    // Read the number of sites
    fscanf(fp, "Number of sites: %d", &site_num);

    // Allocate memory for site information
    char **sites = (char **)malloc(site_num * sizeof(char *));

    // Read site information
    for (i = 0; i < site_num; i++)
    {
        fscanf(fp, "Site name: %s", sites[i]);
        fscanf(fp, "Site status code: %d", &status_code);
        fscanf(fp, "Uptime minutes: %d", &uptime_minutes);
    }

    // Close the file
    fclose(fp);

    // Print the site status
    printf("-------------------------------------------------------------\n");
    printf("   Site Name | Status Code | Uptime Minutes |\n");
    printf("-------------------------------------------------------------\n");
    for (i = 0; i < site_num; i++)
    {
        printf("%-20s | %d | %d |\n", sites[i], status_code, uptime_minutes);
    }

    printf("-------------------------------------------------------------\n");

    // Calculate the time taken to complete the task
    t_start = time(NULL);
    t_end = time(NULL);
    uptime_minutes = (t_end - t_start) * 60;

    // Print the time taken
    printf("Time taken: %d minutes\n", uptime_minutes);

    return 0;
}