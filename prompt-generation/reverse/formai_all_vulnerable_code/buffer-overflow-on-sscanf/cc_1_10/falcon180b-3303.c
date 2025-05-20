//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

//Function to check if a string is a valid date
int isDate(char* str) {
    int year, month, day;
    char* token = strtok(str, " ");
    if(token == NULL)
        return 0;
    if(sscanf(token, "%d", &year)!= 1)
        return 0;
    token = strtok(NULL, " ");
    if(token == NULL)
        return 0;
    if(sscanf(token, "%d", &month)!= 1)
        return 0;
    if(month < 1 || month > 12)
        return 0;
    token = strtok(NULL, " ");
    if(token == NULL)
        return 0;
    if(sscanf(token, "%d", &day)!= 1)
        return 0;
    if(day < 1 || day > 31)
        return 0;
    return 1;
}

//Function to convert a date string to struct tm
void convertDate(char* str, struct tm* date) {
    int year, month, day;
    char* token = strtok(str, " ");
    if(token == NULL)
        return;
    if(sscanf(token, "%d", &year)!= 1)
        return;
    token = strtok(NULL, " ");
    if(token == NULL)
        return;
    if(sscanf(token, "%d", &month)!= 1)
        return;
    if(month < 1 || month > 12)
        return;
    token = strtok(NULL, " ");
    if(token == NULL)
        return;
    if(sscanf(token, "%d", &day)!= 1)
        return;
    if(day < 1 || day > 31)
        return;
    date->tm_year = year - 1900;
    date->tm_mon = month - 1;
    date->tm_mday = day;
}

//Function to print a date in a given format
void printDate(struct tm* date, char* format) {
    char buffer[100];
    strftime(buffer, sizeof(buffer), format, date);
    printf("%s", buffer);
}

int main() {
    char input[100];
    struct tm date;
    printf("Enter a date in the format 'dd/mm/yyyy': ");
    fgets(input, sizeof(input), stdin);
    convertDate(input, &date);
    if(isDate(input)) {
        printf("Valid date entered.\n");
        printf("The date is: ");
        printDate(&date, "%d/%02d/%02d");
    } else {
        printf("Invalid date entered.\n");
    }
    return 0;
}