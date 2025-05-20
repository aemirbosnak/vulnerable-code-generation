//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

struct hotel
{
    int room[MAX];
    int price[MAX];
    int booking_status[MAX];
};

void main()
{
    int choice,i,j,k;
    struct hotel h;

    printf("\n\t\t\tHotel Management System\n");
    printf("\n1.Book a room\n2.Cancel a booking\n3.Check availability\n4.Exit");

    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter room number: ");
                scanf("%d",&i);

                for(j=0;j<MAX;j++)
                {
                    if(h.room[j]==i && h.booking_status[j]==0)
                    {
                        h.booking_status[j]=1;
                        printf("\nBooking successful for room %d",i);
                    }
                    else
                    {
                        printf("\nRoom %d is not available",i);
                    }
                }
                break;

            case 2:
                printf("\nEnter room number: ");
                scanf("%d",&i);

                for(j=0;j<MAX;j++)
                {
                    if(h.room[j]==i && h.booking_status[j]==1)
                    {
                        h.booking_status[j]=0;
                        printf("\nBooking cancelled for room %d",i);
                    }
                    else
                    {
                        printf("\nNo booking found for room %d",i);
                    }
                }
                break;

            case 3:
                printf("\nRoom\tStatus\n");
                for(j=0;j<MAX;j++)
                {
                    if(h.booking_status[j]==0)
                    {
                        printf("\n%d\tAvailable",h.room[j]);
                    }
                    else
                    {
                        printf("\n%d\tBooked",h.room[j]);
                    }
                }
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    }
}