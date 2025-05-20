//FormAI DATASET v1.0 Category: Hotel Management System ; Style: brave
#include<stdio.h>
#include<string.h>

struct room{
    char room_type[10];
    int room_num;
    float price;
    char status[20];
};

struct customer{
    char name[20];
    char address[50];
    char phone[12];
    char id[10];
};

void displayOptions() {
    printf("\n1. Check available rooms");
    printf("\n2. Book a room");
    printf("\n3. Display customer details");
    printf("\n4. Display total earnings");
    printf("\n5. Exit");
}

void displayRooms(struct room *r, int size) {
    printf("\nDisplaying available rooms\n");
    printf("\nRoom Type\tRoom No.\tPrice\tStatus");
    for(int i=0;i<size;i++) {
        if(strcmp(r[i].status,"Available")==0) {
            printf("\n%s\t\t%d\t\t%.2f\t%s",r[i].room_type,r[i].room_num,r[i].price,r[i].status);
        }
    }
}

void bookRoom(struct room *r, int size, struct customer *c, int *custSize, float *totalEarnings) {
    printf("\nEnter customer details\n");
    printf("\nName: ");
    scanf("%s",c[*custSize].name);
    printf("Address: ");
    scanf("%s",c[*custSize].address);
    printf("Phone: ");
    scanf("%s",c[*custSize].phone);
    printf("ID: ");
    scanf("%s",c[*custSize].id);

    displayRooms(r,size);

    printf("\nEnter room details to book a room\n");
    printf("\nRoom Number: ");
    int num;
    scanf("%d",&num);
    int index=-1;
    for(int i=0;i<size;i++) {
        if(r[i].room_num==num) {
            index=i;
            break;
        }
    }
    if(index==-1) {
        printf("\nInvalid room number");
        return;
    }
    if(strcmp(r[index].status,"Booked")==0) {
        printf("\nRoom not available");
        return;
    }
    strcpy(r[index].status,"Booked");
    *custSize+=1;
    *totalEarnings+=r[index].price;
    printf("\nRoom booked successfully");
}

void displayCustomers(struct customer *c, int size) {
    printf("\nDisplaying customer details\n");
    printf("\nName\tAddress\tPhone\tID");
    for(int i=0;i<size;i++) {
        printf("\n%s\t%s\t%s\t%s",c[i].name,c[i].address,c[i].phone,c[i].id);
    }
}

void displayEarnings(float earnings) {
    printf("\nTotal earnings: %.2f",earnings);
}

int main() {
    struct room rooms[10]={
        {"Single",101,200,"Available"},
        {"Single",102,200,"Available"},
        {"Double",201,300,"Available"},
        {"Double",202,300,"Available"},
        {"Queen",301,400,"Available"},
        {"Queen",302,400,"Available"},
        {"King",401,500,"Available"},
        {"King",402,500,"Available"},
        {"Suite",501,600,"Available"},
        {"Suite",502,600,"Available"},
    };

    struct customer customers[100];
    int custSize=0;
    float totalEarnings=0;

    while(1) {
        displayOptions();

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                displayRooms(rooms,10);
                break;
            case 2:
                bookRoom(rooms,10,customers,&custSize,&totalEarnings);
                break;
            case 3:
                displayCustomers(customers,custSize);
                break;
            case 4:
                displayEarnings(totalEarnings);
                break;
            case 5:
                return 0;
            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}