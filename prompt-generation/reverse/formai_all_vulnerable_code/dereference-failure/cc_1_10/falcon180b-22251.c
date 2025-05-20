//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void time_travel(int year,int month,int day,int hour,int min,int sec)
{
    time_t t;
    struct tm *t1;
    t1=localtime(&t);
    t1->tm_year=year;
    t1->tm_mon=month;
    t1->tm_mday=day;
    t1->tm_hour=hour;
    t1->tm_min=min;
    t1->tm_sec=sec;
    t=mktime(t1);
    printf("\nThe current time is %s",ctime(&t));
    system("pause");
}

void time_travel_recursive(int year,int month,int day,int hour,int min,int sec,int depth)
{
    if(depth==0)
    {
        time_travel(year,month,day,hour,min,sec);
        return;
    }
    else
    {
        time_travel_recursive(year,month,day,hour,min,sec,depth-1);
    }
}

int main()
{
    int year,month,day,hour,min,sec,depth;
    printf("\nEnter the year (yyyy): ");
    scanf("%d",&year);
    printf("\nEnter the month (mm): ");
    scanf("%d",&month);
    printf("\nEnter the day (dd): ");
    scanf("%d",&day);
    printf("\nEnter the hour (hh): ");
    scanf("%d",&hour);
    printf("\nEnter the minute (mm): ");
    scanf("%d",&min);
    printf("\nEnter the second (ss): ");
    scanf("%d",&sec);
    printf("\nEnter the depth of recursion: ");
    scanf("%d",&depth);
    time_travel_recursive(year,month,day,hour,min,sec,depth);
    return 0;
}