//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void display_menu();
void convert_date(const char *input_date);
int validate_date(const char *date_str);
void display_formatted_date(struct tm *date_info);

int main() {
    char input_date[100];
    char continue_choice;

    printf("🎉 Welcome to the C Natural Language Date Converter! 🎉\n");
    printf("This program will allow you to convert natural language date inputs into a formatted date!\n\n");

    do {
        display_menu(); // Show menu options
        printf("Please enter a date (e.g., 25th December 2023): ");
        fgets(input_date, sizeof(input_date), stdin);
        input_date[strcspn(input_date, "\n")] = '\0';  // Removing trailing newline

        // Validate and convert date
        if (validate_date(input_date)) {
            convert_date(input_date);
        } else {
            printf("🚫 Oops! That doesn't seem like a valid date. Please try again! 🚫\n");
        }

        printf("\nWould you like to convert another date? (y/n): ");
        scanf(" %c", &continue_choice);
        getchar(); // Clear newline from buffer

    } while (continue_choice == 'y' || continue_choice == 'Y');

    printf("Thank you for using the Date Converter! Have a great day! 🌟\n");
    return 0;
}

void display_menu() {
    printf("\n------------------------------------------\n");
    printf("🗓️  C Natural Language Date Converter Menu:\n");
    printf("1. Convert a date from natural language format\n");
    printf("2. Exit\n");
    printf("------------------------------------------\n");
}

int validate_date(const char *date_str) {
    // Simple validation for the date format with spaces
    return strstr(date_str, " ") != NULL; // Ensuring there's at least a space in the string
}

void convert_date(const char *input_date) {
    struct tm date_info = {0};  // Initialize a struct tm for holding date
    char day_str[10], month_str[20];
    int year;

    // Break down the input date into components
    int matches = sscanf(input_date, "%s %s %d", day_str, month_str, &year);
    
    if (matches == 3) {
        // Map the month string to an integer
        int month = -1;
        if (strcasecmp(month_str, "January") == 0) month = 0;
        else if (strcasecmp(month_str, "February") == 0) month = 1;
        else if (strcasecmp(month_str, "March") == 0) month = 2;
        else if (strcasecmp(month_str, "April") == 0) month = 3;
        else if (strcasecmp(month_str, "May") == 0) month = 4;
        else if (strcasecmp(month_str, "June") == 0) month = 5;
        else if (strcasecmp(month_str, "July") == 0) month = 6;
        else if (strcasecmp(month_str, "August") == 0) month = 7;
        else if (strcasecmp(month_str, "September") == 0) month = 8;
        else if (strcasecmp(month_str, "October") == 0) month = 9;
        else if (strcasecmp(month_str, "November") == 0) month = 10;
        else if (strcasecmp(month_str, "December") == 0) month = 11;

        // Simple extraction of the day, ensuring the use of integers
        int day = atoi(day_str);
        
        // Validate day and month (basic validation here)
        if (day < 1 || day > 31 || month == -1) {
            printf("🚫 Invalid date components! Please try again! 🚫\n");
            return;
        }

        // Fill the date_info structure
        date_info.tm_mday = day;
        date_info.tm_mon = month;
        date_info.tm_year = year - 1900; // tm_year starts from 1900

        // Normalize the date and check for validity
        time_t t = mktime(&date_info);
        if (t == -1) {
            printf("🚫 Invalid date! Could be due to days in month overflow. 🚫\n");
            return;
        }

        // Display the formatted date
        display_formatted_date(&date_info);
    } else {
        printf("🚫 Error processing the date! Ensure proper format. 🚫\n");
    }
}

void display_formatted_date(struct tm *date_info) {
    char output_date[100];
    strftime(output_date, sizeof(output_date), "%A, %d %B %Y", date_info);
    printf("🎉 Your formatted date is: %s 🎉\n", output_date);
}