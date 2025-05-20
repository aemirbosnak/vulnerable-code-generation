//FormAI DATASET v1.0 Category: Hotel Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest //Defining Guest Details
{
    char name[50];
    int room_no;
    int check_in;
    int check_out;
    float room_cost;
}guests[50]; //defining number of guests in the hotel

int main()
{
    int choice=0, count=0, i;
    char check[10];
    do //creating an infinite loop until break statement is executed to exit the program
    {
        printf("\n\n\t\tC HOTEL MANAGEMENT SYSTEM\n");
        printf("\n1. Check In");
        printf("\n2. Check Out");
        printf("\n3. Display Records");
        printf("\n4. Exit");
        printf("\n\nEnter your choice: ");

        scanf("%d" , &choice);

        switch(choice)
        {
            case 1: //Adding Guest details
                printf("\n\nEnter name: ");
                scanf("%s" , &guests[count].name);
                printf("\nEnter Room No.: ");
                scanf("%d" , &guests[count].room_no);
                printf("\nEnter Check-In date (DDMMYY): ");
                scanf("%d" , &guests[count].check_in);
                printf("\nEnter Check-Out date (DDMMYY): ");
                scanf("%d" , &guests[count].check_out);
                printf("\nEnter Room Cost (per day): ");
                scanf("%f" , &guests[count].room_cost);
                count++;
                break;
            case 2: //Deleting Guest details by entering room number
                printf("\n\nEnter Room No. to check out: ");
                int delete_room;
                scanf("%d", &delete_room);
                for(i=0; i<count; i++)
                {
                    if(delete_room == guests[i].room_no)
                    {
                        printf("\nGuest Details:");
                        printf("\n\nName: %s", guests[i].name);
                        printf("\nRoom No: %d", guests[i].room_no);
                        printf("\nCheck-In date (DDMMYY): %d", guests[i].check_in);
                        printf("\nCheck-Out date (DDMMYY): %d", guests[i].check_out);
                        printf("\nRoom cost (per day): %f", guests[i].room_cost);
                        printf("\nTotal cost: $%f", guests[i].room_cost*(guests[i].check_out-guests[i].check_in));
                        for(int j=i; j<count-1; j++)
                        {
                            guests[j] = guests[j+1];
                        }
                        count--;
                        break;

                    }
                    if(i==count-1)
                    {
                        printf("\n\nNo booking found!\n");
                        break;
                    }
                }
                break;
            case 3: //Displaying all guest records stored
                printf("\n\nTotal records: %d", count);
                for(i=0; i<count; i++)
                {
                    printf("\n\nGuest %d", i+1);
                    printf("\nName: %s", guests[i].name);
                    printf("\nRoom No: %d", guests[i].room_no);
                    printf("\nCheck-In date (DDMMYY): %d", guests[i].check_in);
                    printf("\nCheck-Out date (DDMMYY): %d", guests[i].check_out);
                    printf("\nRoom cost (per day): %f", guests[i].room_cost);  
                }
                break;
            case 4: //Exiting the program
                printf("\n\nExiting program!\n");
                break;
            default:
                printf("\n\nPlease enter a valid choice!(1/2/3/4)\n");
                break;
        }
    }while(choice!=4); //breaking the loop on selecting exit option
    return 0;
}