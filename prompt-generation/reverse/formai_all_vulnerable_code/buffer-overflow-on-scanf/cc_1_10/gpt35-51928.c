//FormAI DATASET v1.0 Category: System event logger ; Style: complete
#include <stdio.h>  // for standard input/output functions
#include <stdlib.h> // for exit() function
#include <time.h>   // for time related functions
#include <string.h> // for string related functions
 
int main()
{
    FILE *fp;             // file pointer to log file
    char fileName[] = "eventlog.txt"; // name of the log file
    char eventName[50];   // to store event name
    char eventTime[25];   // to store event time and date
    time_t rawTime;       // to get raw time
    struct tm *timeInfo;  // to convert raw time to readable format
    int choice;           // to store user choice

    fp = fopen(fileName, "a"); // open log file in append mode

    if (fp == NULL) // if error opening the log file
    {
        printf("Error: Could not open file %s", fileName);
        exit(1);
    }

    printf("Welcome to Event Logger Program\n");
    printf("Choose an option:\n");
    printf("1. Log an event\n");
    printf("2. View log\n");
    printf("3. Exit\n");
    scanf("%d", &choice); // get user choice

    switch (choice)
    {
    case 1: // log an event
        printf("Enter the event name: ");
        getchar(); // consume newline character
        fgets(eventName, 50, stdin); // get event name
        eventName[strcspn(eventName, "\n")] = 0; // remove newline character
        time(&rawTime); // get current time
        timeInfo = localtime(&rawTime); // convert raw time to local time
        strftime(eventTime, 25, "%Y-%m-%d %H:%M:%S", timeInfo); // format time 
        fprintf(fp, "%s - %s\n", eventTime, eventName); // write event name and time to log file
        printf("Event logged successfully!\n");
        break;
    case 2: // view log
        printf("Event log:\n");
        printf("--------------------\n");
        rewind(fp); // move file pointer to beginning of the file
        char line[100]; // to store each line in the log file
        while (fgets(line, 100, fp) != NULL) // read each line in the file
            printf("%s", line); // print the line
        printf("--------------------\n");
        break;
    case 3: // exit program
        printf("Thank you for using Event Logger Program!\n");
        break;
    default:
        printf("Invalid choice!\n");
    }

    fclose(fp); // close log file
    return 0;
}