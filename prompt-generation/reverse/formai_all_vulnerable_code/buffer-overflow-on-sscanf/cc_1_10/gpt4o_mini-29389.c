//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to determine the number of days to add or subtract from the current date
int parse_date_expression(const char *expression, struct tm *current_time) {
    int days = 0;
    char modifier[10];
    
    sscanf(expression, "%s %d", modifier, &days);

    if (strcmp(modifier, "next") == 0) {
        if (strstr(expression, "Monday")) days = (1 + 7) % 7;
        else if (strstr(expression, "Tuesday")) days = (2 + 7) % 7;
        else if (strstr(expression, "Wednesday")) days = (3 + 7) % 7;
        else if (strstr(expression, "Thursday")) days = (4 + 7) % 7;
        else if (strstr(expression, "Friday")) days = (5 + 7) % 7;
        else if (strstr(expression, "Saturday")) days = (6 + 7) % 7;
        else if (strstr(expression, "Sunday")) days = (0 + 7) % 7; 
    } else if (strcmp(modifier, "last") == 0) {
        if (strstr(expression, "Monday")) days = (1 - 7) % 7;
        else if (strstr(expression, "Tuesday")) days = (2 - 7) % 7;
        else if (strstr(expression, "Wednesday")) days = (3 - 7) % 7;
        else if (strstr(expression, "Thursday")) days = (4 - 7) % 7;
        else if (strstr(expression, "Friday")) days = (5 - 7) % 7;
        else if (strstr(expression, "Saturday")) days = (6 - 7) % 7;
        else if (strstr(expression, "Sunday")) days = (0 - 7) % 7; 
    } else if (strstr(expression, "from now") != NULL) {
        days = (days > 0) ? days : 0;
    } else if (strstr(expression, "ago") != NULL) {
        days = -days;
    }
    
    return days;
}

// Function to convert current date to a specific format after modifying it
void convert_date(struct tm *date, int days) {
    date->tm_mday += days;

    // Normalize the date
    mktime(date);
}

void format_date(struct tm *date) {
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", date);
    printf("Converted Date: %s\n", buffer);
}

int main() {
    char input[100];
    time_t t = time(NULL);
    struct tm current_time = *localtime(&t);

    printf("Enter a natural language date expression (e.g., 'next Friday', '2 days from now'): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character

    int days = parse_date_expression(input, &current_time);
    convert_date(&current_time, days);
    format_date(&current_time);

    return 0;
}