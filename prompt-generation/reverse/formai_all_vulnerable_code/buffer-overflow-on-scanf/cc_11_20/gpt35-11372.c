//FormAI DATASET v1.0 Category: Hotel Management System ; Style: energetic
#include<stdio.h>
#include<string.h>

void main()
{
    struct hotel
    {
        char roomNo[10];
        char status[15];
        char name[20];
        char address[50];
        char phone[15];
        char email[30];
    }hotel_registration[100];
    int choice,i,j,avail=0,unavail=0;
    char ch='y',room[10];
    do
    {
        printf("\n\n\n*************************************************\n");
        printf(" \n****Welcome to Hotel Management System****\n");
        printf("\n*************************************************\n");
        printf("\n Enter 1 - To register:");
        printf("\n Enter 2 - To display all rooms:");
        printf("\n Enter 3 - To search:");
        printf("\n Enter 4 - To exit:");
        printf("\n Your Choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :

                printf("\n Enter room no :");
                scanf("%s",&hotel_registration[avail].roomNo);
                printf("\n Enter name :");
                scanf("%s",&hotel_registration[avail].name);
                printf("\n Enter address :");
                scanf("%s",&hotel_registration[avail].address);
                printf("\n Enter phone no :");
                scanf("%s",&hotel_registration[avail].phone);
                printf("\n Enter email address :");
                scanf("%s",&hotel_registration[avail].email);
                strcpy(hotel_registration[avail].status,"Unoccupied");
                printf("\n Your room is registered.\n");
                avail++;
                break;

            case 2:
                printf("\nRoom No\tOccupancy\tName\n");
                printf("----------------------------------------\n");
                for(i=0;i<avail;i++)
                    printf("%s\t%s\t%s\n",hotel_registration[i].roomNo,hotel_registration[i].status,hotel_registration[i].name);
                printf("\nTotal no of rooms booked :%d\n",avail);
                printf("Total no of vacant rooms  : %d\n",(100-avail));
                break;

            case 3:
                printf("\nEnter the room no you want to search :");
                scanf("%s",room);
                for(i=0;i<avail;i++)
                {
                    if(strcmp(hotel_registration[i].roomNo,room)==0)
                    {
                        printf("\nRoom no\tName\tAddress\t\t\tPhone No\tEmail\n");
                        printf("------------------------------------------------------------------------------\n");
                        printf("%s\t%s\t%s\t%s\t%s\n",hotel_registration[i].roomNo,hotel_registration[i].name,hotel_registration[i].address,hotel_registration[i].phone,hotel_registration[i].email);
                        break;
                    }
                }
                if(i==avail)
                    printf("\n\nThe room no. does not exist.\n\n");
                break;

            case 4:
                printf("\n\n<<Thank you for using the program>>\n\n");
                exit(0);

            default:
                printf("\nEnter a valid choice.\n");
                break;
        }
        printf("\n Do you want to continue? (y/n)");
        scanf("%s",&ch);
    }while(ch=='y' || ch=='Y');
}