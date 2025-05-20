//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertDate(char *inputDate, int *year, int *month, int *day) {
    if (strlen(inputDate) != 10) // Check if inputDate is exactly of length 10
        exit(EXIT_FAILURE);

    if (isdigit(inputDate[0]) && // Check if first character is a digit
        isdigit(inputDate[1]) &&
        isdigit(inputDate[2]) &&
        isdigit(inputDate[3]) &&
        inputDate[4] == '-' &&
        isdigit(inputDate[5]) && // Check if sixth character is a digit
        isdigit(inputDate[6]) &&
        inputDate[7] == '-' &&
        isdigit(inputDate[8]) && // Check if ninth character is a digit
        isdigit(inputDate[9])) {

        int yearNum = ((inputDate[0] - '0') * 1000) + ((inputDate[1] - '0') * 100) + ((inputDate[2] - '0') * 10) + (inputDate[3] - '0');
        int monthNum = ((inputDate[5] - '0') * 10) + (inputDate[6] - '0');
        int dayNum = ((inputDate[8] - '0') * 10) + (inputDate[9] - '0');

        *year = yearNum;
        *month = monthNum;
        *day = dayNum;
    } else { // If inputDate is not in the correct format, recursively call the function again
        char newInputDate[11];

        printf("Invalid input format. Please enter a date in the following format (including dashes): yyyy-mm-dd: ");
        scanf("%s", newInputDate);

        convertDate(newInputDate, year, month, day);
    }
}

int main() {
    int year, month, day;
    char inputDate[11];

    printf("Enter a date in the following format (including dashes): yyyy-mm-dd: ");
    scanf("%s", inputDate);

    convertDate(inputDate, &year, &month, &day);

    printf("The year is: %d\n", year);
    printf("The month is: %d\n", month);
    printf("The day is: %d\n", day);

    return 0;
}