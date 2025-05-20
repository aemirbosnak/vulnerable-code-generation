//FormAI DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
struct hotel_guest{
    int room_no;
    char name[30];
    char address[50];
    int days;
    int total_bill;
};
struct hotel_guest guest[50] ; // maximum guest capacity;

int main()
{
    int choice,i=0,j,room_no;
    while(1){
        printf("Enter the option you want to perform: \n");
        printf("1. Add Guest\n");
        printf("2. Remove Guest\n");
        printf("3. Search Guest by Room Number\n");
        printf("4. Display All Guest\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) // using switch-case for better readability
        {
            case 1: // adding a new guest
                printf("\nEnter Guest Details: ");
                printf("\nEnter Name: ");
                scanf("%s",guest[i].name);
                printf("\nEnter Address: ");
                scanf("%s",guest[i].address);
                printf("\nEnter Room Number: ");
                scanf("%d",&guest[i].room_no);
                printf("\nEnter Number of Days of Stay: ");
                scanf("%d",&guest[i].days);
                guest[i].total_bill=guest[i].days*2000; // assuming standard rate per day is Rs.2000
                printf("\nGuest successfully added. Total Bill: %d",guest[i].total_bill);
                i++; // increasing count of total guests
                break;
            
            case 2: // removing an existing guest record
                printf("\nEnter Room Number of Guest you want to Remove: ");
                scanf("%d",&room_no);
                for(j=0;j<i;j++){ // looping through all the guests
                    if(guest[j].room_no==room_no){
                        printf("\nGuest of Room Number %d is Removed. Total Bill: %d",guest[j].room_no,guest[j].total_bill);
                        guest[j]=guest[i-1]; // replacing target guest record with the last guest record in the array
                        i--; // decreasing total guests count
                        break;
                    }
                }
                if(j==i)
                printf("\nGuest of Room Number %d not found",room_no);
                break;
            
            case 3: // searching a guest by room number
                printf("\nEnter Room Number to search for Guest: ");
                scanf("%d",&room_no);
                for(j=0;j<i;j++){ // looping through all the guests
                    if(guest[j].room_no==room_no){
                        printf("\nGuest Details: ");
                        printf("\nName: %s",guest[j].name);
                        printf("\nAddress: %s",guest[j].address);
                        printf("\nDays of Stay: %d",guest[j].days);
                        printf("\nTotal Bill: %d",guest[j].total_bill);
                        break;
                    }
                }
                if(j==i)
                printf("\nGuest of Room Number %d not found",room_no);
                break;
            
            case 4: // displaying all the guest records
                printf("\nAll Guest Details:");
                for(j=0;j<i;j++){ // looping through all the guests
                    printf("\nGuest %d :",j+1);
                    printf("\nName: %s",guest[j].name);
                    printf("\nAddress: %s",guest[j].address);
                    printf("\nRoom Number: %d",guest[j].room_no);
                    printf("\nDays of Stay: %d",guest[j].days);
                    printf("\nTotal Bill: %d",guest[j].total_bill);
                }
                break;
            
            case 5: // exiting the program
            default:
                exit(0); // exit function of stdlib.h library
        }
    }
    return 0;
}