//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
// Welcome to the Natural Language Date Converter program!

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to remove leading and trailing whitespaces from strings
char* trim(char* str) {
    char* end;

    // Remove leading whitespaces
    while (isspace((unsigned char)*str)) {
        str++;
    }

    // Return if string is empty
    if (*str == '\0') {
        return str;
    }

    // Remove trailing whitespaces
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    // Null-terminate the string
    *(end+1) = '\0';

    return str;
}

// Function to convert string month to integer month
int get_month_number(char* month) {
    char* months[] = {"January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December"};
    int month_number = 0;
    
    // Loop through months array to get month number
    for (int i = 0; i < 12; i++) {
        // Convert both strings to lowercase and compare
        if (strcasecmp(months[i], month) == 0) {
            month_number = i + 1;
            break;
        }
    }
    
    return month_number;
}

// Function to convert natural language date to numeric date
char* natural_to_numeric(char* date) {
    char* numeric_date = (char*) malloc(sizeof(char) * 11);
    char day[3], year[5], month[10], copy_date[strlen(date)];
    int i = 0;

    // Copy date to temporary variable for manipulation
    strcpy(copy_date, date);
    
    // Get day from date
    sscanf(copy_date, "%2s", day);
    i += strlen(day);
    
    // Get month from date
    sscanf(copy_date + i, "%10s", month);
    i += strlen(month);
    
    // Get year from date
    sscanf(copy_date + i, "%4s", year);
    i += strlen(year);
    
    // Convert month from string to integer
    int month_number = get_month_number(month);
    
    // Create numeric date string in format "MM/DD/YYYY"
    sprintf(numeric_date, "%02d/%s/%s", month_number, day, year);

    return trim(numeric_date);
}

int main() {
    char natural_date[50], option;
    
    printf("Welcome to Natural Language Date Converter!\n");
    
    do {
        // Get natural language date from user
        printf("\nEnter a date in natural language: ");
        fgets(natural_date, sizeof(natural_date), stdin);
        
        // Remove newline character from input
        natural_date[strcspn(natural_date, "\n")] = 0;
        
        // Convert natural language date to numeric date
        char* numeric_date = natural_to_numeric(natural_date);
        printf("Numeric date: %s\n", numeric_date);
        
        // Free memory allocated for numeric date
        free(numeric_date);
        
        // Ask user if they want to convert another date
        printf("\nDo you want to convert another date? (y/n) ");
        scanf(" %c", &option);
        getchar();
    } while (tolower(option) == 'y');
    
    printf("\nThank you for using Natural Language Date Converter!\n");
    
    return 0;
}