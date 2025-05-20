//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine
{
    char name[50];
    char type[20];
    int stock;
    float price;
};

struct order
{
    char name[50];
    int quantity;
    float total_cost;
};

void add_medicine()
{
    FILE *fp;
    struct medicine med;
    fp=fopen("medicines.txt","a");
    if(fp==NULL)
    {
        printf("Cannot open file!!");
        return;
    }
    printf("Enter name of medicine:");
    scanf("%s",med.name);
    printf("Enter type of medicine:");
    scanf("%s",med.type);
    printf("Enter stock available:");
    scanf("%d",&med.stock);
    printf("Enter price per unit:");
    scanf("%f",&med.price);
    fprintf(fp,"%s %s %d %f\n",med.name,med.type,med.stock,med.price);
    printf("Medicine added successfully!\n");
    fclose(fp);
}

void view_medicines()
{
    FILE *fp;
    struct medicine med;
    fp=fopen("medicines.txt","r");
    if(fp==NULL)
    {
        printf("Cannot open file!!");
        return;
    }
    printf("\n%-20s %-10s %-10s %-10s\n","Name","Type","Stock","Price");
    printf("----------------------------------------------------------\n");
    while(fscanf(fp,"%s %s %d %f",med.name,med.type,&med.stock,&med.price)!=EOF)
    {
        printf("%-20s %-10s %-10d %-10.2f\n",med.name,med.type,med.stock,med.price);
    }
    fclose(fp);
}

void update_stock()
{
    FILE *fp,*temp;
    struct medicine med;
    char name[50];
    int stock;
    fp=fopen("medicines.txt","r");
    temp=fopen("temp.txt","w");
    if(fp==NULL || temp==NULL)
    {
        printf("Cannot open file!!");
        return;
    }
    printf("Enter name of medicine to update stock:");
    scanf("%s",name);
    while(fscanf(fp,"%s %s %d %f",med.name,med.type,&med.stock,&med.price)!=EOF)
    {
        if(strcmp(name,med.name)==0)
        {
            printf("Current stock available: %d\n",med.stock);
            printf("Enter new stock available:");
            scanf("%d",&stock);
            med.stock=stock;
            fprintf(temp,"%s %s %d %f\n",med.name,med.type,med.stock,med.price);
            printf("Stock updated successfully!\n");
        }
        else
        {
            fprintf(temp,"%s %s %d %f\n",med.name,med.type,med.stock,med.price);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("medicines.txt");
    rename("temp.txt","medicines.txt");
}

void place_order()
{
    FILE *fp;
    struct medicine med;
    struct order odr;
    char name[50];
    int quantity,flag=0;
    fp=fopen("medicines.txt","r");
    if(fp==NULL)
    {
        printf("Cannot open file!!");
        return;
    }
    printf("Enter name of medicine to order:");
    scanf("%s",name);
    printf("Enter quantity:");
    scanf("%d",&quantity);
    while(fscanf(fp,"%s %s %d %f",med.name,med.type,&med.stock,&med.price)!=EOF)
    {
        if(strcmp(name,med.name)==0)
        {
            if(quantity<=med.stock)
            {
                flag=1;
                printf("%.2f rupees per unit.\n",med.price);
                odr.total_cost=med.price*quantity;
                odr.quantity=quantity;
                strcpy(odr.name,name);

                FILE *order_fp;
                order_fp=fopen("orders.txt","a");
                if(order_fp==NULL)
                {
                    printf("Cannot open file!!");
                    return;
                }
                fprintf(order_fp,"%s %d %.2f\n",odr.name,odr.quantity,odr.total_cost);
                printf("Order placed successfully!\n");

                med.stock=med.stock-quantity;

                FILE *temp;
                temp=fopen("temp.txt","a");
                if(temp==NULL)
                {
                    printf("Cannot open file!!");
                    return;
                }
                fprintf(temp,"%s %s %d %f\n",med.name,med.type,med.stock,med.price);
                fclose(temp);
                remove("medicines.txt");
                rename("temp.txt","medicines.txt");
            }
            else
            {
                flag=1;
                printf("Requested quantity is not available!!\n");
            }
        }
    }
    if(flag==0)
    {
        printf("Medicine not found!!\n");
    }
    fclose(fp);
}

void view_orders()
{
    FILE *fp;
    struct order odr;
    fp=fopen("orders.txt","r");
    if(fp==NULL)
    {
        printf("Cannot open file!!");
        return;
    }
    printf("\n%-20s %-10s %-10s\n","Name","Quantity","Total Cost");
    printf("------------------------------------------------\n");
    while(fscanf(fp,"%s %d %f",odr.name,&odr.quantity,&odr.total_cost)!=EOF)
    {
        printf("%-20s %-10d %-10.2f\n",odr.name,odr.quantity,odr.total_cost);
    }
    fclose(fp);
}

void about()
{
    printf("This is a simple MEDICAL STORE MANAGEMENT SYSTEM.\n");
    printf("Developed in C Language in a Medieval Style.\n");
    printf("Author: Medieval Programmer\n");
}

void menu()
{
    int choice;
    while(1)
    {
        printf("\n\nWelcome to the MEDICAL STORE MANAGEMENT SYSTEM!\n");
        printf("*************************************************\n");
        printf("\t1. Add Medicine\n");
        printf("\t2. View Medicines\n");
        printf("\t3. Update Stock\n");
        printf("\t4. Place Order\n");
        printf("\t5. View Orders\n");
        printf("\t6. About\n");
        printf("\t7. Exit\n");
        printf("*************************************************\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                add_medicine();
                break;
            case 2:
                view_medicines();
                break;
            case 3:
                update_stock();
                break;
            case 4:
                place_order();
                break;
            case 5:
                view_orders();
                break;
            case 6:
                about();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!!\n");
        }
    }
}

int main()
{
    menu();
    return 0;
}