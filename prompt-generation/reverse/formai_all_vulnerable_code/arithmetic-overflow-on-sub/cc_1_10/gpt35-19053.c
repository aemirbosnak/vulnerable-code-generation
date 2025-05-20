//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Sherlock Holmes
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

//Function to get date as string in the format "YYYY-MM-DD"
char* getDateAsString(time_t currentTime) {
    struct tm* localTime = localtime(&currentTime);
    char* dateString = (char*)malloc(sizeof(char) * 11);
    sprintf(dateString, "%d-%02d-%02d", localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday);
    return dateString;
}

int main(){
    time_t currentTime = time(NULL);
    char* currentDate = getDateAsString(currentTime);
    printf("Welcome to the C Time Travel Simulator, Sherlock Holmes style!\n\n");

    printf("Today is %s.\n", currentDate);
    printf("Enter a date in the past (in the format YYYY-MM-DD): ");
    char* inputDate = (char*)malloc(sizeof(char) * 11);
    scanf("%s", inputDate);

    time_t inputTime, diff;
    struct tm inputTm;
    memset(&inputTm, 0, sizeof(struct tm));
    sscanf(inputDate, "%d-%d-%d", &inputTm.tm_year, &inputTm.tm_mon, &inputTm.tm_mday);
    inputTm.tm_year -= 1900;
    inputTm.tm_mon -= 1;
    inputTm.tm_isdst = -1;
    inputTime = mktime(&inputTm);
    diff = difftime(currentTime, inputTime);

    if (diff < 0) {
        printf("\nTime-travel to the future is not yet possible! Please enter a date in the past.\n\n");
        return 0;
    }

    printf("\nYou have selected a date in the past (%s).\n", getDateAsString(inputTime));

    printf("\nEnter a time of day (in the format HH:MM:SS): ");
    char* inputTimeStr = (char*)malloc(sizeof(char) * 9);
    scanf("%s", inputTimeStr);
    int inputHH, inputMM, inputSS;
    sscanf(inputTimeStr, "%d:%d:%d", &inputHH, &inputMM, &inputSS);

    int secondsToSubtract = inputHH * 3600 + inputMM * 60 + inputSS;
    inputTime -= secondsToSubtract;
    diff = difftime(currentTime, inputTime);

    printf("\nYou have selected the time %s (%d seconds ago).\n", inputTimeStr, (int)diff);

    printf("\nWould you like to time-travel to this date and time?\n");
    printf("Enter 'y' for yes or 'n' for no: ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y') {
        printf("\nWelcome to %s, the time is now %s!\n", getDateAsString(inputTime), inputTimeStr);
    } else {
        printf("\nGoodbye!\n");
    }

    free(inputDate);
    free(inputTimeStr);
    free(currentDate);
    return 0;
}