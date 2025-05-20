//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to check if a string is a valid date
int is_valid_date(char *date_str) {
    struct tm tm;
    strptime(date_str, "%d/%m/%Y", &tm);
    if (mktime(&tm) == -1) {
        return 0;
    }
    return 1;
}

// Function to convert a string to a date
struct tm str_to_tm(char *date_str) {
    struct tm tm;
    strptime(date_str, "%d/%m/%Y", &tm);
    return tm;
}

// Function to convert a date to a string
char *tm_to_str(struct tm *tm) {
    char buf[20];
    strftime(buf, 20, "%d/%m/%Y", tm);
    return strdup(buf);
}

// Function to convert a string to a time_t
time_t str_to_time(char *date_str) {
    struct tm tm;
    strptime(date_str, "%d/%m/%Y", &tm);
    return mktime(&tm);
}

// Function to print a date
void print_date(struct tm *tm) {
    printf("%d/%02d/%02d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);
}

int main() {
    char input[80];
    char *date_str;
    struct tm tm;

    // Prompt the user for a date
    printf("Enter a date (dd/mm/yyyy): ");
    if (fgets(input, 80, stdin) == NULL) {
        printf("Error: Input too long.\n");
        return 1;
    }

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Convert the input string to a date
    date_str = strdup(input);
    if (!is_valid_date(date_str)) {
        printf("Error: Invalid date.\n");
        return 1;
    }

    // Convert the date to a time_t
    time_t time = str_to_time(date_str);

    // Convert the time_t to a struct tm
    tm = *localtime(&time);

    // Print the date
    printf("The date is: ");
    print_date(&tm);

    // Convert the date to a string
    char *date_str2 = tm_to_str(&tm);
    printf("The date as a string is: %s\n", date_str2);

    // Free the memory used by the date strings
    free(date_str);
    free(date_str2);

    return 0;
}