//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: invasive
#include <stdio.h>

int main() {
    char input_date[10];
    int month, day, year;
    printf("Welcome to the Date Converter. Please enter a date in the format MM/DD/YYYY: \n");
    scanf("%s", input_date);
    sscanf(input_date, "%d/%d/%d", &month, &day, &year);
    if (month < 1 || month > 12) {
        printf("Invalid month. Please enter a valid date.\n");
        return 0;
    }
    if (day < 1 || day > 31) {
        printf("Invalid day. Please enter a valid date.\n");
        return 0;
    }
    if (year < 0 || year > 9999) {
        printf("Invalid year. Please enter a valid date.\n");
        return 0;
    }
    printf("The date you entered is: %d/%d/%d.\n", month, day, year);
    printf("Would you like to convert this date to another format? (Y/N)\n");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        printf("Great! Please choose a format:\n");
        printf("1. MMMM DD, YYYY.\n");
        printf("2. DD MMMM YYYY.\n");
        printf("3. YYYY/MM/DD.\n");
        int format_choice;
        scanf("%d", &format_choice);
        switch (format_choice) {
            case 1:
                switch (month) {
                    case 1: printf("January"); break;
                    case 2: printf("February"); break;
                    case 3: printf("March"); break;
                    case 4: printf("April"); break;
                    case 5: printf("May"); break;
                    case 6: printf("June"); break;
                    case 7: printf("July"); break;
                    case 8: printf("August"); break;
                    case 9: printf("September"); break;
                    case 10: printf("October"); break;
                    case 11: printf("November"); break;
                    case 12: printf("December"); break;
                }
                printf(" %d, %d.\n", day, year);
                break;
            case 2:
                printf("%d ", day);
                switch (month) {
                    case 1: printf("January"); break;
                    case 2: printf("February"); break;
                    case 3: printf("March"); break;
                    case 4: printf("April"); break;
                    case 5: printf("May"); break;
                    case 6: printf("June"); break;
                    case 7: printf("July"); break;
                    case 8: printf("August"); break;
                    case 9: printf("September"); break;
                    case 10: printf("October"); break;
                    case 11: printf("November"); break;
                    case 12: printf("December"); break;
                }
                printf(" %d.\n", year);
                break;
            case 3:
                printf("%d/%d/%d.\n", year, month, day);
                break;
            default:
                printf("Invalid choice.\n");
                return 0;
        }
        printf("Thanks for using the Date Converter! Goodbye!\n");
        return 0;
    }
    printf("Thanks for using the Date Converter! Goodbye!\n");
    return 0;
}