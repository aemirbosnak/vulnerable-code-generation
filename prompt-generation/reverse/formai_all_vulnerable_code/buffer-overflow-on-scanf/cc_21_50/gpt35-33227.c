//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: configurable
#include <stdio.h>

int main() {
    int day, month, year;

    printf("Enter date in the format dd/mm/yyyy: ");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("\nChoose the output format: \n");
    printf("1. MM/DD/YYYY\n");
    printf("2. Month DD, YYYY\n");
    printf("3. DD Month YYYY\n");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nOutput: %02d/%02d/%04d\n", month, day, year);
            break;
        case 2:
            printf("\nOutput: ");
            switch(month) {
                case 1:
                    printf("January");
                    break;
                case 2:
                    printf("February");
                    break;
                case 3:
                    printf("March");
                    break;
                case 4:
                    printf("April");
                    break;
                case 5:
                    printf("May");
                    break;
                case 6:
                    printf("June");
                    break;
                case 7:
                    printf("July");
                    break;
                case 8:
                    printf("August");
                    break;
                case 9:
                    printf("September");
                    break;
                case 10:
                    printf("October");
                    break;
                case 11:
                    printf("November");
                    break;
                case 12:
                    printf("December");
                    break;
                default:
                    printf("Invalid month");
                    break;
            }
            printf(" %02d, %04d\n", day, year);
            break;
        case 3:
            printf("\nOutput: %02d ", day);
            switch(month) {
                case 1:
                    printf("January");
                    break;
                case 2:
                    printf("February");
                    break;
                case 3:
                    printf("March");
                    break;
                case 4:
                    printf("April");
                    break;
                case 5:
                    printf("May");
                    break;
                case 6:
                    printf("June");
                    break;
                case 7:
                    printf("July");
                    break;
                case 8:
                    printf("August");
                    break;
                case 9:
                    printf("September");
                    break;
                case 10:
                    printf("October");
                    break;
                case 11:
                    printf("November");
                    break;
                case 12:
                    printf("December");
                    break;
                default:
                    printf("Invalid month");
                    break;
            }
            printf(" %04d\n", year);
            break;
        default:
            printf("\nInvalid choice\n");
            break;
    }

    return 0;
}