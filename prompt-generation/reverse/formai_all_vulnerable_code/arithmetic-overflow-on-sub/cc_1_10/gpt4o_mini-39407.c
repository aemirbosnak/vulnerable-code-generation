//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// -------- Surprise Helpers --------
void parseDate(const char* dateString, struct tm* timeStruct) {
    if (strstr(dateString, "today")) {
        time_t now = time(NULL);
        *timeStruct = *localtime(&now);
    } else if (strstr(dateString, "tomorrow")) {
        time_t now = time(NULL);
        time_t tomorrow = now + 86400; // 24 hours in seconds
        *timeStruct = *localtime(&tomorrow);
    } else if (strstr(dateString, "yesterday")) {
        time_t now = time(NULL);
        time_t yesterday = now - 86400; // 24 hours in seconds
        *timeStruct = *localtime(&yesterday);
    } else {
        printf("🎉 Surprise! Let's assume this is a specific date! 🎉\n");
        sscanf(dateString, "%d %s %d", &timeStruct->tm_mday, dateString, &timeStruct->tm_year);
        if (strcmp(dateString, "January") == 0) timeStruct->tm_mon = 0;
        else if (strcmp(dateString, "February") == 0) timeStruct->tm_mon = 1;
        else if (strcmp(dateString, "March") == 0) timeStruct->tm_mon = 2;
        else if (strcmp(dateString, "April") == 0) timeStruct->tm_mon = 3;
        else if (strcmp(dateString, "May") == 0) timeStruct->tm_mon = 4;
        else if (strcmp(dateString, "June") == 0) timeStruct->tm_mon = 5;
        else if (strcmp(dateString, "July") == 0) timeStruct->tm_mon = 6;
        else if (strcmp(dateString, "August") == 0) timeStruct->tm_mon = 7;
        else if (strcmp(dateString, "September") == 0) timeStruct->tm_mon = 8;
        else if (strcmp(dateString, "October") == 0) timeStruct->tm_mon = 9;
        else if (strcmp(dateString, "November") == 0) timeStruct->tm_mon = 10;
        else if (strcmp(dateString, "December") == 0) timeStruct->tm_mon = 11;
        timeStruct->tm_year -= 1900; // Adjust year
    }
}

// -------- Generate Magical Output --------
void displayDate(struct tm timeStruct) {
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", &timeStruct);
    printf("🗓️ Voila! The formatted date is: %s\n", buffer);
}

// -------- Let's Create a Magical Experience --------
void surpriseDateConverter() {
    char dateInput[100];
    
    printf("🌟 Welcome to the Magical Date Converter! 🌟\n");
    printf("Please type a date in natural language (e.g., 'today', 'tomorrow', 'yesterday', or '15 March 2023'): ");
    
    // Unexpected twist! Let's get the input!
    fgets(dateInput, sizeof(dateInput), stdin);
    dateInput[strcspn(dateInput, "\n")] = 0; // Remove trailing newline

    struct tm timeStruct = {0};

    // Parse the date and tell the user about our surprises!
    printf("🤔 You entered: \"%s\"\n", dateInput);
    parseDate(dateInput, &timeStruct);

    // Convert and display the date
    displayDate(timeStruct);
    
    printf("🎊 Thank you for using our Magical Date Converter! 🎊\n");
}

// -------- Main Function --------
int main() {
    surpriseDateConverter();
    return 0;
}