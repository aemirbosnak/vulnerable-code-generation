//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
// Romeo and Juliet Date Converter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Day names
char *days[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"
};

// Month names
char *months[] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
};

// Converts a day number to a day name
char *day_name(int day) {
    return days[day % 7];
}

// Converts a month number to a month name
char *month_name(int month) {
    return months[month % 12];
}

// Converts a date to a string
char *date_to_string(int day, int month, int year) {
    char *date = malloc(32);
    sprintf(date, "%s, %s %d, %d",
        day_name(day),
        month_name(month),
        day,
        year);
    return date;
}

// Converts a string to a date
void string_to_date(char *date, int *day, int *month, int *year) {
    char *parts[3];
    int i;

    // Split the date into parts
    for (i = 0; i < 3; i++) {
        parts[i] = strtok(date, " ");
    }

    // Convert the parts to numbers
    *day = atoi(parts[1]);
    *month = atoi(parts[2]) - 1;
    *year = atoi(parts[3]);
}

// Main function
int main() {
    // Get the date from the user
    char date[32];
    printf("Enter a date (e.g., Tuesday, March 14, 2023): ");
    gets(date);

    // Convert the date to a number
    int day, month, year;
    string_to_date(date, &day, &month, &year);

    // Print the number
    printf("The date is: %d-%d-%d\n", day, month, year);

    return 0;
}