//FormAI DATASET v1.0 Category: Banking Record System ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct customer{
    int account_number;
    char name[20];
    int balance;
}c;

void view_record()
{
    FILE *fp;
    int found=0,num;
    printf("Enter account number to view record: ");
    scanf("%d",&num);
    fp=fopen("banking_record.dat","rb");
    while(fread(&c,sizeof(c),1,fp)==1){
        if(c.account_number==num){
            printf("Account number: %d\nName: %s\nBalance: %d\n\n",c.account_number,c.name,c.balance);
            found=1;
        }
    }
    fclose(fp);
    if(!found){
        printf("No such record found.\n");
    }
}
void modify_record()
{
    FILE *fp;
    int found=0,num,pos=0;
    printf("Enter account number to modify record: ");
    scanf("%d",&num);
    fp=fopen("banking_record.dat","rb+");
    while(fread(&c,sizeof(c),1,fp)==1){
        if(c.account_number==num){
            printf("Account number: %d\nName: %s\nBalance: %d\n\n",c.account_number,c.name,c.balance);
            printf("Enter new name: ");
            scanf(" %[^\n]",c.name);
            printf("Enter new balance: ");
            scanf("%d",&c.balance);
            fseek(fp,pos*sizeof(c),SEEK_SET);
            fwrite(&c,sizeof(c),1,fp);
            printf("Record modified successfully.\n");
            found=1;
            break;
        }
        pos++;
    }
    fclose(fp);
    if(!found){
        printf("No such record found.\n");
    }
}
void add_record()
{
    FILE *fp;
    fp=fopen("banking_record.dat","ab");
    printf("Enter account number: ");
    scanf("%d",&c.account_number);
    printf("Enter name: ");
    scanf(" %[^\n]",c.name);
    printf("Enter balance: ");
    scanf("%d",&c.balance);
    fwrite(&c,sizeof(c),1,fp);
    fclose(fp);
    printf("Record added successfully.\n");
}
void delete_record()
{
    FILE *fp,*temp;
    int found=0,num;
    printf("Enter account number to delete record: ");
    scanf("%d",&num);
    fp=fopen("banking_record.dat","rb");
    temp=fopen("temp.dat","wb");
    while(fread(&c,sizeof(c),1,fp)==1){
        if(c.account_number!=num){
            fwrite(&c,sizeof(c),1,temp);
        }else{
            printf("Record deleted successfully.\n");
            found=1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("banking_record.dat");
    rename("temp.dat","banking_record.dat");
    if(!found){
        printf("No such record found.\n");
    }
}

void main()
{
    int ch;
    printf("Welcome to Banking Record System.\n\n");
    do{
        printf("1. View record\n");
        printf("2. Modify record\n");
        printf("3. Add record\n");
        printf("4. Delete record\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        printf("\n");
        switch(ch){
            case 1:
                view_record();
                break;
            case 2:
                modify_record();
                break;
            case 3:
                add_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                printf("Thank you for using our system.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }while(ch!=5);
}