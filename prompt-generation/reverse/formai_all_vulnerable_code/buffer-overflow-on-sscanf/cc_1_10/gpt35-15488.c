//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 100

// Function prototypes
int is_valid_date_format(char* date);
int is_leap_year(int year);
int days_in_month(int month, int year);
void convert_date(char* date, char* converted_date);

int main() {
    // Declare variables
    char date[BUFFER_SIZE], converted_date[BUFFER_SIZE];
    int num_players;

    // Get user input
    printf("Enter a date in natural language format (e.g. January 1, 2022): ");
    fgets(date, BUFFER_SIZE, stdin);
    date[strcspn(date, "\n")] = '\0'; // Remove newline character from input

    // Check if date format is valid
    if (!is_valid_date_format(date)) {
        printf("Sorry, the date format is not valid.\n");
        return 1;
    }

    // Get number of players
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    getchar(); // Remove newline character from input

    // Convert date for each player and output results
    for (int i = 1; i <= num_players; i++) {
        printf("Player %d's date: ", i);
        convert_date(date, converted_date);
        printf("%s\n", converted_date);
    }

    return 0;
}

// Check if date format is valid
int is_valid_date_format(char* date) {
    int month, day, year;

    if (sscanf(date, "%d/%d/%d", &month, &day, &year) == 3) { // Check if date is in numeric format
        if (month < 1 || month > 12) return 0;
        if (day < 1 || day > days_in_month(month, year)) return 0;
        if (year < 0) return 0;
        return 1;
    } else if (sscanf(date, "%*s %d, %d", &day, &year) == 2) { // Check if date is in natural language format
        if (day < 1 || day > 31) return 0;
        if (year < 0) return 0;
        char* month_string = strtok(date, " ");
        while (month_string != NULL) {
            if (strlen(month_string) >= 3 && isalpha(month_string[0]) && isalpha(month_string[1]) && isalpha(month_string[2])) {
                month_string[0] = toupper(month_string[0]);
                month_string[1] = tolower(month_string[1]);
                month_string[2] = tolower(month_string[2]);
                const char* month_names[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
                for (int i = 0; i < 12; i++) {
                    if (strcmp(month_string, month_names[i]) == 0) {
                        month = i + 1;
                        return 1;
                    }
                }
            }
            month_string = strtok(NULL, " ");
        }
    }

    return 0;
}

// Check if year is a leap year
int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1; // Leap year
    } else {
        return 0; // Not a leap year
    }
}

// Get number of days in a month
int days_in_month(int month, int year) {
    const int days[] = { 31, is_leap_year(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return days[month - 1];
}

// Convert date to C natural language format
void convert_date(char* date, char* converted_date) {
    int month, day, year;
    sscanf(date, "%*s %d, %d", &day, &year); // Get day and year from input
    char* month_string = strtok(date, " "); // Get month from input
    while (month_string != NULL) {
        if (strlen(month_string) >= 3 && isalpha(month_string[0]) && isalpha(month_string[1]) && isalpha(month_string[2])) {
            month_string[0] = toupper(month_string[0]);
            month_string[1] = tolower(month_string[1]);
            month_string[2] = tolower(month_string[2]);
            const char* month_names[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
            for (int i = 0; i < 12; i++) {
                if (strcmp(month_string, month_names[i]) == 0) {
                    month = i + 1;
                }
            }
        }
        month_string = strtok(NULL, " ");
    }
    sprintf(converted_date, "%04d/%02d/%02d", year, month, day); // Format date as C natural language
}