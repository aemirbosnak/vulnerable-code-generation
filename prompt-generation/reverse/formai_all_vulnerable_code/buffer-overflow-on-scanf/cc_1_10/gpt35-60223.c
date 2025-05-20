//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is an Intrusion Detection System using C language. */
/* It monitors log files to detect any unauthorized access attempts. */
/* Whenever it detects an attack, it sends an alert to the system administrator. */
/* This program records the log files, checks for any suspicious activity, and reports it to the admin.*/

struct log
{
    char data[100];
};

int main()
{
    FILE *filePointer;
    struct log records[100];
    char fileName[100], *token;
    int count = 0;

    printf("Enter the name of the log file: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "r");

    if (filePointer == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    else
    {
        printf("Log File Opened Successfully! \n");
    }

    char line[1024];

    while (fgets(line, 1024, filePointer))
    {
        strcpy(records[count].data, line);
        count++;
    }

    token = strtok(records[0].data, " ");

    if (strcmp(token, "root") == 0)
    {
        printf("\n\nAlert: Root user has logged in! \n\n");
    }

    for (int i = 1; i < count; i++)
    {
        token = strtok(records[i].data, " ");

        if (strcmp(token, "root") == 0)
        {
            printf("\n\nAlert: Root user has logged in! \n\n");
        }

        token = strtok(records[i].data, "[");

        if (strcmp(token, "Failed password for") == 0)
        {
            char *username = strtok(NULL, " ");
            printf("\n\nAlert: Failed password attempt for %s \n\n", username);
        }
    }

    fclose(filePointer);

    return 0;
}