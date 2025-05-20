//FormAI DATASET v1.0 Category: Hotel Management System ; Style: surprised
#include<stdio.h>
#include<string.h>

struct customer{
    int room_no;
    char name[20];
    char address[50];
    char phone_no[15];
};

struct room{
    int room_no;
    char room_type[20];
    float price;
    int availability;
};

int main(){
    struct customer c[100];
    struct room r[100];
    int i,n,room,bill,ch;
    char name[20];
    printf("Welcome to C Hotel Management System\n");
    printf("======================================\n\n");

    printf("Enter the number of rooms in the hotel: ");
    scanf("%d",&n);

    //Set the data of the rooms
    for(i=0;i<n;i++){
        r[i].room_no=i+1;
        printf("\nEnter the room type for room %d: ",r[i].room_no);
        scanf("%s",r[i].room_type);
        printf("Enter the price of %s room: ",r[i].room_type);
        scanf("%f",&r[i].price);
        r[i].availability=1;
    }
    
    do{
        printf("\nChoose an option:\n");
        printf("1. Book a room\n");
        printf("2. View Customer Details\n");
        printf("3. Exit\n");
        
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                printf("\nEnter the customer details\n");
                printf("Name: ");
                scanf("%s",c[i].name);
                printf("Address: ");
                scanf("%s",c[i].address);
                printf("Phone number: ");
                scanf("%s",c[i].phone_no);
                printf("\nThe available rooms are: \n\n");
                printf("| %-10s | %-10s | %-10s |\n","Room No.","Room Type","Price");
                for(i=0;i<n;i++){
                    if(r[i].availability==1){
                        printf("| %-10d | %-10s | %-10.2f |\n",r[i].room_no,r[i].room_type,r[i].price);
                    }
                }
                printf("\nEnter the room number that you want to book: ");
                scanf("%d",&room);
                if(r[room-1].availability==1){
                    printf("\nBooking Successful!\n");
                    c[room-1].room_no=room;
                    r[room-1].availability=0;
                    bill+=r[room-1].price;
                }else{
                    printf("\nSorry! Room not available\n");
                }
                break;
            case 2:
                printf("\nEnter the name of the customer: ");
                scanf("%s",name);
                for(i=0;i<n;i++){
                    if(strcmp(c[i].name,name)==0){
                        printf("\nCustomer details for %s are:\n",c[i].name);
                        printf("Address: %s\n",c[i].address);
                        printf("Phone Number: %s\n",c[i].phone_no);
                        printf("Room No.: %d\n",c[i].room_no);
                    }
                }
                break;
            case 3:
                printf("\nThank you for using C Hotel Management System!\n");
                break;
            default:
                printf("\nInvalid option. Please choose a valid option.\n");
                break;
        }    
    }while(ch!=3);

    return 0;
}