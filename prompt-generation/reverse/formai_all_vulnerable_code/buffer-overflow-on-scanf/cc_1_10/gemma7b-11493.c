//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define the Digital Diary structure
typedef struct DigitalDiary {
    char name[20];
    int year;
    int month;
    int day;
    char entry[200];
} DigitalDiary;

// Create a function to add an entry to the digital diary
void addEntry(DigitalDiary *diary) {
    printf("Enter your name: ");
    scanf("%s", diary->name);

    printf("Enter the year: ");
    scanf("%d", &diary->year);

    printf("Enter the month: ");
    scanf("%d", &diary->month);

    printf("Enter the day: ");
    scanf("%d", &diary->day);

    printf("Enter your entry: ");
    scanf("%s", diary->entry);
}

// Create a function to display an entry from the digital diary
void displayEntry(DigitalDiary *diary) {
    printf("Name: %s\n", diary->name);
    printf("Year: %d\n", diary->year);
    printf("Month: %d\n", diary->month);
    printf("Day: %d\n", diary->day);
    printf("Entry: %s\n", diary->entry);
}

int main() {
    // Create a digital diary
    DigitalDiary diary;

    // Add an entry to the digital diary
    addEntry(&diary);

    // Display an entry from the digital diary
    displayEntry(&diary);

    return 0;
}