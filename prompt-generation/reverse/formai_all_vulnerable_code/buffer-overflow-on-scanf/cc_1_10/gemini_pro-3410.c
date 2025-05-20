//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the date
typedef struct date {
    int year;
    int month;
    int day;
} date;

// Define the function to convert a string to a date
date string_to_date(char *str) {
    date d;
    char *p;
    
    // Get the year
    p = strchr(str, '-');
    if (p == NULL) {
        fprintf(stderr, "Invalid date format\n");
        exit(EXIT_FAILURE);
    }
    *p = '\0';
    d.year = atoi(str);
    
    // Get the month
    str = p + 1;
    p = strchr(str, '-');
    if (p == NULL) {
        fprintf(stderr, "Invalid date format\n");
        exit(EXIT_FAILURE);
    }
    *p = '\0';
    d.month = atoi(str);
    
    // Get the day
    str = p + 1;
    d.day = atoi(str);
    
    return d;
}

// Define the function to print a date
void print_date(date d) {
    printf("%d-%02d-%02d\n", d.year, d.month, d.day);
}

// Define the main function
int main() {
    // Get the date from the user
    char str[11];
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", str);
    
    // Convert the date to a struct
    date d = string_to_date(str);
    
    // Print the date
    printf("The date is: ");
    print_date(d);
    
    return 0;
}