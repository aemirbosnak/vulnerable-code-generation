//FormAI DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct customer{
    char name[50];
    int room_no;
    char address[100];
    int phone_no;
    int days;
    float payment;
};

void main_menu();
void add_customer();
void view_customer();
void edit_customer();
void delete_customer();
void generate_bill();
void search_customer();

int room[10]={0,0,0,0,0,0,0,0,0,0}; 

int main(){
    system("color 70");
    printf("\n\n\t\t\t\t\t           Welcome to the C Hotel Management System!\n\n");
    main_menu();
    return 0;
}

void main_menu(){
    int choice;
    printf("\n\n                              MAIN MENU \n\n");
    printf(" 1. Add Customer\n");
    printf(" 2. View Customer\n");
    printf(" 3. Edit Customer\n");
    printf(" 4. Delete Customer\n");
    printf(" 5. Generate Bill\n");
    printf(" 6. Search Customer\n");
    printf(" 7. Exit\n");
    printf("\n Please enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            add_customer();
            break;
        case 2:
            view_customer();
            break;
        case 3:
            edit_customer();
            break;
        case 4:
            delete_customer();
            break;
        case 5:
            generate_bill();
            break;
        case 6:
            search_customer();
            break;
        case 7:
            printf("Thank you for using C Hotel Management System!");
            exit(0);
            break;
        default:
            printf("\nInvalid Input!\n");
            main_menu();
    }
}

