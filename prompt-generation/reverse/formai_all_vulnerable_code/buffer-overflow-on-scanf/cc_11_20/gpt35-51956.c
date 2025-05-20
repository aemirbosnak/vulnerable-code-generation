//FormAI DATASET v1.0 Category: Hotel Management System ; Style: realistic
#include<stdio.h>
#include<string.h>

struct room{
    int room_no;
    char type[20];
    int price;
    int availability;
};

int main(){
    struct room hotel[5];
    int i=0;
    //initialize the hotel
    for(i=0;i<5;i++)
    {
        hotel[i].room_no=i+101;
        if(i%2==0)
        {
            strcpy(hotel[i].type,"AC");
            hotel[i].price=2000;
            hotel[i].availability=1;
        }
        else
        {
            strcpy(hotel[i].type,"Non-AC");
            hotel[i].price=1500;
            hotel[i].availability=1;
        }
    }
    int option=0;
    while(option!=4)
    {
        printf("\nWelcome to C Hotel Management System\n");
        printf("Please choose an option:\n");
        printf("1. View room details\n2. Book a room\n3. List all available rooms\n4. Exit\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("\nEnter the room number to view details: ");
                int room_num;
                scanf("%d",&room_num);
                if(room_num>=101 && room_num<=105)
                {
                    printf("\nRoom Number: %d",hotel[room_num-101].room_no);
                    printf("\nType: %s",hotel[room_num-101].type);
                    printf("\nPrice: %d",hotel[room_num-101].price);
                    if(hotel[room_num-101].availability==1)
                        printf("\nAvailability: Available");
                    else
                        printf("\nAvailability: Not Available");
                    break;
                }
                else{
                    printf("Invalid Room Number!");
                    break;
                }
            case 2:
                printf("\nEnter the room number to book: ");
                int num;
                scanf("%d",&num);
                if(num>=101 && num<=105){
                    if(hotel[num-101].availability==1)
                    {
                        printf("\nRoom Booked!\n");
                        hotel[num-101].availability=0;
                        break;
                    }
                    else{
                        printf("\nRoom not available!\n");
                        break;
                    }
                }
                else{
                    printf("Invalid Room Number!");
                    break;
                }
            case 3:
                printf("\nList of all available rooms:");
                for(i=0;i<5;i++)
                {
                    if(hotel[i].availability==1)
                        printf("\nRoom Number: %d\tType: %s\tPrice: %d",hotel[i].room_no,hotel[i].type,hotel[i].price);
                }
                printf("\n");
                break;
            case 4:
                printf("\nThank you for using C Hotel Management System!");
                break;
            default:
                printf("\nInvalid option! Please choose a valid option.\n");
                
        }
    }
    return 0;
}