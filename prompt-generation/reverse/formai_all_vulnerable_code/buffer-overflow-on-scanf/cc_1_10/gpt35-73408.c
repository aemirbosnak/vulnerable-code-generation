//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: surprised
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void print_greeting();
void print_farewell();
void convert_date(char input[]);

// main function
int main()
{
    print_greeting();
    
    char input[100];
    do {
        printf("Enter a date in natural language (e.g. 'today', 'next Friday', 'October 31st'): ");
        scanf("%[^\n]", input);
        getchar();
        convert_date(input);
        printf("Enter another date? (y/n): ");
        char response = getchar();
        if (tolower(response) == 'n') {
            break;
        }
        getchar();
    } while (1);
    
    print_farewell();
    return 0;
}

// function definitions
void print_greeting() {
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("I can convert dates like 'today' or 'next Wednesday' to a numerical date.\n");
    printf("But keep an eye out for surprises along the way!\n");
}

void print_farewell() {
    printf("Thank you for using the Natural Language Date Converter. Have a great day!\n");
}

void convert_date(char input[]) {
    // check for special dates
    if (strcmp(input, "pi day") == 0) {
        printf("Wow, it's Pi Day! March 14th.\n");
        return;
    }
    
    // get current time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    
    // add the requested amount of days
    if (strcmp(input, "yesterday") == 0) {
        t -= 86400;
    } else if (strcmp(input, "today") != 0) {
        // calculate the number of days to add
        int day_of_week = tm->tm_wday;
        int days_to_add;
        if (day_of_week == 5) {
            days_to_add = 2;
        } else if (day_of_week == 6) {
            days_to_add = 1;
        } else {
            days_to_add = 1 + (7 + (input[0] - 'a' + 7 - day_of_week) % 7) % 7;
        }
        // add the days to the current time
        t += 86400 * days_to_add;
    }
    
    // convert to struct tm and print the date
    tm = localtime(&t);
    printf("The date on %s is %02d/%02d/%04d.\n", input, tm->tm_mon + 1, tm->tm_mday, tm->tm_year + 1900);
}