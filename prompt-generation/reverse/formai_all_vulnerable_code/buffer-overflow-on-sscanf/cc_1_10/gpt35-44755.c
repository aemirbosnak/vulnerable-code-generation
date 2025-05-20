//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char date[11];
    char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("Enter the date in mm/dd/yyyy format: ");
    fgets(date, sizeof(date), stdin);

    // Extracting day, month and year from the input string
    int day, year;
    char mon[10];
    sscanf(date, "%d/%[^/]/%d", &day, mon, &year);

    // Converting month to numeric value
    int i, n = sizeof(month)/sizeof(month[0]);
    for(i=0; i<n; i++){
        if(strcmp(month[i],mon)==0){
            break;
        }
    }
    i++;

    printf("\nInquisitive style questions to convert dates! (Please don't feel bored while answering!)\n");

    printf("What was the day of the week on %s %d, %d? (Enter 1-7, where 1=Sunday and 7=Saturday): ", mon, day, year);
    int n1;
    scanf("%d", &n1);

    // Validating day of the week
    if(n1<1 || n1>7){
        while(n1<1 || n1>7){
            printf("Invalid input! Please enter a number between 1-7: ");
            scanf("%d", &n1);
        }
    }

    printf("What was happening on %s %d, %d? (For example: day of my birth, my wedding day, etc.): ", mon, day, year);
    char event[50];
    fgets(event, sizeof(event), stdin);

    printf("How many days are left until %s %d, %d? (Enter a number): ", mon, day, year+1);
    int n2;
    scanf("%d", &n2);

    printf("\n==============================\n");

    printf("The date you entered is: %d/%d/%d\n", i, day, year);
    printf("The day of the week was: %d\n", n1);
    printf("The event on that day was: %s", event);
    printf("The number of days until next year's date is: %d\n", n2);

    return 0;

}