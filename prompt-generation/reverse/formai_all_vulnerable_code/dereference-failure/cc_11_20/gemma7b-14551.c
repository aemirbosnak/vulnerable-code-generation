//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char *date_string = NULL;
    char *date_format = NULL;
    int year, month, day, hour, minute, second;
    int is_valid = 0;

    printf("Welcome to the Time Traveler!\n");
    printf("Please provide a date and time in the format YYYY-MM-DD HH:MM:SS:\n");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the date and time string
    date_string = strtok(buffer, " ");
    date_format = strtok(NULL, " ");

    // Validate the date and time format
    if (strcmp(date_format, "YYYY-MM-DD HH:MM:SS") != 0)
    {
        printf("Invalid date format!\n");
        return 1;
    }

    // Convert the date and time string into integers
    year = atoi(date_string);
    month = atoi(strtok(NULL, "-")) - 1;
    day = atoi(strtok(NULL, "-")) - 1;
    hour = atoi(strtok(NULL, ":")) - 1;
    minute = atoi(strtok(NULL, ":")) - 1;
    second = atoi(strtok(NULL, ":")) - 1;

    // Check if the date and time are valid
    if (year < 1 || year > 2023)
    {
        printf("Invalid year!\n");
        return 1;
    }
    if (month < 0 || month > 11)
    {
        printf("Invalid month!\n");
        return 1;
    }
    if (day < 0 || day > 31)
    {
        printf("Invalid day!\n");
        return 1;
    }
    if (hour < 0 || hour > 23)
    {
        printf("Invalid hour!\n");
        return 1;
    }
    if (minute < 0 || minute > 59)
    {
        printf("Invalid minute!\n");
        return 1;
    }
    if (second < 0 || second > 59)
    {
        printf("Invalid second!\n");
        return 1;
    }

    // Print the date and time in a friendly format
    printf("Congratulations, you have successfully traveled to: %d-%d-%d %d:%d:%d\n", year, month, day, hour, minute, second);

    return 0;
}