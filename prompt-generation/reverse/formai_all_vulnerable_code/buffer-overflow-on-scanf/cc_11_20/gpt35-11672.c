//FormAI DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROOMS 100

int main(){
    
    int i, j, m[MAX_ROOMS], n, c, x, y, z;
    float price[MAX_ROOMS], total_price=0;
    char name[MAX_ROOMS][20], phone[MAX_ROOMS][10], email[MAX_ROOMS][20], card_no[MAX_ROOMS][16];
    
    printf("Enter the number of rooms: ");
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        printf("Enter the details for Room %d:\n", i+1);
        printf("Enter the name: ");
        scanf("%s", name[i]);
        printf("Enter the phone number: ");
        scanf("%s", phone[i]);
        printf("Enter the email id: ");
        scanf("%s", email[i]);
        printf("Enter the card number: ");
        scanf("%s", card_no[i]);
        printf("Enter the room type (1 for single, 2 for double, 3 for suite): ");
        scanf("%d", &m[i]);
        switch(m[i]){
            case 1:
                price[i] = 5000.0;
                break;
            case 2:
                price[i] = 7500.0;
                break;
            case 3:
                price[i] = 10000.0;
                break;
            default:
                printf("Invalid room type! Please enter a valid room type.\n");
                i--;
                break;
        }
    }
    
    printf("\n\n\t\t  HOTEL BILL\n\n");
    printf("ROOM NO.\tNAME\t\tPHONE NO.\tEMAIL\t\tCARD NO.\t\t\tROOM TYPE\t\tPRICE\n");
    printf("=================================================================================================================\n");
    for(i=0; i<n; i++){
        printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%0.2f\n", i+1, name[i], phone[i], email[i], card_no[i], m[i]==1?"Single":(m[i]==2?"Double":"Suite"), price[i]);
        total_price += price[i];
    }
    
    printf("=================================================================================================================\n");
    printf("\n\nTOTAL PRICE: %0.2f", total_price);
    
    printf("\n\nTo get the invoice of any room, enter the room number: ");
    scanf("%d", &x);
    if(x>n || x<=0){
        printf("Invalid room number! Please enter a valid room number.\n");
    }else{
        printf("\n\n\t\t  HOTEL INVOICE\n\n");
        printf("NAME\t\tROOM TYPE\t\tPRICE\n");
        printf("=================================================================================================================\n");
        printf("%s\t\t%s\t\t\t%0.2f", name[x-1], m[x-1]==1?"Single":(m[x-1]==2?"Double":"Suite"), price[x-1]);
    }

    printf("\n\nTo print the details of all the rooms of a particular type, enter the room type (1 for single, 2 for double, 3 for suite): ");
    scanf("%d", &y);
    printf("\n\n\t\t  ROOM DETAILS\n\n");
    printf("ROOM NO.\tNAME\t\tPHONE NO.\tEMAIL\t\tCARD NO.\n");
    printf("=================================================================================================================\n");
    for(i=0, c=0; i<n; i++){
        if(m[i]==y){
            printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n", i+1, name[i], phone[i], email[i], card_no[i]);
            c++;
        }
    }
    if(c==0){
        printf("Sorry! No rooms of the given room type found.\n");
    }

    printf("\n\nTo print the details of all the rooms whose price is above a certain value, enter the value: ");
    scanf("%d", &z);
    printf("\n\n\t\t  ROOM DETAILS\n\n");
    printf("ROOM NO.\tNAME\t\tPHONE NO.\tEMAIL\t\tCARD NO.\t\t\tROOM TYPE\t\tPRICE\n");
    printf("=================================================================================================================\n");
    for(i=0, c=0; i<n; i++){
        if(price[i]>z){
            printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%0.2f\n", i+1, name[i], phone[i], email[i], card_no[i], m[i]==1?"Single":(m[i]==2?"Double":"Suite"), price[i]);
            c++;
        }
    }
    if(c==0){
        printf("Sorry! No rooms found with price above the given value.\n");
    }
    
    return 0;
}