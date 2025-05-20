//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>

int main() 
{
    int month, day, year;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Enter a date in the format of 'Month Day Year': ");

    scanf("%d %d %d", &month, &day, &year);

    switch(month) 
    {
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

    printf(" %d", day);
    
    if (day == 1 || day == 21 || day == 31) 
    {
        printf("st");
    }
    else if (day == 2 || day == 22)
    {
        printf("nd");
    }
    else if (day == 3 || day == 23)
    {
        printf("rd");
    }
    else 
    {
        printf("th");
    }

    printf(", %d\n", year);
    printf("Thank you for using the Natural Language Date Converter!");

    return 0;
}