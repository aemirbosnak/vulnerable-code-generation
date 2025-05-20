//FormAI DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customer{
    char name[30];
    char address[100];
    char phone_number[15];
    int room_number;
    int days;
};

struct room{
    int room_number;
    char type[10];
    int price;
    int available;
};

struct bill{
    int room_number;
    int days;
    int room_charge;
    int food_charge;
    int total;
};

void display_menu(){
    printf("Welcome to C Hotel Management System\n");
    printf("1. Check-in\n");
    printf("2. Check-out\n");
    printf("3. Room Status\n");
    printf("4. List of Customers\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
}

void check_in(struct room* rooms, int num_of_rooms, struct customer* customers, int num_of_customers){
    int room_no,found=0,i;
    for(i=0;i<num_of_rooms;i++){
        if(rooms[i].available){
            printf("Room Number: %d\n",rooms[i].room_number);
            printf("Type: %s\n",rooms[i].type);
            printf("Price: %d\n",rooms[i].price);
            found=1;
        }
    }
    if(!found){
        printf("All rooms are occupied!\n");
        return;
    }
    printf("Enter Room Number: ");
    scanf("%d",&room_no);
    for(i=0;i<num_of_rooms;i++){
        if(rooms[i].room_number==room_no){
            if(rooms[i].available){
                int index=num_of_customers;
                strcpy(customers[index].name,"");
                strcpy(customers[index].address,"");
                strcpy(customers[index].phone_number,"");
                customers[index].room_number=room_no;
                customers[index].days=0;
                printf("Enter Customer Name: ");
                scanf("%s",customers[index].name);
                printf("Enter Customer Address: ");
                scanf("%s",customers[index].address);
                printf("Enter Phone Number: ");
                scanf("%s",customers[index].phone_number);
                printf("Enter Number of Days: ");
                scanf("%d",&customers[index].days);
                rooms[i].available=0;
                printf("Check-in successful!\n");
            }
            else{
                printf("Room is already occupied!\n");
            }
            break;
        }
    }
    if(i==num_of_rooms){
        printf("Invalid Room Number!\n");
        return;
    }
}

void check_out(struct room* rooms, int num_of_rooms, struct customer* customers, int num_of_customers, struct bill* bills, int num_of_bills){
    int room_no,found_customer=-1,i;
    printf("Enter Room Number: ");
    scanf("%d",&room_no);
    for(i=0;i<num_of_customers;i++){
        if(customers[i].room_number==room_no){
            found_customer=i;
            break;
        }
    }
    if(found_customer==-1){
        printf("Invalid Room Number!\n");
        return;
    }
    int index=num_of_bills;
    bills[index].room_number=room_no;
    bills[index].days=customers[found_customer].days;
    bills[index].room_charge=0;
    bills[index].food_charge=0;
    for(i=0;i<num_of_rooms;i++){
        if(rooms[i].room_number==room_no){
            rooms[i].available=1;
            bills[index].room_charge+=customers[found_customer].days*rooms[i].price;
            break;
        }
    }
    printf("Enter Food Charges: ");
    scanf("%d",&bills[index].food_charge);
    bills[index].total+=bills[index].room_charge+bills[index].food_charge;
    printf("Bill for Room Number %d\n",room_no);
    printf("Room Charge: %d\n",bills[index].room_charge);
    printf("Food Charge: %d\n",bills[index].food_charge);
    printf("Total Charge: %d\n",bills[index].total);
    for(i=found_customer;i<num_of_customers-1;i++){
        customers[i]=customers[i+1];
    }
    printf("Check-out successful!\n");
}

void room_status(struct room* rooms, int num_of_rooms){
    printf("Room\tType\tPrice\tAvailability\n");
    int i;
    for(i=0;i<num_of_rooms;i++){
        printf("%d\t%s\t%d\t",rooms[i].room_number,rooms[i].type,rooms[i].price);
        if(rooms[i].available){
            printf("Available\n");
        }
        else{
            printf("Occupied\n");
        }
    }
}

void list_of_customers(struct customer* customers, int num_of_customers){
    printf("Name\tAddress\tPhone Number\tRoom Number\tDays\n");
    int i;
    for(i=0;i<num_of_customers;i++){
        printf("%s\t%s\t%s\t%d\t%d\n",customers[i].name,customers[i].address,customers[i].phone_number,customers[i].room_number,customers[i].days);
    }
}

void initialize_rooms(struct room* rooms, int num_of_rooms){
    int i;
    for(i=0;i<num_of_rooms;i++){
        rooms[i].room_number=i+1;
        strcpy(rooms[i].type,"");
        rooms[i].price=0;
        rooms[i].available=1;
    }
}

int main(){
    int num_of_rooms=3,num_of_customers=0,num_of_bills=0;
    struct room rooms[num_of_rooms];
    initialize_rooms(rooms,num_of_rooms);
    struct customer customers[num_of_customers];
    struct bill bills[num_of_bills];
    int choice;
    do{
        display_menu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                check_in(rooms,num_of_rooms,customers,num_of_customers);
                break;
            case 2:
                check_out(rooms,num_of_rooms,customers,num_of_customers,bills,num_of_bills);
                break;
            case 3:
                room_status(rooms,num_of_rooms);
                break;
            case 4:
                list_of_customers(customers,num_of_customers);
                break;
            case 5:
                printf("Thank you for using C Hotel Management System!\n");
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }while(choice!=5);
    return 0;
}