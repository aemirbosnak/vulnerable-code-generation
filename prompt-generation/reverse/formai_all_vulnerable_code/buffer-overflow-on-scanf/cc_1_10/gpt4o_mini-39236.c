//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 5
#define MAX_DATE_LENGTH 100
#define MAX_NAME_LENGTH 50

void convertDate(const char *inputDate, char *outputDate);
int isLeapYear(int year);
int getDaysInMonth(int month, int year);
void displayMenu();
void getPlayerName(char *name);

int main() {
    char playerNames[MAX_PLAYERS][MAX_NAME_LENGTH];
    char inputDates[MAX_PLAYERS][MAX_DATE_LENGTH];
    char outputDates[MAX_PLAYERS][MAX_DATE_LENGTH];
    int playerCount = 0;
    char continueGame;

    printf("Welcome to the Multiplayer Natural Language Date Converter!\n");

    // Get number of players
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    getchar(); // To consume newline after scanf

    // Get player names
    for (int i = 0; i < playerCount; i++) {
        getPlayerName(playerNames[i]);
    }

    do {
        for (int i = 0; i < playerCount; i++) {
            printf("%s, enter a date in natural language (e.g., 'first of July 2023'): ", playerNames[i]);
            fgets(inputDates[i], MAX_DATE_LENGTH, stdin);
            inputDates[i][strcspn(inputDates[i], "\n")] = 0; // Remove newline

            convertDate(inputDates[i], outputDates[i]);
            printf("%s, your date in YYYY-MM-DD format is: %s\n", playerNames[i], outputDates[i]);
        }

        printf("Would you like to continue converting dates? (y/n): ");
        scanf(" %c", &continueGame);
        getchar(); // To consume newline after scanf

    } while (continueGame == 'y' || continueGame == 'Y');

    printf("Thank you for playing!\n");
    return 0;
}

void convertDate(const char *inputDate, char *outputDate) {
    char dayStr[3];
    char monthStr[20];
    char yearStr[5];
    int day, month, year;

    // Basic parsing of natural language date
    sscanf(inputDate, "%s %*s %s %s", dayStr, monthStr, yearStr);
    day = atoi(dayStr);
    year = atoi(yearStr);
    
    // Convert month name to number
    if (strcmp(monthStr, "January") == 0) month = 1;
    else if (strcmp(monthStr, "February") == 0) month = 2;
    else if (strcmp(monthStr, "March") == 0) month = 3;
    else if (strcmp(monthStr, "April") == 0) month = 4;
    else if (strcmp(monthStr, "May") == 0) month = 5;
    else if (strcmp(monthStr, "June") == 0) month = 6;
    else if (strcmp(monthStr, "July") == 0) month = 7;
    else if (strcmp(monthStr, "August") == 0) month = 8;
    else if (strcmp(monthStr, "September") == 0) month = 9;
    else if (strcmp(monthStr, "October") == 0) month = 10;
    else if (strcmp(monthStr, "November") == 0) month = 11;
    else if (strcmp(monthStr, "December") == 0) month = 12;
    else {
        strcpy(outputDate, "Invalid month");
        return;
    }

    // Validation of the day based on month
    if (day < 1 || day > getDaysInMonth(month, year)) {
        strcpy(outputDate, "Invalid day");
        return;
    }

    // Format the output date
    sprintf(outputDate, "%04d-%02d-%02d", year, month, day);
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    int thirtyOneDays[] = {1, 3, 5, 7, 8, 10, 12};
    for (int i = 0; i < sizeof(thirtyOneDays)/sizeof(thirtyOneDays[0]); i++) {
        if (month == thirtyOneDays[i]) return 31;
    }
    return 30; // For April, June, September, November
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void displayMenu() {
    printf("Date Converter Menu:\n");
    printf("1. Enter Date\n");
    printf("2. Exit\n");
}

void getPlayerName(char *name) {
    printf("Enter player name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline
}