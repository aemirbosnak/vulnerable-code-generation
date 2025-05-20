//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 20

typedef struct date_info {
    char date[MAX_LENGTH];
    char month[MAX_LENGTH];
    char day[MAX_LENGTH];
} date_info;

date_info read_date(const char* date_string) {
    date_info date_info_struct;
    char* date_parts[3];
    int i;

    // Separate date string into month, day and year parts
    date_parts[0] = strtok(date_string, "-");
    date_parts[1] = strtok(NULL, "-");
    date_parts[2] = strtok(NULL, "-");

    // Initialize date_info_struct
    memset(date_info_struct.date, '\0', sizeof(date_info_struct.date));
    memset(date_info_struct.month, '\0', sizeof(date_info_struct.month));
    memset(date_info_struct.day, '\0', sizeof(date_info_struct.day));

    // Set date_info_struct based on date parts
    for (i = 0; i < 3; i++) {
        if (date_parts[i]!= NULL) {
            strcpy(date_info_struct.date, date_parts[i]);
        }
    }

    return date_info_struct;
}

void convert_date(date_info* date_info_struct) {
    char month[MAX_LENGTH];
    char day[MAX_LENGTH];
    char year[MAX_LENGTH];
    int len_month, len_day, len_year;

    // Convert date_info_struct to formatted string
    len_month = strlen(date_info_struct->month);
    len_day = strlen(date_info_struct->day);
    len_year = strlen(date_info_struct->date);

    // Copy formatted date to month, day and year variables
    strcpy(month, date_info_struct->month);
    strcpy(day, date_info_struct->day);
    strcpy(year, date_info_struct->date);

    // Format date string
    printf("Date: %s-%s-%s\n", month, day, year);
}

int main() {
    date_info date_info_struct;
    const char* date_string = "2022-02-21";

    // Read date string from user
    printf("Enter a date in the format 'YYYY-MM-DD': ");
    scanf("%s", date_string);

    // Read date string and convert to date_info_struct
    date_info_struct = read_date(date_string);

    // Convert date_info_struct to formatted string
    convert_date(&date_info_struct);

    // Print formatted date string
    printf("Formatted date: %s-%s-%s\n", date_info_struct.month, date_info_struct.day, date_info_struct.date);

    return 0;
}