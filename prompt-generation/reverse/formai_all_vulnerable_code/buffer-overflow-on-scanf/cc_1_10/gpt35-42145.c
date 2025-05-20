//FormAI DATASET v1.0 Category: Banking Record System ; Style: brave
#include<stdio.h>
#include<stdlib.h>

struct record{
    char account_num[15];
    char account_type[10];
    char name[50];
    float balance;
}s;

void write_records();
void display_records();

void main(){
    int choice;
    printf("\t*********** WELCOME TO BANKING RECORD SYSTEM ***********\n");

    do{
        printf("\nMenu:\n1. Write Records\n2. Display Records\n3. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: write_records();
                break;
            case 2: display_records();
                break;
            case 3: printf("Thank you for using the Banking Record System!");
                exit(0);
            default: printf("Invalid choice! Please enter a valid choice.");
        }
    }while(choice!=3);
}

void write_records(){
    FILE *fp;
    fp = fopen("records.dat", "ab");
    printf("\nEnter Account Number: ");
    fflush(stdin);
    gets(s.account_num);
    printf("Enter Account Type: ");
    fflush(stdin);
    gets(s.account_type);
    printf("Enter Name: ");
    fflush(stdin);
    gets(s.name);
    printf("Enter Balance: ");
    scanf("%f", &s.balance);
    fwrite(&s, sizeof(s), 1, fp);
    printf("\nRecord added successfully!");
    fclose(fp);
}

void display_records(){
    FILE *fp;
    fp = fopen("records.dat", "rb");
    if(fp==NULL){
        printf("\nNo records found!\n");
        return;
    }
    printf("\nRecords:\n");
    printf("\n%-15s %-10s %-50s %-10s\n", "Account Number", "Account Type", "Name", "Balance");

    while(fread(&s, sizeof(s), 1, fp)==1){
        printf("%-15s %-10s %-50s %-10.2f\n", s.account_num, s.account_type, s.name, s.balance);
    }

    fclose(fp);
}