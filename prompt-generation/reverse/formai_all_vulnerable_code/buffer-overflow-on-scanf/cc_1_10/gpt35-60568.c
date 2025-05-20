//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//function to check if the entered username and password are correct
int login(char username[],char password[])
{
    if(strcmp(username,"admin")==0 && strcmp(password,"admin")==0)
        return 1;
    else
        return 0;
}

int main()
{
    char username[20], password[20];
    int choice,flag=0;
    float price=0.0, total_price=0.0;
    int quantity=0, count=0;
    char medicine_name[100];
    char another='y';

    printf("------ Welcome to the C Medical Store Management System ------\n\n");
    printf("Please Login\n");

    do{
        printf("\nEnter your username: ");
        scanf("%s",username);
        printf("Enter your password: ");
        scanf("%s",password);
        
        if(login(username,password)==0){
            printf("\nInvalid username or password. Please try again.\n");
        }else{
            printf("\nLogin successful!\n");
            flag=1;
        }
    }while(flag==0);

    printf("\n%s, which operation do you want to perform?\n", username);
    printf("1. Add medicine to the store\n");
    printf("2. Sell medicine\n");
    printf("3. Quit\n");

    //medicine structure that contains information of a medicine
    struct medicine
    {
        char name[100];
        int quantity;
        float price;
    }m[100];

    while(choice!=3)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the name of the medicine: ");
                scanf("%s",m[count].name);
                printf("Enter the quantity: ");
                scanf("%d",&m[count].quantity);
                printf("Enter the price: ");
                scanf("%f",&m[count].price);
                printf("\nMedicine added successfully!\n");
                count++;
                break;

            case 2:
                printf("\nList of available medicines:\n");
                printf("Name           Quantity           Price\n");
                for(int i=0;i<count;i++)
                {
                    printf("%-15s %-19d $%-15.2f\n",m[i].name,m[i].quantity,m[i].price);
                }

                do{
                    printf("\nEnter the name of the medicine you want to buy: ");
                    scanf("%s",medicine_name);
                    printf("Enter the quantity: ");
                    scanf("%d",&quantity);

                    for(int i=0;i<count;i++)
                    {
                        if(strcmp(medicine_name,m[i].name)==0 && quantity<=m[i].quantity)
                        {
                            m[i].quantity = m[i].quantity - quantity;
                            price = m[i].price * quantity;
                            total_price += price;
                            printf("\n%s sold successfully! You have to pay $%.2f\n", medicine_name, price);
                        }else if(strcmp(medicine_name,m[i].name)==0 && quantity>m[i].quantity)
                        {
                            printf("\nSorry, we don't have enough quantity of %s\n",medicine_name);
                        }
                    }
                    printf("Do you want to buy another medicine? (y/n) ");
                    fflush(stdin);
                    scanf("%c",&another);
                }while(another=='y' || another =='Y');
                break;

            case 3:
                printf("\nThank you for using our system!\n");
                printf("The total amount earned today is: $%.2f\n",total_price);
                break;

            default:
                printf("\nInvalid choice! Please enter again.\n");
        }
    }

    return 0;
}