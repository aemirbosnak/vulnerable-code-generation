//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert month name to month number
int month_to_number(const char *month) {
    if (strcmp(month, "January") == 0) return 1;
    if (strcmp(month, "February") == 0) return 2;
    if (strcmp(month, "March") == 0) return 3;
    if (strcmp(month, "April") == 0) return 4;
    if (strcmp(month, "May") == 0) return 5;
    if (strcmp(month, "June") == 0) return 6;
    if (strcmp(month, "July") == 0) return 7;
    if (strcmp(month, "August") == 0) return 8;
    if (strcmp(month, "September") == 0) return 9;
    if (strcmp(month, "October") == 0) return 10;
    if (strcmp(month, "November") == 0) return 11;
    if (strcmp(month, "December") == 0) return 12;
    return -1; // Month not found
}

// Function to convert date from "DD Month YYYY" to "YYYY-MM-DD"
void convert_date(const char *input_date, char *output_date) {
    int day = 0, month = 0, year = 0;
    char month_name[20];

    // Scan the input date
    if (sscanf(input_date, "%d %s %d", &day, month_name, &year) != 3) {
        strcpy(output_date, "Invalid date format!");
        return;
    }

    // Convert month name to month number
    month = month_to_number(month_name);
    if (month == -1) {
        strcpy(output_date, "Invalid month name!");
        return;
    }

    // Format the output date
    sprintf(output_date, "%04d-%02d-%02d", year, month, day);
}

// Main function
int main() {
    char input_date[30];
    char output_date[30];

    printf("🎉 Welcome to the Joyful Date Converter! 🎉\n");
    printf("Enter a date in the format 'DD Month YYYY': ");
    
    // Get the user input
    fgets(input_date, sizeof(input_date), stdin);
    
    // Remove the newline character from the input
    input_date[strcspn(input_date, "\n")] = '\0';

    // Call the conversion function
    convert_date(input_date, output_date);

    // Output the result
    printf("🎊 Converted Date: %s 🎊\n", output_date);
    printf("💖 Thank you for using the Joyful Date Converter! 💖\n");

    return 0;
}