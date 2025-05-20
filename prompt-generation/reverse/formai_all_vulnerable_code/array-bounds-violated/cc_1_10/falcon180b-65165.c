//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the current date in the medieval style
void print_date(int day, int month, int year) {
    static char *months[] = {"Januarius", "Februarius", "Martius", "Aprilis", "Maius", "Junius", "Julius", "Augustus", "September", "October", "November", "December"};
    printf("Today is the %d day of %s, in the year of our Lord %d.\n", day, months[month - 1], year);
}

// Function to write a new entry to the diary file
void write_entry(FILE *diary, int day, int month, int year, char *message) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    tm->tm_mday = day;
    tm->tm_mon = month - 1;
    tm->tm_year = year - 1900;
    tm->tm_hour = 0;
    tm->tm_min = 0;
    tm->tm_sec = 0;
    fprintf(diary, "%04d-%02d-%02d %02d:%02d:%02d - %s\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, message);
}

// Function to read the diary file and print all entries
void read_diary(FILE *diary) {
    char message[1024];
    while (fgets(message, sizeof(message), diary)!= NULL) {
        printf("%s", message);
    }
}

int main() {
    FILE *diary;
    char filename[32];
    int day, month, year;
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    // Get the current date
    day = tm->tm_mday;
    month = tm->tm_mon + 1;
    year = tm->tm_year + 1900;

    // Open the diary file
    sprintf(filename, "diary_%d-%02d-%02d.txt", year, month, day);
    diary = fopen(filename, "a+");
    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        return 1;
    }

    // Print the current date
    print_date(day, month, year);

    // Ask the user if they want to write a new entry
    char choice;
    printf("Do you want to write a new entry? (y/n) ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        char message[1024];
        printf("Enter your message: ");
        fgets(message, sizeof(message), stdin);
        write_entry(diary, day, month, year, message);
        printf("Entry saved.\n");
    }

    // Ask the user if they want to read the diary
    printf("Do you want to read the diary? (y/n) ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        read_diary(diary);
    }

    // Close the diary file
    fclose(diary);

    return 0;
}