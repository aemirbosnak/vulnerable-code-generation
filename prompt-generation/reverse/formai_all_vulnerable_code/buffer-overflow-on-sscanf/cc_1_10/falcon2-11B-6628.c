//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to convert natural language date to C date format
void convertDate(char* naturalLanguageDate) {
    char* cDate = malloc(sizeof(char) * 10);
    int month = 0;
    int day = 0;
    int year = 0;

    // Split the natural language date into month, day, and year
    sscanf(naturalLanguageDate, "%d-%d-%d", &month, &day, &year);

    // Convert month and day to 01-12 format
    if (month < 10) {
        sprintf(cDate, "%d0%d-%d", year, month, day);
    } else {
        sprintf(cDate, "%d%d-%d", year, month, day);
    }

    // Print the converted date
    printf("%s\n", cDate);

    // Free the dynamically allocated memory
    free(cDate);
}

// Function to get random natural language date
char* getRandomNaturalLanguageDate() {
    char* randomDate = malloc(sizeof(char) * 50);

    // Generate a random month, day, and year
    srand(time(NULL));
    int month = rand() % 12 + 1;
    int day = rand() % 31 + 1;
    int year = 2022 + rand() % 20;

    // Generate a random natural language date string
    sprintf(randomDate, "%d-%d-%d", year, month, day);

    return randomDate;
}

int main() {
    char* naturalLanguageDate = getRandomNaturalLanguageDate();
    convertDate(naturalLanguageDate);
    free(naturalLanguageDate);

    return 0;
}