//FormAI DATASET v1.0 Category: Banking Record System ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BankRecord{
    char firstName[20];
    char lastName[20];
    int accountNumber;
    float balance;
};

struct BankRecord customer[50]; //creating an array of structures

void displayMenu(){
    printf("*********BANKING RECORD SYSTEM*********\n");
    printf("1) Add Customer Record\n");
    printf("2) Edit Customer Record\n");
    printf("3) View Customer Record\n");
    printf("4) Delete Customer Record\n");
    printf("5) Exit\n");
}

int main(){
    FILE *fp,*ft; //file pointers to read & write data from/to the file
    int i,choice,n,ch;
    char newName[20];
    float newBalance;
    fp=fopen("BankRecord.txt","a+"); //opening file in append mode
    printf("**********WELCOME TO THE BANKING RECORD SYSTEM**********\n\n");
    for(;;){
        displayMenu();
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: //add customer record
                printf("\nEnter First Name: ");
                scanf("%s",customer[n].firstName);
                printf("Enter Last Name: ");
                scanf("%s",customer[n].lastName);
                printf("Enter Account Number: ");
                scanf("%d",&customer[n].accountNumber);
                printf("Enter Balance: ");
                scanf("%f",&customer[n].balance);
                fwrite(&customer[n],sizeof(struct BankRecord),1,fp); //writing data to file
                n++;
                printf("\nRecord added successfully!\n\n");
                break;

            case 2: //edit customer record
                printf("\nEnter account number of record to edit: ");
                int accNum;
                scanf("%d", &accNum);
                for(i=0;i<50;++i){
                    if(customer[i].accountNumber==accNum){
                        printf("Record Found!");
                        printf("\n\nEnter New First Name: ");
                        scanf("%s",newName);
                        printf("Enter New Balance: ");
                        scanf("%f",&newBalance);
                        strcpy(customer[i].firstName,newName);
                        customer[i].balance=newBalance;
                        ft=fopen("tempBank.txt","w+"); //opening temporary file
                        for(int j=0;j<n;++j){
                            fwrite(&customer[j],sizeof(struct BankRecord),1,ft); //writing data to temporary file
                        }
                        fclose(fp);
                        fclose(ft);
                        remove("BankRecord.txt");
                        rename("tempBank.txt","BankRecord.txt"); //renaming temporary file
                        fp=fopen("BankRecord.txt","a+"); //opening file again in append mode
                        printf("\nRecord updated successfully!\n\n");
                        break;
                    }
                    else{
                        printf("\nRecord not found!");
                        break;
                    }
                }
                break;

            case 3: //view customer record
                printf("\nEnter account number of record to view: ");
                int accNumV;
                scanf("%d", &accNumV);
                for(i=0;i<n;++i){
                    if(customer[i].accountNumber==accNumV){
                        printf("\nRecord Found!");
                        printf("\nFirst Name: %s",customer[i].firstName);
                        printf("\nLast Name: %s",customer[i].lastName);
                        printf("\nAccount Number: %d",customer[i].accountNumber);
                        printf("\nBalance: %.2f\n\n",customer[i].balance);
                        break;
                    }
                    else{
                        printf("\nRecord not found!");
                        break;
                    }
                }
                break;

            case 4: //delete customer record
                printf("\nEnter account number of record to delete: ");
                int accNumD;
                scanf("%d", &accNumD);
                ft=fopen("tempBank.txt","w+"); //opening another temporary file
                for(i=0;i<n;++i){
                    if(customer[i].accountNumber!=accNumD){
                        fwrite(&customer[i], sizeof(struct BankRecord), 1, ft); //writing data to temporary file
                    }
                    else{
                        printf("\nRecord deleted successfully!\n\n");
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("BankRecord.txt");
                rename("tempBank.txt","BankRecord.txt"); //renaming temporary file
                fp=fopen("BankRecord.txt","a+"); //opening file again in append mode
                break;

            case 5: //exit
                fclose(fp); //closing file
                printf("\nThank you for using the Banking Record System!\n");
                exit(0); //terminating program
                break;

            default: //invalid choice
                printf("\nInvalid choice! Please try again.\n\n");
                break;
        }
    }
    return 0;
}