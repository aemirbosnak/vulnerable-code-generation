//FormAI DATASET v1.0 Category: Expense Tracker ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct expenses
{
    int id;
    char category[20];
    float amount;
    char date[11];
}e;

void add_expense()
{
    FILE *fp;
    fp=fopen("expenses.txt","ab");
    printf("Enter the category (maximum 20 characters): ");
    getchar();
    fgets(e.category,20,stdin);
    printf("Enter the amount: ");
    scanf("%f",&e.amount);
    printf("Enter the date (format:dd-mm-yyyy): ");
    getchar();
    fgets(e.date,11,stdin);
    e.id=1;
    fseek(fp,-sizeof(e),SEEK_END);
    if(fread(&e,sizeof(e),1,fp)==1)
    {
        e.id=e.id+e.id;
    }
    fwrite(&e,sizeof(e),1,fp);
    fclose(fp);
    printf("\nExpense added successfully!!\n\n");
}

void view_expenses()
{
    FILE *fp;
    fp=fopen("expenses.txt","rb");
    if(fp==NULL)
    {
        printf("\nFile not found!!\n\n");
        return;
    }
    printf("\nExpense details:\n\n");
    printf("ID   CATEGORY          AMOUNT      DATE\n");
    while(fread(&e,sizeof(e),1,fp)==1)
    {
        printf("%-5d%-20s%-12.2f%s",e.id,e.category,e.amount,e.date);
    }
    fclose(fp);
    printf("\n\n");
}

void total_expenses()
{
    FILE *fp;
    fp=fopen("expenses.txt","rb");
    if(fp==NULL)
    {
        printf("\nFile not found!!\n\n");
        return;
    }
    float total=0.0;
    while(fread(&e,sizeof(e),1,fp)==1)
    {
        total=total+e.amount;
    }
    fclose(fp);
    printf("\nTotal expenses: %.2f\n\n",total);
}

void delete_expense()
{
    FILE *fp,*ft;
    int found=0;
    int expense_id;
    printf("Enter the ID of the expense to delete: ");
    scanf("%d",&expense_id);
    fp=fopen("expenses.txt","rb");
    ft=fopen("temporary.txt","wb");
    while(fread(&e,sizeof(e),1,fp)==1)
    {
        if(expense_id!=e.id)
        {
            fwrite(&e,sizeof(e),1,ft);
        }
        else
        {
            found=1;
        }
    }
    fclose(fp);
    fclose(ft);
    if(found==0)
    {
        printf("\nExpense not found!!\n\n");
    }
    else
    {
        remove("expenses.txt");
        rename("temporary.txt","expenses.txt");
        printf("\nExpense deleted successfully!!\n\n");
    }
}

void update_expense()
{
    FILE *fp;
    int found=0;
    int expense_id;
    printf("Enter the ID of the expense to update: ");
    scanf("%d",&expense_id);
    fp=fopen("expenses.txt","rb+");
    while(fread(&e,sizeof(e),1,fp)==1)
    {
        if(expense_id==e.id)
        {
            printf("Enter the updated category (maximum 20 characters): ");
            getchar();
            fgets(e.category,20,stdin);
            printf("Enter the updated amount: ");
            scanf("%f",&e.amount);
            printf("Enter the updated date (format:dd-mm-yyyy): ");
            getchar();
            fgets(e.date,11,stdin);
            fseek(fp,-sizeof(e),SEEK_CUR);
            fwrite(&e,sizeof(e),1,fp);
            found=1;
            break;
        }
    }
    fclose(fp);
    if(found==0)
    {
        printf("\nExpense not found!!\n\n");
    }
    else
    {
        printf("\nExpense updated successfully!!\n\n");
    }
}

int main()
{
    int choice;
    printf("**********WELCOME TO EXPENSE TRACKER**********\n\n");
    while(1)
    {
        printf("What would you like to do?\n\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Total expenses\n");
        printf("4. Delete expense\n");
        printf("5. Update expense\n");
        printf("6. Exit\n\n");
        printf("Enter your choice (1-6): ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: add_expense();
                    break;
            case 2: view_expenses();
                    break;
            case 3: total_expenses();
                    break;
            case 4: delete_expense();
                    break;
            case 5: update_expense();
                    break;
            case 6: printf("\nThank you for using Expense Tracker!!\n\n");
                    exit(0);
                    break;
            default: printf("\nInvalid choice!!\n\n");
                     break;
        }
    }
    return 0;
}