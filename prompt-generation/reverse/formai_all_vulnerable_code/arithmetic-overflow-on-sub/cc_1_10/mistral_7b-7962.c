//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void convertDate(char *dateStr) {
    int day, month, year, hour, minute, second;
    char *token;

    // Splitting the date string using space as delimiter
    token = strtok(dateStr, " ");

    // Extracting date part
    sscanf(token, "%d/%d/%d", &day, &month, &year);

    // Setting the date using mktime() function
    struct tm *date = malloc(sizeof(struct tm));
    memset(date, 0, sizeof(struct tm));

    date->tm_sec = 0;
    date->tm_min = 0;
    date->tm_hour = 0;
    date->tm_mday = day;
    date->tm_mon = month - 1; // months are zero indexed in C
    date->tm_year = year - 1900;

    // Converting the date to Unix timestamp
    time_t unixTime = mktime(date);

    // Extracting time part from the input string
    token = strtok(NULL, ":");
    hour = atoi(token);
    token = strtok(NULL, ":");
    minute = atoi(token);
    token = strtok(NULL, ":");
    second = atoi(token);

    // Adding the time to the Unix timestamp
    unixTime += hour * 3600 + minute * 60 + second;

    printf("Unix Timestamp: %ld\n", (long)unixTime);

    free(date);
}

int main() {
    char input[100];

    printf("Enter the date and time in the format 'dd/mm/yyyy hh:mm:ss': ");
    scanf("%s", input);

    convertDate(input);

    return 0;
}