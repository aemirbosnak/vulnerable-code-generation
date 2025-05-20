//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Happy Date Struct
typedef struct {
    int day;
    int month;
    int year;
} HappyDate;

// Function Prototypes
void HappyPrint(const HappyDate* happyDate);
void HappyScan(char* dateString, HappyDate* happyDate);

int main() {
    HappyDate happyDate;
    char dateString[30];

    printf("Happiness is when your date is correctly converted!\n");
    printf("Enter date in format DD/MM/YYYY: ");
    fgets(dateString, sizeof(dateString), stdin);

    // Remove newline character from fgets
    if (dateString[strlen(dateString) - 1] == '\n') {
        dateString[strlen(dateString) - 1] = '\0';
    }

    HappyScan(dateString, &happyDate);
    HappyPrint(&happyDate);

    return 0;
}

// Scans a date string and stores it in HappyDate structure
void HappyScan(char* dateString, HappyDate* happyDate) {
    int day, month, year;
    int scanIndex = 0;

    // Scan day
    day = 0;
    while (isdigit(dateString[scanIndex])) {
        day = day * 10 + (dateString[scanIndex] - '0');
        scanIndex++;
    }
    happyDate->day = day;

    // Check for invalid day
    if (day > 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)) {
        printf("Error: Invalid day! Try again.\n");
        exit(1);
    }

    // Scan slash (/)
    while (dateString[scanIndex] != '/') {
        scanIndex++;
        if (dateString[scanIndex] == '\0') {
            printf("Error: Invalid date format! Try again.\n");
            exit(1);
        }
    }
    scanIndex++;

    // Scan month
    month = 0;
    while (isdigit(dateString[scanIndex])) {
        month = month * 10 + (dateString[scanIndex] - '0');
        scanIndex++;
    }
    happyDate->month = month;

    // Check for invalid month
    if (month > 12) {
        printf("Error: Invalid month! Try again.\n");
        exit(1);
    }

    // Scan slash (/)
    while (dateString[scanIndex] != '/') {
        scanIndex++;
        if (dateString[scanIndex] == '\0') {
            printf("Error: Invalid date format! Try again.\n");
            exit(1);
        }
    }
    scanIndex++;

    // Scan year
    year = 0;
    while (isdigit(dateString[scanIndex])) {
        year = year * 10 + (dateString[scanIndex] - '0');
        scanIndex++;
    }
    happyDate->year = year;
}

// Prints a HappyDate in format DD/MM/YYYY
void HappyPrint(const HappyDate* happyDate) {
    printf("Your date is: %02d/%02d/%04d\n", happyDate->day, happyDate->month, happyDate->year);
}