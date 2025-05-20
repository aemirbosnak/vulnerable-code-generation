//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: expert-level
#include <stdio.h>
#include <string.h>

// Function to convert month from string to integer
int month_to_int(char* month) {
    char* months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};

    for(int i = 0; i < 12; i++) {
        if(strcmp(month, months[i]) == 0) {
            return i + 1;   // Return month number (1-12)
        }
    }

    return -1;  // Invalid month entered
}

// Function to convert date string to integer
int date_to_int(char* date) {
    int len = strlen(date);

    if(len != 8) {
        return -1;  // Invalid date format
    }

    int day, month, year;

    // Extract day, month and year from date string
    sscanf(date, "%2d-%2d-%4d", &day, &month, &year);

    // Check validity of extracted day, month and year
    if(day < 1 || day > 31 || month < 1 || month > 12 || year < 1000 || year > 9999) {
        return -1; // Invalid date entered
    }

    return (year * 10000) + (month * 100) + day; // Return date as integer (yyyymmdd)
}

// Function to convert integer date to string date
void int_to_date(int int_date, char* str_date) {
    int year = int_date / 10000;
    int month = (int_date / 100) % 100;
    int day = int_date % 100;

    sprintf(str_date, "%02d-%02d-%04d", day, month, year);
}

int main() {
    printf("Enter date in format dd-mm-yyyy: ");
    char date[20];
    scanf("%s", date);

    // Convert date to integer for easy manipulation
    int int_date = date_to_int(date);

    if(int_date == -1) {
        printf("Invalid date entered!\n");
        return 1;
    }

    int day = int_date % 100;
    int month = (int_date / 100) % 100;
    int year = int_date / 10000;

    printf("Enter desired output format (dd-mm-yyyy or Month dd, yyyy): ");
    char format[20];
    scanf("%s", format);

    if(strcmp(format, "dd-mm-yyyy") == 0) {
        printf("Date in requested format: %s\n", date);
    } else if(strcmp(format, "Month dd, yyyy") == 0) {
        char month_name[20];
        switch(month) {
            case 1:
                strcpy(month_name, "January");
                break;
            case 2:
                strcpy(month_name, "February");
                break;
            case 3:
                strcpy(month_name, "March");
                break;
            case 4:
                strcpy(month_name, "April");
                break;
            case 5:
                strcpy(month_name, "May");
                break;
            case 6:
                strcpy(month_name, "June");
                break;
            case 7:
                strcpy(month_name, "July");
                break;
            case 8:
                strcpy(month_name, "August");
                break;
            case 9:
                strcpy(month_name, "September");
                break;
            case 10:
                strcpy(month_name, "October");
                break;
            case 11:
                strcpy(month_name, "November");
                break;
            case 12:
                strcpy(month_name, "December");
                break;
        }

        printf("Date in requested format: %s %d, %d\n", month_name, day, year);
    } else {
        printf("Invalid format entered!\n");
        return 1;
    }

    return 0;
}