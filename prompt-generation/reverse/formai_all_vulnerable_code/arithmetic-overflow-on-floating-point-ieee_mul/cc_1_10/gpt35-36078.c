//FormAI DATASET v1.0 Category: Hotel Management System ; Style: active
#include<stdio.h>
#include<string.h>

struct guest
{
    int room_no;
    char name[30];
    char address[50];
    char phone_no[15];
    int days;
    float rate;
    int occupancy;
    float amount;
}g[100];

int n=0;

void addGuest()
{
    printf("\nEnter the details of the guest : ");
    printf("\nEnter the room number : ");
    scanf("%d",&g[n].room_no);
    printf("\nEnter the name of the guest : ");
    getchar();
    fgets(g[n].name,30,stdin);
    printf("\nEnter the address of the guest : ");
    fgets(g[n].address,50,stdin);
    printf("\nEnter the phone number of the guest : ");
    fgets(g[n].phone_no,15,stdin);
    printf("\nEnter the number of days of stay : ");
    scanf("%d",&g[n].days);
    printf("\nEnter the rate per day : ");
    scanf("%f",&g[n].rate);
    printf("\nEnter the occupancy (1 - Single, 2 - Double, 3 - Suite) : ");
    scanf("%d",&g[n].occupancy);
    switch(g[n].occupancy)
    {
        case 1: g[n].amount = g[n].days * g[n].rate * 1.0; break;
        case 2: g[n].amount = g[n].days * g[n].rate * 1.5; break;
        case 3: g[n].amount = g[n].days * g[n].rate * 2.0; break;
    }
    printf("\nGuest added successfully!\n");
    n++;
}

void displayGuest(int i)
{
    printf("\n================================================================");
    printf("\nRoom Number : %d",g[i].room_no);
    printf("\nName of the Guest : %s",g[i].name);
    printf("Address of the Guest : %s",g[i].address);
    printf("Phone Number of the Guest : %s",g[i].phone_no);
    printf("Number of Days of Stay : %d",g[i].days);
    printf("Rate per Day : %.2f",g[i].rate);
    printf("Occupancy : ");
    switch(g[i].occupancy)
    {
        case 1: printf("Single"); break;
        case 2: printf("Double"); break;
        case 3: printf("Suite"); break;
    }
    printf("\nAmount to be paid : %.2f\n",g[i].amount);
}

void searchGuest()
{
    int i,room;
    printf("\nEnter the room number of the guest : ");
    scanf("%d",&room);
    for(i=0;i<n;i++)
    {
        if(g[i].room_no==room)
        {
            printf("\nSearch Results : \n");
            displayGuest(i);
            break;
        }
    }
    if(i==n)
    {
        printf("\nGuest not found!\n");
    }
}

void displayAllGuests()
{
    int i;
    if(n==0)
    {
        printf("\nNo guests added to the hotel yet!\n");
    }
    else
    {
        printf("\nAll Guests in the Hotel : \n");
        for(i=0;i<n;i++)
        {
            displayGuest(i);
        }
    }
}

void deleteGuest()
{
    int i,j,room;
    printf("\nEnter the room number of the guest to be deleted : ");
    scanf("%d",&room);
    j=n;
    for(i=0;i<n;i++)
    {
        if(g[i].room_no==room)
        {
            j=i;
            for(i=j;i<n-1;i++)
            {
                g[i]=g[i+1];
            }
            n--;
            printf("\nGuest deleted successfully!\n");
            break;
        }
    }
    if(i==n)
    {
        printf("\nGuest not found!\n");
    }
}

void modifyGuest()
{
    int i,room,choice;
    char temp[50];
    printf("\nEnter the room number of the guest to be modified : ");
    scanf("%d",&room);
    for(i=0;i<n;i++)
    {
        if(g[i].room_no==room)
        {
            printf("\nCurrent details of the guest are : \n");
            displayGuest(i);
            printf("\nEnter the field to be modified : \n1. Name\n2. Address\n3. Phone number\n4. Number of days\n5. Rate per day\n6. Occupancy\nEnter your choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: getchar(); printf("\nEnter the new name of the guest : "); fgets(temp,30,stdin); strcpy(g[i].name,temp); break;
                case 2: getchar(); printf("\nEnter the new address of the guest : "); fgets(temp,50,stdin); strcpy(g[i].address,temp); break;
                case 3: getchar(); printf("\nEnter the new phone number of the guest : "); fgets(temp,15,stdin); strcpy(g[i].phone_no,temp); break;
                case 4: printf("\nEnter the new number of days of stay : "); scanf("%d",&g[i].days); break;
                case 5: printf("\nEnter the new rate per day : "); scanf("%f",&g[i].rate); break;
                case 6: printf("\nEnter the new occupancy (1 - Single, 2 - Double, 3 - Suite) : "); scanf("%d",&g[i].occupancy); break;
                default: printf("\nInvalid option selected!\n"); break;
            }
            printf("\nGuest modified successfully!\n");
            break;
        }
    }
    if(i==n)
    {
        printf("\nGuest not found!\n");
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n===========================");
        printf("\nC Hotel Management System");
        printf("\n===========================");
        printf("\n1. Add Guest");
        printf("\n2. Search Guest");
        printf("\n3. Display All Guests");
        printf("\n4. Delete Guest");
        printf("\n5. Modify Guest");
        printf("\n6. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: addGuest(); break;
            case 2: searchGuest(); break;
            case 3: displayAllGuests(); break;
            case 4: deleteGuest(); break;
            case 5: modifyGuest(); break;
            case 6: printf("\nThank you for using C Hotel Management System!\n"); return 0;
            default : printf("\nInvalid choice! Please choose a valid option.\n"); break;
        }
    }
    return 0;
}