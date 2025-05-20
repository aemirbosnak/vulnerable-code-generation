//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* Function to convert a given date string into time_t format */
time_t convert_date(char *date_str) {
    struct tm tm;
    time_t result = 0;

    /* Initialize the tm struct */
    memset(&tm, 0, sizeof(tm));

    /* Parse the date string */
    if (strptime(date_str, "%d/%m/%Y", &tm) == NULL) {
        printf("Invalid date format!\n");
        exit(1);
    }

    /* Convert the tm struct to time_t format */
    result = mktime(&tm);

    return result;
}

/* Function to convert a given time_t value into a date string */
char *convert_time(time_t time_val) {
    struct tm tm;
    char buf[80];

    /* Convert the time_t value to tm struct */
    localtime_r(&time_val, &tm);

    /* Format the tm struct as a date string */
    strftime(buf, sizeof(buf), "%d/%m/%Y", &tm);

    return strdup(buf);
}

int main() {
    char input[80];
    char *date_str;
    time_t time_val;
    char *result;

    /* Prompt the user for a date string */
    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%s", input);

    /* Convert the input string to lowercase */
    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    /* Convert the input string to a date_t value */
    date_str = strdup(input);
    time_val = convert_date(date_str);

    /* Convert the date_t value to a date string */
    result = convert_time(time_val);

    /* Display the result */
    printf("The date %s is %s\n", input, result);

    return 0;
}