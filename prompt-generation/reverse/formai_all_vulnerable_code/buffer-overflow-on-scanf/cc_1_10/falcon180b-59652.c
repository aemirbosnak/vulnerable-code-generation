//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to convert a given string to a date
time_t string_to_date(char* str) {
    struct tm tm;
    char* format = "%d/%m/%Y %H:%M:%S";
    strptime(str, format, &tm);
    return mktime(&tm);
}

// Function to convert a date to a string
char* date_to_string(time_t date) {
    struct tm* tm = localtime(&date);
    return asctime(tm);
}

// Function to get the current date and time
char* get_current_date() {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    char* format = "%d/%m/%Y %H:%M:%S";
    char* str = asctime(tm);
    strftime(str, strlen(str), format, tm);
    return str;
}

int main() {
    char* input;
    char* date;
    char* result;

    // Get input from user
    printf("Enter a date in the format 'dd/mm/yyyy hh:mm:ss': ");
    scanf("%s", input);

    // Convert input to a date
    time_t date_value = string_to_date(input);

    // Get the current date and time
    date = get_current_date();

    // Convert date to a string
    result = date_to_string(date_value);

    // Print the result
    printf("The input date is %s\n", result);
    printf("The current date and time is %s\n", date);

    return 0;
}