//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

struct customer{
    char name[50];
    int room_no;
    int days;
    float room_rent;
    float food_bill;
    float total;
}cust[100];

int count = 0;

void add_customer(){
    printf("\nEnter Customer Details:\n");
    printf("\nName: ");
    scanf("%s", cust[count].name);
    printf("Room No: ");
    scanf("%d", &cust[count].room_no);
    printf("Days: ");
    scanf("%d", &cust[count].days);
    printf("Room Rent: ");
    scanf("%f", &cust[count].room_rent);
    printf("Food Bill: ");
    scanf("%f", &cust[count].food_bill);
    cust[count].total = cust[count].room_rent + cust[count].food_bill;
    count++;
    printf("Customer Added Successfully!\n");
}

void display_customer(){
    int i, room_no;
    printf("\nEnter Room No: ");
    scanf("%d", &room_no);
    
    for(i=0; i<count; i++){
        if(cust[i].room_no == room_no){
            printf("\n Customer Details:\n");
            printf("\n Name: %s ",cust[i].name);
            printf("\n Room No: %d ",cust[i].room_no);
            printf("\n Days: %d ",cust[i].days);
            printf("\n Room Rent: %.2f ",cust[i].room_rent);
            printf("\n Food Bill: %.2f ",cust[i].food_bill);
            printf("\n Total: %.2f ",cust[i].total);
            return;
        }
    }
    
    printf("\n No Customer Found with Room No %d", room_no);
}

int main(){
    
    int ch;
    
    printf("Welcome to our Hotel Management System\n");
    
    while(ch != 3){
        printf("\n 1. Add Customer ");
        printf("\n 2. Display Customer ");
        printf("\n 3. Exit\n");
        printf("\n Enter Your Choice: ");
        
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                add_customer();
                break;
            case 2:
                display_customer();
                break;
            case 3:
                printf("\n Thanks for Using Hotel Management System!");
                exit(0);
            default:
                printf("\n Invalid Choice! ");
                break;
        }
    }
    return 0;
}