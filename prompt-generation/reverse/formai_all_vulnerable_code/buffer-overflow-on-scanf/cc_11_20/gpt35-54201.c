//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day, month, year;
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);
    if(day < 1 || day > 31 || month < 1 || month > 12 || year < 1000 || year > 9999)
    {
        printf("Invalid date entered. Please try again!\n");
        return 1;
    }
    else
    {
        char * months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        printf("The date you entered is: %s %d, %d.\n", months[month - 1], day, year);
        printf("In romantic style: ");
        switch(month)
        {
            case 1:
                printf("January is the month of new beginnings, and on this day %d years ago, a beautiful soul came into this world, destined to find their one true love.", year);
                break;
            case 2:
                printf("February is the month of love, and on this day %d years ago, an angel was born, who would one day find their soulmate and embark on a journey of love and happiness.", year);
                break;
            case 3:
                printf("March is the month of hope and renewal, and on this day %d years ago, a precious heart was created, ready to weather the storms of life and come out stronger on the other side.", year);
                break;
            case 4:
                printf("April is the month of rebirth and growth, and on this day %d years ago, a shining star was born, with a bright future and a heart full of love to share.", year);
                break;
            case 5:
                printf("May is the month of blooming flowers and warm sunshine, and on this day %d years ago, a kindred spirit was born, destined to find their other half and create a love that would last a lifetime.", year);
                break;
            case 6:
                printf("June is the month of summer love and adventure, and on this day %d years ago, a beautiful person came into this world, with a heart full of dreams and a spirit of adventure.", year);
                break;
            case 7:
                printf("July is the month of hot nights and sweet romance, and on this day %d years ago, a wonderful human being was born, with a heart full of fire and a passion for life.", year);
                break;
            case 8:
                printf("August is the month of lazy days and warm nights, and on this day %d years ago, a charming soul was created, ready to take on the world and find their one true love.", year);
                break;
            case 9:
                printf("September is the month of fresh starts and new beginnings, and on this day %d years ago, a precious gem came into this world, destined to shine bright and touch the lives of many.", year);
                break;
            case 10:
                printf("October is the month of falling leaves and magic, and on this day %d years ago, a beautiful mind was born, with a heart full of wonder and a spirit of adventure.", year);
                break;
            case 11:
                printf("November is the month of cozy nights and warm hugs, and on this day %d years ago, a lovely person was created, with a heart full of love and a soul full of kindness.", year);
                break;
            case 12:
                printf("December is the month of holidays and joyful celebrations, and on this day %d years ago, a miracle happened, and a beautiful soul was born, destined to find true love and happiness.", year);
                break;
            default:
                printf("Something went wrong. Please try again later!\n");
                return 1;
        }
    }
    return 0;
}