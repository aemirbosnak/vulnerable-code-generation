//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayIntro() {
    printf("In fair Verona, where we lay our scene,\n");
    printf("Two star-crossed lovers, plight unseen.\n");
    printf("Enter the date, with format raw,\n");
    printf("We shall convert, with hearts in awe.\n\n");
}

void displayChoices() {
    printf("Choose thy format:\n");
    printf("1. YYYY-MM-DD (Year-Month-Day)\n");
    printf("2. DD-MM-YYYY (Day-Month-Year)\n");
    printf("3. MM-DD-YYYY (Month-Day-Year)\n");
    printf("4. Exit the stage\n");
}

void convertDate(char* dateInput, int choice) {
    char year[5], month[3], day[3];
    char outputDate[11];  // Buffer for the output date

    switch (choice) {
        case 1: 
            // YYYY-MM-DD to DD-MM-YYYY
            strncpy(year, dateInput, 4);
            year[4] = '\0';
            strncpy(month, dateInput + 5, 2);
            month[2] = '\0';
            strncpy(day, dateInput + 8, 2);
            day[2] = '\0';
            sprintf(outputDate, "%s-%s-%s", day, month, year);
            printf("Lo! The transformed date: %s\n", outputDate);
            break;

        case 2:
            // DD-MM-YYYY to YYYY-MM-DD
            strncpy(day, dateInput, 2);
            day[2] = '\0';
            strncpy(month, dateInput + 3, 2);
            month[2] = '\0';
            strncpy(year, dateInput + 6, 4);
            year[4] = '\0';
            sprintf(outputDate, "%s-%s-%s", year, month, day);
            printf("Lo! The transformed date: %s\n", outputDate);
            break;

        case 3:
            // MM-DD-YYYY to YYYY-MM-DD
            strncpy(month, dateInput, 2);
            month[2] = '\0';
            strncpy(day, dateInput + 3, 2);
            day[2] = '\0';
            strncpy(year, dateInput + 6, 4);
            year[4] = '\0';
            sprintf(outputDate, "%s-%s-%s", year, month, day);
            printf("Lo! The transformed date: %s\n", outputDate);
            break;

        default:
            printf("Alas! We cannot proceed further.\n");
            break;
    }
}

int main() {
    displayIntro();
    
    char dateInput[11]; // For user input of date strings
    int choice;

    while (1) {
        displayChoices();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Parting is such sweet sorrow.\n");
            break;
        }

        printf("Enter the date you wish to convert (format as informed): ");
        scanf("%s", dateInput);

        // Validating date length
        if ((choice == 1 && strlen(dateInput) == 10) || 
            (choice == 2 && strlen(dateInput) == 10) || 
            (choice == 3 && strlen(dateInput) == 10)) {
            convertDate(dateInput, choice);
        } else {
            printf("Prithee, enter a date in the correct format, forsooth!\n");
        }
        printf("\n");
    }

    return 0;
}