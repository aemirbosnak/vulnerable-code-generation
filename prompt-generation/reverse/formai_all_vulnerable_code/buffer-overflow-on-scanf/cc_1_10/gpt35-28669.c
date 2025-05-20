//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>
#include <string.h>

// Function to calculate the number of days in a given month
int getDaysInMonth(int month, int year) {
    switch(month) {
        case 1: return 31;
        case 2: 
            if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                return 29;
            else
                return 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return -1;
    }
}

// Function to convert the given date from string to int format
void convertDate(const char* date, int* day, int* month, int* year) {
    // Extracting day, month and year from string format
    int len = strlen(date);
    char d[3], m[3], y[5];
    int index = 0;
    for(int i = 0; i < len; i++) {
        if(date[i] == '/') {
            index++;
            continue;
        }
        if(index == 0) {
            d[i] = date[i];
        } else if(index == 1) {
            m[i-2] = date[i];
        } else if(index == 2) {
            y[i-5] = date[i];
        }
    }
    // Converting the extracted day, month and year into integer format
    sscanf(d, "%d", day);
    sscanf(m, "%d", month);
    sscanf(y, "%d", year);
}

// Function to convert the given date into numerical representation
int convertToNumericDate(char* date) {
    int day, month, year;
    convertDate(date, &day, &month, &year);
    int numDays = 0;
    // Calculating the number of days passed since Jan 1, year 1 AD
    for(int i = 1; i < year; i++) {
        if(i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
            numDays += 366;
        else
            numDays += 365;
    }
    for(int i = 1; i < month; i++) {
        numDays += getDaysInMonth(i, year);
    }
    numDays += day;
    return numDays;
}

// Function to convert the given numerical date into natural language date
void convertToNaturalDate(int numDate, char* naturalDate) {
    char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int year = 1, month = 1, day = 0;
    int n = numDate;
    // Calculating the year, month and day from the given numerical date
    while(n > 0) {
        int daysInYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 366 : 365;
        if(n - daysInYear >= 0) {
            n -= daysInYear;
            year++;
        } else {
            int i;
            for(i = 1; i <= 12; i++) {
                int daysInMonth = getDaysInMonth(i, year);
                if(n - daysInMonth >= 0)
                    n -= daysInMonth;
                else {
                    day = n;
                    month = i;
                    break;
                }
            }
            break;
        }
    }
    // Formatting the natural language date
    sprintf(naturalDate, "%s %d, %d", months[month-1], day, year);
}

// Driver function for testing the date conversion functions
int main() {
    char date[11];
    printf("Enter a date in mm/dd/yyyy format: ");
    scanf("%s", date);
    int numericDate = convertToNumericDate(date);
    char naturalDate[20];
    convertToNaturalDate(numericDate, naturalDate);
    printf("The natural language representation of the given date is: %s\n", naturalDate);
    return 0;
}