//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

// Function to check if a string is a valid date in the format "DD/MM/YYYY"
int is_valid_date(const char *date_str) {
    struct tm tm = {0};
    strptime(date_str, "%d/%m/%Y", &tm);
    return!mktime(&tm);
}

// Function to convert a date string to a numerical format
int date_to_num(const char *date_str) {
    int day, month, year;
    sscanf(date_str, "%d/%d/%d", &day, &month, &year);
    return (year * 10000) + (month * 100) + day;
}

// Function to convert a numerical date to a string in the format "DD/MM/YYYY"
void num_to_date(int num, char *date_str) {
    int day, month, year;
    year = num / 10000;
    month = (num / 100) % 100;
    day = num % 100;
    sprintf(date_str, "%d-%d-%d", day, month, year);
}

// Function to convert a string to title case (first letter of each word capitalized)
void to_title_case(char *str) {
    int i = 0;
    while (str[i]) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
        i++;
    }
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    char input_date[20];
    char output_date[20];

    printf("Enter a date in the format 'DD/MM/YYYY': ");
    scanf("%s", input_date);

    if (!is_valid_date(input_date)) {
        printf("Invalid date format. Please enter a valid date.\n");
        return 1;
    }

    int num_date = date_to_num(input_date);
    num_to_date(num_date, output_date);

    printf("Numerical representation of the date: %s\n", output_date);

    to_title_case(output_date);
    printf("Title case representation of the date: %s\n", output_date);

    return 0;
}