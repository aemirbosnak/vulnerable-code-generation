//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Function to convert natural language date to specific format
void convertDate(char* date)
{
    // Separate the date components (day, month, year)
    char* day = strtok(date, "th");
    char* month = strtok(NULL, "th");
    char* year = strtok(NULL, "th");

    // Convert the month to a specific format
    char* monthFormat = strdup("0");
    if (strcmp(month, "January") == 0) {
        monthFormat = strdup("01");
    } else if (strcmp(month, "February") == 0) {
        monthFormat = strdup("02");
    } else if (strcmp(month, "March") == 0) {
        monthFormat = strdup("03");
    } else if (strcmp(month, "April") == 0) {
        monthFormat = strdup("04");
    } else if (strcmp(month, "May") == 0) {
        monthFormat = strdup("05");
    } else if (strcmp(month, "June") == 0) {
        monthFormat = strdup("06");
    } else if (strcmp(month, "July") == 0) {
        monthFormat = strdup("07");
    } else if (strcmp(month, "August") == 0) {
        monthFormat = strdup("08");
    } else if (strcmp(month, "September") == 0) {
        monthFormat = strdup("09");
    } else if (strcmp(month, "October") == 0) {
        monthFormat = strdup("10");
    } else if (strcmp(month, "November") == 0) {
        monthFormat = strdup("11");
    } else if (strcmp(month, "December") == 0) {
        monthFormat = strdup("12");
    }

    // Concatenate the date components into a specific format
    char* specificFormat = (char*)malloc(strlen(day) + strlen(monthFormat) + strlen(year) + 1);
    strcpy(specificFormat, day);
    strcat(specificFormat, "-");
    strcat(specificFormat, monthFormat);
    strcat(specificFormat, "-");
    strcat(specificFormat, year);

    // Print the specific format date
    printf("%s\n", specificFormat);
}

int main()
{
    // Get the natural language date from the user
    char date[100];
    printf("Enter a natural language date (e.g. 'March 12th, 2021'): ");
    scanf("%s", date);

    // Convert the natural language date to a specific format
    convertDate(date);

    return 0;
}