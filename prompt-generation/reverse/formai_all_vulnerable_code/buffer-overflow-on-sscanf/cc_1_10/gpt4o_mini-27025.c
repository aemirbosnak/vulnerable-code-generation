//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

void print_current_time() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char buffer[26];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Current Date and Time: %s\n", buffer);
}

int is_valid_date(const char *date) {
    struct tm tm;
    return strptime(date, "%Y-%m-%d", &tm) != NULL;
}

void convert_natural_language_to_date(const char *input) {
    char date_str[MAX_LENGTH];
    char month_str[20];
    int day, month, year;

    if (sscanf(input, "on %d %s %d", &day, month_str, &year) == 3) {
        if (strcmp(month_str, "January") == 0) month = 1;
        else if (strcmp(month_str, "February") == 0) month = 2;
        else if (strcmp(month_str, "March") == 0) month = 3;
        else if (strcmp(month_str, "April") == 0) month = 4;
        else if (strcmp(month_str, "May") == 0) month = 5;
        else if (strcmp(month_str, "June") == 0) month = 6;
        else if (strcmp(month_str, "July") == 0) month = 7;
        else if (strcmp(month_str, "August") == 0) month = 8;
        else if (strcmp(month_str, "September") == 0) month = 9;
        else if (strcmp(month_str, "October") == 0) month = 10;
        else if (strcmp(month_str, "November") == 0) month = 11;
        else if (strcmp(month_str, "December") == 0) month = 12;
        else {
            printf("Invalid month\n");
            return;
        }

        snprintf(date_str, sizeof(date_str), "%04d-%02d-%02d", year, month, day);
        if (is_valid_date(date_str)) {
            printf("Natural Language Date: %s is converted to Date: %s\n", input, date_str);
        } else {
            printf("The date %s is not valid\n", date_str);
        }
    } else {
        printf("Invalid input format. Use: 'on <day> <month-name> <year>'\n");
        return;
    }
}

void cut_the_string(const char* str, char* first, char* second) {
    int i = 0;
    while (str[i] != ' ' && str[i] != '\0') {
        first[i] = str[i];
        i++;
    }
    first[i] = '\0';
    
    if (str[i] != '\0') {
        i++; // skip the space
        int j = 0;
        while (str[i] != '\0') {
            second[j++] = str[i++];
        }
        second[j] = '\0';
    } else {
        second[0] = '\0'; // no second part
    }
}

void main_menu() {
    printf("=== Natural Language Date Converter ===\n");
    printf("1. Convert Natural Language Date\n");
    printf("2. Show Current Date and Time\n");
    printf("3. Exit\n");
}

int main() {
    char input[MAX_LENGTH];
    int choice;

    while (1) {
        main_menu();
        
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character after choice

        switch (choice) {
            case 1:
                printf("Enter a date in natural language (e.g., 'on 25 December 2021'): ");
                fgets(input, MAX_LENGTH, stdin);
                strtok(input, "\n"); // Removing the newline character
                convert_natural_language_to_date(input);
                break;

            case 2:
                print_current_time();
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
                break;
        }
    }

    return 0;
}