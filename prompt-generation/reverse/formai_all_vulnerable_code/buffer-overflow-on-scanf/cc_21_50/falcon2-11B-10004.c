//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <string.h>

// Function to convert Natural Language date to machine-readable format
void convertDate(char *date, char *result) {
    int day = 0, month = 0, year = 0;

    // Convert day
    if (strlen(date) > 1 && date[0] == '1') {
        day = 1;
        strncpy(result, "01", 2);
    } else if (strlen(date) > 1 && date[0] == '2') {
        day = 2;
        strncpy(result, "02", 2);
    } else if (strlen(date) > 1 && date[0] == '3') {
        day = 3;
        strncpy(result, "03", 2);
    } else if (strlen(date) > 1 && date[0] == '4') {
        day = 4;
        strncpy(result, "04", 2);
    } else if (strlen(date) > 1 && date[0] == '5') {
        day = 5;
        strncpy(result, "05", 2);
    } else if (strlen(date) > 1 && date[0] == '6') {
        day = 6;
        strncpy(result, "06", 2);
    } else if (strlen(date) > 1 && date[0] == '7') {
        day = 7;
        strncpy(result, "07", 2);
    } else if (strlen(date) > 1 && date[0] == '8') {
        day = 8;
        strncpy(result, "08", 2);
    } else if (strlen(date) > 1 && date[0] == '9') {
        day = 9;
        strncpy(result, "09", 2);
    } else if (strlen(date) > 1 && date[0] == '0') {
        day = 0;
        strncpy(result, "00", 2);
    }

    // Convert month
    if (strlen(date) > 1 && date[1] == '1') {
        month = 1;
        strncpy(result + 2, "01", 2);
    } else if (strlen(date) > 1 && date[1] == '2') {
        month = 2;
        strncpy(result + 2, "02", 2);
    } else if (strlen(date) > 1 && date[1] == '3') {
        month = 3;
        strncpy(result + 2, "03", 2);
    } else if (strlen(date) > 1 && date[1] == '4') {
        month = 4;
        strncpy(result + 2, "04", 2);
    } else if (strlen(date) > 1 && date[1] == '5') {
        month = 5;
        strncpy(result + 2, "05", 2);
    } else if (strlen(date) > 1 && date[1] == '6') {
        month = 6;
        strncpy(result + 2, "06", 2);
    } else if (strlen(date) > 1 && date[1] == '7') {
        month = 7;
        strncpy(result + 2, "07", 2);
    } else if (strlen(date) > 1 && date[1] == '8') {
        month = 8;
        strncpy(result + 2, "08", 2);
    } else if (strlen(date) > 1 && date[1] == '9') {
        month = 9;
        strncpy(result + 2, "09", 2);
    } else if (strlen(date) > 1 && date[1] == '0') {
        month = 0;
        strncpy(result + 2, "00", 2);
    }

    // Convert year
    if (strlen(date) > 3 && date[3] == '1') {
        year = 2010;
        strncpy(result + 4, "10", 2);
    } else if (strlen(date) > 3 && date[3] == '2') {
        year = 2011;
        strncpy(result + 4, "11", 2);
    } else if (strlen(date) > 3 && date[3] == '3') {
        year = 2012;
        strncpy(result + 4, "12", 2);
    } else if (strlen(date) > 3 && date[3] == '4') {
        year = 2013;
        strncpy(result + 4, "13", 2);
    } else if (strlen(date) > 3 && date[3] == '5') {
        year = 2014;
        strncpy(result + 4, "14", 2);
    } else if (strlen(date) > 3 && date[3] == '6') {
        year = 2015;
        strncpy(result + 4, "15", 2);
    } else if (strlen(date) > 3 && date[3] == '7') {
        year = 2016;
        strncpy(result + 4, "16", 2);
    } else if (strlen(date) > 3 && date[3] == '8') {
        year = 2017;
        strncpy(result + 4, "17", 2);
    } else if (strlen(date) > 3 && date[3] == '9') {
        year = 2018;
        strncpy(result + 4, "18", 2);
    } else if (strlen(date) > 3 && date[3] == '0') {
        year = 0;
        strncpy(result + 4, "00", 2);
    }

    // Convert result
    strncpy(result + 2, "-", 1);
    strncpy(result + 4, "-", 1);
    strncpy(result + 6, "-", 1);
}

int main() {
    char date[50], result[50];

    // Get input date
    printf("Enter a date in Natural Language format: ");
    scanf("%s", date);

    // Convert date to machine-readable format
    convertDate(date, result);

    // Print result
    printf("Machine-readable date: %s\n", result);

    return 0;
}