//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the months of the year
char *months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Define the days of the week
char *days[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

// Convert a date from the format "dd/mm/yyyy" to the format "yyyy-mm-dd"
char *convert_date(char *date) {
    char *new_date = malloc(11);
    sscanf(date, "%2d/%2d/%4d", &new_date[8], &new_date[5], &new_date[0]);
    new_date[4] = '-';
    new_date[7] = '-';
    new_date[10] = '\0';
    return new_date;
}

// Get the day of the week for a given date
char *get_day_of_week(char *date) {
    char *new_date = convert_date(date);
    int year, month, day;
    sscanf(new_date, "%4d-%2d-%2d", &year, &month, &day);
    int century = year / 100;
    int year_of_century = year % 100;
    int month_code;
    switch (month) {
        case 1: month_code = 1; break;
        case 2: month_code = 4; break;
        case 3: month_code = 4; break;
        case 4: month_code = 0; break;
        case 5: month_code = 2; break;
        case 6: month_code = 5; break;
        case 7: month_code = 0; break;
        case 8: month_code = 3; break;
        case 9: month_code = 6; break;
        case 10: month_code = 1; break;
        case 11: month_code = 4; break;
        case 12: month_code = 6; break;
    }
    int day_of_week = (day + (26 * (month_code + 1) - 2) / 10 + year_of_century + year_of_century / 4 + century / 4 - 2 * century) % 7;
    free(new_date);
    return days[day_of_week];
}

// Print the date in the format "dd/mm/yyyy (day of week)"
void print_date(char *date) {
    char *day_of_week = get_day_of_week(date);
    printf("%s (%s)\n", date, day_of_week);
}

int main() {
    // Get the date from the user
    char date[11];
    printf("Enter the date in the format dd/mm/yyyy: ");
    scanf("%s", date);

    // Print the date in the format "dd/mm/yyyy (day of week)"
    print_date(date);

    return 0;
}