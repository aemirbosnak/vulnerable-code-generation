//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Turing
// Alan Turing's Date Converter for ACE Machine

// Constants
#define MONTHS 12
#define LEAP_YEAR 28

// Struct for date
struct date {
    int day;
    int month;
    int year;
};

// Function to check if year is leap
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to convert date string to date struct
struct date parseDate(char* dateStr) {
    struct date result;
    int day, month, year, temp;

    sscanf(dateStr, "%d/%d/%d", &month, &day, &year);

    if (month < 1 || month > MONTHS || day < 1) {
        result.day = 0;
        result.month = 0;
        result.year = 0;
        return result;
    }

    result.month = month;
    result.day = day;

    if (month < 3) {
        year -= 1;
    }

    temp = (year / 100) * 100;
    result.year = year + (temp / 4) - (temp / 100) + (temp / 400);

    if (isLeapYear(result.year) && (month == 2 && day > LEAP_YEAR)) {
        result.day = 0;
    }

    return result;
}

// Function to print date
void printDate(struct date date) {
    if (date.day == 0 || date.month == 0 || date.year == 0) {
        printf("Invalid date\n");
        return;
    }

    printf("%d/%d/%d", date.month, date.day, date.year);
}

int main() {
    char dateStr[20];
    struct date date;

    printf("Enter date in format MM/DD/YYYY: ");
    scanf("%s", dateStr);

    date = parseDate(dateStr);

    printDate(date);

    return 0;
}