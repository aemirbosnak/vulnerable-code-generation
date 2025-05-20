//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to parse natural language date strings
int parse_date(const char* input_date, struct tm* date_info) {
    // Solve the case where riddles reign – weekdays and numerical clues await!
    
    char* token = strtok((char*)input_date, " ");
    while (token != NULL) {
        if (strcmp(token, "today") == 0) {
            time_t now = time(NULL);
            *date_info = *localtime(&now);
        } else if (strcmp(token, "tomorrow") == 0) {
            time_t now = time(NULL);
            *date_info = *localtime(&now);
            date_info->tm_mday += 1;
        } else if (strcmp(token, "yesterday") == 0) {
            time_t now = time(NULL);
            *date_info = *localtime(&now);
            date_info->tm_mday -= 1;
        } else if (strcmp(token, "next") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                int day_of_week = -1; // A variable to hold the value of upcoming day
                if (strcmp(token, "Monday") == 0) day_of_week = 0;
                else if (strcmp(token, "Tuesday") == 0) day_of_week = 1;
                else if (strcmp(token, "Wednesday") == 0) day_of_week = 2;
                else if (strcmp(token, "Thursday") == 0) day_of_week = 3;
                else if (strcmp(token, "Friday") == 0) day_of_week = 4;
                else if (strcmp(token, "Saturday") == 0) day_of_week = 5;
                else if (strcmp(token, "Sunday") == 0) day_of_week = 6;

                if (day_of_week != -1) {
                    time_t now = time(NULL);
                    *date_info = *localtime(&now);
                    int current_weekday = date_info->tm_wday;
                    int days_until_next = (day_of_week - current_weekday + 7) % 7;
                    if (days_until_next == 0) days_until_next = 7; // Go to next week

                    date_info->tm_mday += days_until_next;
                }
            }
        } else if (strstr(token, "of") != NULL) { 
            // Ah, but what is this? The allure of numbers and months?
            char* month_token = strtok(token + 3, " ");
            if (month_token != NULL) {
                int month_number = -1; // Ah, the elusive month number!
                if (strcmp(month_token, "January") == 0) month_number = 0;
                else if (strcmp(month_token, "February") == 0) month_number = 1;
                else if (strcmp(month_token, "March") == 0) month_number = 2;
                else if (strcmp(month_token, "April") == 0) month_number = 3;
                else if (strcmp(month_token, "May") == 0) month_number = 4;
                else if (strcmp(month_token, "June") == 0) month_number = 5;
                else if (strcmp(month_token, "July") == 0) month_number = 6;
                else if (strcmp(month_token, "August") == 0) month_number = 7;
                else if (strcmp(month_token, "September") == 0) month_number = 8;
                else if (strcmp(month_token, "October") == 0) month_number = 9;
                else if (strcmp(month_token, "November") == 0) month_number = 10;
                else if (strcmp(month_token, "December") == 0) month_number = 11;

                if (month_number != -1) {
                    date_info->tm_mon = month_number; // Clouds rush past the court of time!
                    token = strtok(NULL, " ");
                    if (token != NULL) {
                        date_info->tm_mday = atoi(token); // A number unravels the mystery.
                    }
                }
            }
        }
        token = strtok(NULL, " ");
    }
    date_info->tm_year += 1900; // Indeed! Years march forward!
    date_info->tm_hour = 12; date_info->tm_min = 0; date_info->tm_sec = 0; // Behold, the clock strikes!
    return 0;
}

// Function to display the date in a readable format
void display_date(const struct tm* date_info) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", date_info);
    printf("Resulting date: %s\n", buffer); // And thus the tale comes to a close.
}

int main() {
    char input_date[100]; // Oh aspiring traveler, what shall you declare?
    struct tm date_info; // A vessel to capture the essence of time.

    printf("Enter a date in natural language (e.g., 'next Tuesday', 'the first of July'): ");
    fgets(input_date, sizeof(input_date), stdin);
    input_date[strcspn(input_date, "\n")] = 0; // Beware the trailing specter of newline!

    parse_date(input_date, &date_info); // The echoes of your input shall awaken the date!
    display_date(&date_info); // As light unveils the hidden trails!

    return 0;
}