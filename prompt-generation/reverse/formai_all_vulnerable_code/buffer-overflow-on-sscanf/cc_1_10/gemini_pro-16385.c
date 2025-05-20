//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Sherlock Holmes
// Watson, we need to devise a converter to decipher the enigmatic dates concealed within these ancient scrolls. Engage your analytical prowess!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Roman numeral equivalents for each digit
const char* roman_numerals[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
const char* month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Function to convert a Roman numeral to an integer
int roman_to_int(char* roman_numeral) {
    int result = 0;
    int i;

    // Iterate through the Roman numeral string
    for (i = 0; i < strlen(roman_numeral); i++) {
        // Determine the value of the current character
        switch (roman_numeral[i]) {
            case 'I':
                result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                result += 10;
                break;
            default:
                // Invalid Roman numeral character
                return -1;
        }

        // Check if the next character is a smaller value
        if (i < strlen(roman_numeral) - 1 && roman_numeral[i] < roman_numeral[i + 1]) {
            result -= 1;
        }
    }

    // Return the result
    return result;
}

// Function to convert a date string in the format "DD MMM YYYY" to a Julian day number
int date_to_julian(char* date_string) {
    // Extract the day, month, and year from the date string
    char day_string[3];
    char month_string[4];
    char year_string[5];
    sscanf(date_string, "%s %s %s", day_string, month_string, year_string);

    // Convert the day, month, and year to integers
    int day = atoi(day_string);
    int month = roman_to_int(month_string);
    int year = atoi(year_string);

    // Check if the date is valid
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1) {
        return -1;
    }

    // Calculate the Julian day number
    int julian_day = day;
    for (int i = 1; i < month; i++) {
        julian_day += 31;
    }
    julian_day += (year - 1) * 365;
    julian_day += (year - 1) / 4;
    julian_day -= (year - 1) / 100;
    julian_day += (year - 1) / 400;

    // Return the Julian day number
    return julian_day;
}

// Function to convert a Julian day number to a date string in the format "DD MMM YYYY"
char* julian_to_date(int julian_day) {
    // Declare a buffer to store the date string
    char* date_string = malloc(11);

    // Calculate the year, month, and day from the Julian day number
    int year = julian_day / 365 + 1;
    int month = (julian_day - (year - 1) * 365) / 31;
    int day = julian_day - (year - 1) * 365 - month * 31;

    // Convert the year, month, and day to strings
    char year_string[5];
    char month_string[4];
    char day_string[3];
    sprintf(year_string, "%d", year);
    sprintf(month_string, "%s", month_names[month - 1]);
    sprintf(day_string, "%d", day);

    // Construct the date string
    strcpy(date_string, day_string);
    strcat(date_string, " ");
    strcat(date_string, month_string);
    strcat(date_string, " ");
    strcat(date_string, year_string);

    // Return the date string
    return date_string;
}

// Main function
int main() {
    // Declare variables to store the date and Julian day number
    char date_string[11];
    int julian_day;

    // Prompt the user to enter a date in the format "DD MMM YYYY"
    printf("Enter a date in the format \"DD MMM YYYY\": ");
    scanf("%s", date_string);

    // Convert the date string to a Julian day number
    julian_day = date_to_julian(date_string);

    // Check if the date is valid
    if (julian_day == -1) {
        printf("Invalid date.\n");
        return 1;
    }

    // Convert the Julian day number to a date string
    char* new_date_string = julian_to_date(julian_day);

    // Print the original date and the converted date
    printf("Original date: %s\n", date_string);
    printf("Converted date: %s\n", new_date_string);

    // Free the memory allocated for the new date string
    free(new_date_string);

    return 0;
}