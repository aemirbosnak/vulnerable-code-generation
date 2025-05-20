//FormAI DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customer{
    char name[20];
    int room_no;
    int days;
    float bill;
}c;

void menu(){
    printf("*******************\n");
    printf("1. Book a room\n");
    printf("2. Check-out\n");
    printf("3. View all customer details\n");
    printf("4. Exit\n");
    printf("*******************\n");
}

void book_room(){
    FILE *fp;
    fp=fopen("customers.txt","a+");
    printf("Enter your name: ");
    fflush(stdin);
    scanf("%[^\n]",c.name);
    printf("Enter room number: ");
    fflush(stdin);
    scanf("%d",&c.room_no);
    printf("Enter number of days: ");
    fflush(stdin);
    scanf("%d",&c.days);
    c.bill = c.days * 1000;
    fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",c.name,c.room_no,c.days,c.bill);
    fclose(fp);
    printf("Room booked successfully!\n");
    printf("*******************\n");
}

void check_out(){
    FILE *fp,*temp;
    int room_no,found=0;
    float refund=0, paid=0;
    printf("Enter room number: ");
    scanf("%d",&room_no);
    fp=fopen("customers.txt","r+");
    temp=fopen("temp.txt","w");
    while(fscanf(fp,"%s%d%d%f",c.name,&c.room_no,&c.days,&c.bill)!=EOF){
        if(room_no==c.room_no){
            found=1;
            printf("\nName: %s\nRoom no: %d\nDays: %d\nBill: RS. %.2f\n",c.name,c.room_no,c.days,c.bill);
            printf("Enter amount paid: ");
            scanf("%f",&paid);
            refund = paid - c.bill;
            printf("Refund amount: RS. %.2f\n\n",refund);
        }
        else{
            fprintf(temp,"%s\t\t%d\t\t%d\t\t%.2f\n",c.name,c.room_no,c.days,c.bill);
        }
    }
    if(found==0){
        printf("No records found!\n");
    }
    fclose(fp);
    fclose(temp);
    //delete the original file and rename the temp file
    remove("customers.txt");
    rename("temp.txt","customers.txt");
}

void view_details(){
    FILE *fp;
    fp=fopen("customers.txt","r");
    printf("Name\t\tRoom No\t\tDays\t\tBill\n");
    while(fscanf(fp,"%s%d%d%f",c.name,&c.room_no,&c.days,&c.bill)!=EOF){
        printf("%s\t\t%d\t\t%d\t\t%.2f\n",c.name,c.room_no,c.days,c.bill);
    }
    fclose(fp);
}

int main(){
    int choice;
    while(1){
        menu();
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: book_room();
                    break;
            case 2: check_out();
                    break;
            case 3: view_details();
                    break;
            case 4: printf("Thank you for using our hotel management system!");
                    exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}