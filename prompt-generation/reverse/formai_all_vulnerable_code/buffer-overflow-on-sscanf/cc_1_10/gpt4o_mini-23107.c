//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold Dates in the Medieval Realm
struct Date {
    int day;
    int month;
    int year;
};

// Enchanted array with the names of the months
const char* months[] = {
    "Januarius", "Februarius", "Martius", "Aprilis", 
    "Maius", "Junius", "Julius", "Augustus", 
    "September", "October", "November", "December"
};

// Declare the functionality of the enchanted date converter
struct Date parse_date(const char* natural_language_date);
void display_date(const struct Date date);
int get_month_number(const char* month_name);
void grace_the_user();

int main() {
    grace_the_user();
    char natural_language_date[100];

    printf("Pray thee, enter the date in a natural tongue (e.g. 'fifteenth of April in the year of our Lord two thousand three'):\n");
    fgets(natural_language_date, sizeof(natural_language_date), stdin);
    
    struct Date converted_date = parse_date(natural_language_date);
    display_date(converted_date);
    
    return 0;
}

// Display a warm message to greet the user
void grace_the_user() {
    printf("Welcome, noble seeker of truth and time!\n");
    printf("In this realm, we shall convert your natural words into the language of the dates.\n");
    printf("Let us embark on this mystical journey together!\n\n");
}

// Function to parse the natural language date into structured date format
struct Date parse_date(const char* natural_language_date) {
    struct Date date = {0, 0, 0};
    int day, year;
    char month_name[20];

    // A kingdom of simple words to integer mappings
    sscanf(natural_language_date, "%d of %s in the year of our Lord %d", &day, month_name, &year);
    
    date.day = day;
    date.year = year;
    date.month = get_month_number(month_name);

    return date;
}

// Convert month name to corresponding number
int get_month_number(const char* month_name) {
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(month_name, months[i]) == 0)
            return i + 1;
    }
    return 0; // Return 0 if not found
}

// Function to display the date in a regal format
void display_date(const struct Date date) {
    if (date.month == 0) {
        printf("Alas, the month you entered seems to bear no fruit from our enchanted garden!\n");
    } else {
        printf("\nHark! The date you seek is as follows:\n");
        printf("%s the %dth, in the year of our Lord %d\n", months[date.month - 1], date.day, date.year);
        printf("May the stars shine bright upon your path!\n");
    }
}