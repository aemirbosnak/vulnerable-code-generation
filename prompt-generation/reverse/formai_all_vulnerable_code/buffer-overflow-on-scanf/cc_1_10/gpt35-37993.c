//FormAI DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct expenses   //A structure with fields to store expense details
{
    char item[50]; 
    float amount;
}record;
int main()
{
    int choice=0,total_records=0,i;
    float expense_total=0;
    char ch='y';
    FILE *file_ptr;
    file_ptr=fopen("expense.dat","ab+");  //file to store data in binary mode
    if(file_ptr==NULL)
    {
        printf("Unable to open file!");
        return 0;
    }
    printf("Expense Tracker\n");
    printf("---------------\n");
    printf("\n");
    do{
        printf("Enter the expense item name: ");
        scanf("%s",record.item);
        printf("Enter the amount: ");
        scanf("%f",&record.amount);
        //Storing the expense details into the file
        fwrite(&record,sizeof(struct expenses),1,file_ptr);
        total_records++;
        //Calculating the total expense amount
        expense_total+=record.amount;
        printf("Do you want to enter more expenses? (y/n): ");
        scanf(" %c",&ch);
    }while(ch=='y' || ch=='Y');
    printf("Expenses Summary\n");
    printf("-------------------------------\n");
    //Reading the data one record at a time using fread()
    fread(&record,sizeof(struct expenses),1,file_ptr);
    while(!feof(file_ptr))
    {
        printf("%s: $%.2f\n",record.item,record.amount);
        fread(&record,sizeof(struct expenses),1,file_ptr);
    }
    printf("-------------------------------\n");
    printf("Total Expenses: $%.2f\n",expense_total);
    printf("Number of Expenses: %d\n",total_records);
    fclose(file_ptr);
    return 0;
}