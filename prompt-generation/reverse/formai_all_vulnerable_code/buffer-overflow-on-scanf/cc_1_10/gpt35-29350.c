//FormAI DATASET v1.0 Category: Hotel Management System ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

struct hotel{
    char name[50];
    int room_number;
    int room_type;
    int days;
    int amount;
};


int main(){
    int i,n,temp;
    struct hotel h[50];
    printf("\n*****Welcome to C Hotel Management System*****\n");
    printf("\nEnter the number of bookings you want to make:");
    scanf("%d",&n);

    //Taking input from the user
    for(i=0;i<n;i++){
        printf("\nEnter the name of customer:");
        scanf("%s",h[i].name);
        printf("\nEnter the room number:");
        scanf("%d",&h[i].room_number);
        printf("\nChoose the room type:\n1. Standard\n2. Deluxe\n3. Suite\n");
        scanf("%d",&h[i].room_type);
        printf("\nEnter the number of days of stay:");
        scanf("%d",&h[i].days);
    }

    //Calculating the amount for each booking
    for(i=0;i<n;i++){  
        if(h[i].room_type==1){
            h[i].amount=h[i].days*5000;
        }
        else if(h[i].room_type==2){
            h[i].amount=h[i].days*8000;
        }
        else{
            h[i].amount=h[i].days*12000;
        }
    }

    //Sorting the bookings based on the room type
    for(i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(h[i].room_type>h[j].room_type){
                temp=h[i].room_type;
                h[i].room_type=h[j].room_type;
                h[j].room_type=temp;

                temp=h[i].room_number;
                h[i].room_number=h[j].room_number;
                h[j].room_number=temp;

                temp=h[i].days;
                h[i].days=h[j].days;
                h[j].days=temp;

                temp=h[i].amount;
                h[i].amount=h[j].amount;
                h[j].amount=temp;
            }
        }
    }

    //Displaying the final amount for each booking
    printf("\n\n************Bookings Sorted based on Room Type************");
    printf("\n\nName of Customer\tRoom Number\tRoom Type\tDays of Stay\tAmount\n");
    for(i=0;i<n;i++){  
        printf("%s\t\t\t%d\t\t\%d\t\t%d\t\t%d\n",h[i].name,h[i].room_number,h[i].room_type,h[i].days,h[i].amount);
    }

    return 0;
}