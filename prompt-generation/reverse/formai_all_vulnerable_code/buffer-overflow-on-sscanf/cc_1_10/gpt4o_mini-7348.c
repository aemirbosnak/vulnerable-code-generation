//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

void displayMenu() {
    printf("\n");
    printf("     /\\    /\\\n");
    printf("    /  \\__/  \\\n");
    printf("   /  DATE    \\\n");
    printf("  /  CONVERTER \\\n");
    printf(" /              \\\n");
    printf("/________________\\\n");
    printf("\n");
    printf("1. Convert MM/DD/YYYY to DD Month YYYY\n");
    printf("2. Convert DD Month YYYY to MM/DD/YYYY\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

struct Date convertToDate(char *input) {
    struct Date date;
    sscanf(input, "%d/%d/%d", &date.month, &date.day, &date.year);
    return date;
}

void convertToFormattedString(struct Date date, char *output) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    sprintf(output, "%02d %s %04d", date.day, months[date.month - 1], date.year);
}

void convertFromFormattedString(char *input, struct Date *date) {
    char month[20];
    sscanf(input, "%d %s %d", &date->day, month, &date->year);
    
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    for (int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            date->month = i + 1;
            break;
        }
    }
}

void convertAndDisplayMenu(int option) {
    if (option == 1) {
        char input[11];
        printf("Enter date (MM/DD/YYYY): ");
        scanf("%10s", input);
        struct Date date = convertToDate(input);
        char output[50];
        convertToFormattedString(date, output);
        printf("Converted Date: %s\n", output);
    } else if (option == 2) {
        char input[50];
        printf("Enter date (DD Month YYYY): ");
        scanf(" %[^\n]", input);
        struct Date date;
        convertFromFormattedString(input, &date);
        printf("Converted Date: %02d/%02d/%04d\n", date.month, date.day, date.year);
    } else {
        printf("Exiting the program. Thank you!\n");
    }
}

int main() {
    int option;
    
    do {
        displayMenu();
        scanf("%d", &option);
        if (option == 1 || option == 2) {
            convertAndDisplayMenu(option);
        } else if (option < 1 || option > 3) {
            printf("Invalid option. Please try again.\n");
        }
    } while (option != 3);
    
    return 0;
}