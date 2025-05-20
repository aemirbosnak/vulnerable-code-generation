//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// struct to hold the date components
typedef struct {
    int year;
    int month;
    int day;
} Date;

// async function to read user input
void read_input(Date *date) {
    printf("Enter date in format YYYY-MM-DD: ");
    // allocate memory for input string
    char *input = malloc(11 * sizeof(char));
    fgets(input, 11, stdin);
    // parse year, month, and day from input string
    sscanf(input, "%d-%d-%d", &date->year, &date->month, &date->day);
    // free memory for input string
    free(input);
}

// async function to convert date to natural language format
void convert_to_natural_language(Date *date) {
    // array of month names
    const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // determine month name
    char *month_name = malloc(sizeof(char) * 10);
    strcpy(month_name, months[date->month - 1]);

    // determine day suffix
    char *day_suffix;
    switch (date->day % 10) {
        case 1:
            day_suffix = "st";
            break;
        case 2:
            day_suffix = "nd";
            break;
        case 3:
            day_suffix = "rd";
            break;
        default:
            day_suffix = "th";
            break;
    }

    // print natural language representation of date
    printf("%s %d%s, %d\n", month_name, date->day, day_suffix, date->year);

    // free memory for month name
    free(month_name);
}

// async main function
int main() {
    Date date;
    // read user input
    read_input(&date);
    // convert to natural language and print
    convert_to_natural_language(&date);
    return 0;
}