void add_customer(){
    struct customer cus;
    int i,flag=0;
    FILE *p;
    p=fopen("cusfile.txt","a");
    if(p==NULL)
        printf("\nUnable to open file!");
    else{
        printf("\nEnter the following customer details:\n");
        printf("Name: ");
        scanf("%s",cus.name);
        printf("Room Number (101-110): ");
        scanf("%d",&cus.room_no);
        if(cus.room_no>110 || cus.room_no<101){
            printf("Invalid Room Number!\n");
            add_customer();
        }
        else{
            for(i=0;i<10;i++){
                if(room[i]==cus.room_no){
                    printf("This room is already occupied!\n");
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                printf("Address: ");
                scanf("%s",cus.address);
                printf("Phone Number: ");
                scanf("%d",&cus.phone_no);
                printf("No. of Days Stayed: ");
                scanf("%d",&cus.days);
                cus.payment=cus.days*5000;
                room[i]=cus.room_no;
                fwrite(&cus,sizeof(cus),1,p);
                fclose(p);
                printf("\nCustomer record has been added successfully!\n");
                main_menu();
            }
            else
                add_customer();
        }
    }
}

void view_customer(){
    struct customer cus;
    FILE *p;
    p=fopen("cusfile.txt","r");
    if(p==NULL)
        printf("\nUnable to open file!");
    else{
        printf("\n%-20s%-10s%-20s%-15s%-15s%-10s\n","Name","Room No.","Address","Phone No.","No. of Days","Payment");
        while(fread(&cus,sizeof(cus),1,p)){
            printf("%-20s%-10d%-20s%-15d%-15d%-10.2f\n",cus.name,cus.room_no,cus.address,cus.phone_no,cus.days,cus.payment);
        }
        fclose(p);
        main_menu();
    }
}

void edit_customer(){
    struct customer cus;
    int i,flag=0,choice,new_room_no;
    FILE *p,*temp;
    p=fopen("cusfile.txt","r");
    temp=fopen("temp.txt","a");
    if(p==NULL)
        printf("\nUnable to open file!");
    else{
        printf("Enter the name of the customer record you want to edit: ");
        scanf("%s",cus.name);
        while(fread(&cus,sizeof(cus),1,p)){
            if(strcmp(cus.name,cus.name)==0){
                flag=1;
                printf("\nFollowing customer record found in the file: \n");
                printf("\n%-20s%-10s%-20s%-15s%-15s%-10s\n","Name","Room No.","Address","Phone No.","No. of Days","Payment");
                printf("%-20s%-10d%-20s%-15d%-15d%-10.2f\n",cus.name,cus.room_no,cus.address,cus.phone_no,cus.days,cus.payment);
                printf("\nEnter the Field to be edited: \n");
                printf("1. Address\n");
                printf("2. Phone Number\n");
                printf("3. Room Number\n");
                printf("\nEnter your choice: ");
                scanf("%d",&choice);
                switch(choice){
                    case 1:
                        printf("Enter new address: ");
                        scanf("%s",cus.address);
                        break;
                    case 2:
                        printf("Enter new phone number: ");
                        scanf("%d",&cus.phone_no);
                        break;
                    case 3:
                        printf("Enter new room number: ");
                        scanf("%d",&new_room_no);
                        if(new_room_no>110 || new_room_no<101){
                            printf("Invalid Room Number!\n");
                            edit_customer();
                        }
                        else if(room[i]==new_room_no){
                            printf("This room is already occupied!\n");
                            edit_customer();
                        }
                        else{
                            room[i]=new_room_no;
                            cus.room_no=new_room_no;
                        }
                        break;
                    default:
                        printf("\nInvalid Input!");
                        edit_customer();
                }
                fwrite(&cus,sizeof(cus),1,temp);
                printf("\nCustomer record has been updated successfully!\n");
            }
            else
                fwrite(&cus,sizeof(cus),1,temp);
        }
        if(flag==0)
            printf("\nNo customer record found associated to the name given!\n");
        fclose(p);
        fclose(temp);
        remove("cusfile.txt");
        rename("temp.txt","cusfile.txt");
        main_menu();
    }
}

void delete_customer(){
    struct customer cus;
    int flag=0,choice;
    FILE *p,*temp;
    p=fopen("cusfile.txt","r");
    temp=fopen("temp.txt","a");
    if(p==NULL)
        printf("\nUnable to open file!");
    else{
        printf("Enter the name of the customer record you want to delete: ");
        scanf("%s",cus.name);
        while(fread(&cus,sizeof(cus),1,p)){
            if(strcmp(cus.name,cus.name)==0){
                flag=1;
                printf("\nFollowing customer record found in the file: \n");
                printf("\n%-20s%-10s%-20s%-15s%-15s%-10s\n","Name","Room No.","Address","Phone No.","No. of Days","Payment");
                printf("%-20s%-10d%-20s%-15d%-15d%-10.2f\n",cus.name,cus.room_no,cus.address,cus.phone_no,cus.days,cus.payment);
                printf("Are you sure you want to delete this record?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d",&choice);
                if(choice==1)
                    printf("\nCustomer record has been deleted successfully!\n");
                else{
                    printf("\nCustomer record has not been deleted!\n");
                    fwrite(&cus,sizeof(cus),1,temp);
                }
            }
            else
                fwrite(&cus,sizeof(cus),1,temp);
        }
        if(flag==0)
            printf("\nNo customer record found associated to the name given!\n");
        fclose(p);
        fclose(temp);
        remove("cusfile.txt");
        rename("temp.txt","cusfile.txt");
        main_menu();
    }
}

void generate_bill(){
    struct customer cus;
    int flag=0;
    char name[50];
    FILE *p;
    p=fopen("cusfile.txt","r");
    if(p==NULL)
        printf("\nUnable to open file!");
    else{
        printf("Enter the name of the customer record for which you want to generate bill: ");
        scanf("%s",name);
        while(fread(&cus,sizeof(cus),1,p)){
            if(strcmp(cus.name,name)==0){
                flag=1;
                printf("\nBill for the customer record: \n");
                printf("\n%-20s%-10s%-20s%-15s%-15s%-10s%-10s\n","Name","Room No.","Address","Phone No.","No. of Days","Payment","Total");
                printf("%-20s%-10d%-20s%-15d%-15d%-10.2f%-10.2f\n",cus.name,cus.room_no,cus.address,cus.phone_no,cus.days,cus.payment,cus.payment+(cus.payment*0.1));
            }
        }
        if(flag==0)
            printf("\nNo customer record found associated to the name given!\n");
        fclose(p);
        main_menu();
    }
}

void search_customer(){
    struct customer cus;
    int flag=0,choice,room_no;
    char name[50];
    FILE *p;
    p=fopen("cusfile.txt","r");
    if(p==NULL)
        printf("\nUnable to open file!");
    else{
        printf("\n1. Search by Name\n");
        printf("2. Search by Room No.\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the name of the customer record you want to search: ");
                scanf("%s",name);
                while(fread(&cus,sizeof(cus),1,p)){
                    if(strcmp(cus.name,name)==0){
                        flag=1;
                        printf("\nFollowing customer record found in the file: \n");
                        printf("\n%-20s%-10s%-20s%-15s%-15s%-10s\n","Name","Room No.","Address","Phone No.","No. of Days","Payment");
                        printf("%-20s%-10d%-20s%-15d%-15d%-10.2f\n",cus.name,cus.room_no,cus.address,cus.phone_no,cus.days,cus.payment);
                    }
                }
                if(flag==0)
                    printf("\nNo customer record found associated to the name given!\n");
                break;
            case 2:
                printf("Enter the Room No. of the customer record you want to search: ");
                scanf("%d",&room_no);
                while(fread(&cus,sizeof(cus),1,p)){
                    if(cus.room_no==room_no){
                        flag=1;
                        printf("\nFollowing customer record found in the file: \n");
                        printf("\n%-20s%-10s%-20s%-15s%-15s%-10s\n","Name","Room No.","Address","Phone No.","No. of Days","Payment");
                        printf("%-20s%-10d%-20s%-15d%-15d%-10.2f\n",cus.name,cus.room_no,cus.address,cus.phone_no,cus.days,cus.payment);
                    }
                }
                if(flag==0)
                    printf("\nNo customer record found associated to the Room No. given!\n");
                break;
            default:
                printf("\nInvalid Input!");
                search_customer();
        }
        fclose(p);
        main_menu();
    }
}