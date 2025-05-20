//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct bank_record{
    int acc_num;
    char name[50];
    float balance;
}record;

void add_record();
void display_record();
void search_record();
void update_record();
void delete_record();

int main(){
    int choice;
    while(1){
        printf("Welcome to Cryptic Banking Record System!\n");
        printf("Please choose an option:\n");
        printf("1. Add Record\n");
        printf("2. Display Record\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");
        scanf("%d", & choice);

        switch(choice){
            case 1: add_record();
            break;

            case 2: display_record();
            break;

            case 3: search_record();
            break;

            case 4: update_record();
            break;

            case 5: delete_record();
            break;

            case 6: exit(0);
            break;

            default: printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}

void add_record(){
    FILE *fp;
    fp = fopen("bank_record.dat", "ab");
    printf("Enter Account Number: ");
    scanf("%d", &record.acc_num);
    printf("Enter Name: ");
    scanf("%s", &record.name);
    printf("Enter Balance: ");
    scanf("%f", &record.balance);
    fwrite(&record, sizeof(record), 1, fp);
    fclose(fp);
    printf("Record added successfully!\n");
}

void display_record(){
    FILE *fp;
    fp = fopen("bank_record.dat", "rb");
    while(fread(&record, sizeof(record), 1, fp)){
        printf("Account Number: %d\n", record.acc_num);
        printf("Name: %s\n", record.name);
        printf("Balance: %f\n", record.balance);
        printf("\n");
    }
    fclose(fp);
}

void search_record(){
    int acc_num, found = 0;
    FILE *fp;
    fp = fopen("bank_record.dat", "rb");
    printf("Enter Account Number to search: ");
    scanf("%d", &acc_num);
    while(fread(&record, sizeof(record), 1, fp)){
        if(record.acc_num == acc_num){
            printf("Account Number: %d\n", record.acc_num);
            printf("Name: %s\n", record.name);
            printf("Balance: %f\n", record.balance);
            printf("\n");
            found = 1;
        }
    }
    if(found == 0){
        printf("Record not found!\n");
    }
    fclose(fp);
}

void update_record(){
    int acc_num, found = 0;
    FILE *fp;
    fp = fopen("bank_record.dat", "rb+");
    printf("Enter Account Number to update: ");
    scanf("%d", &acc_num);
    while(fread(&record, sizeof(record), 1, fp)){
        if(record.acc_num == acc_num){
            printf("Enter Name: ");
            scanf("%s", &record.name);
            printf("Enter Balance: ");
            scanf("%f", &record.balance);
            fseek(fp, -sizeof(record), SEEK_CUR);
            fwrite(&record, sizeof(record), 1, fp);
            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("Record not found!\n");
    }
    fclose(fp);
}

void delete_record(){
    int acc_num, found = 0;
    FILE *fp1, *fp2;
    fp1 = fopen("bank_record.dat", "rb");
    fp2 = fopen("temp.dat", "wb");
    printf("Enter Account Number to delete: ");
    scanf("%d", &acc_num);
    while(fread(&record, sizeof(record), 1, fp1)){
        if(record.acc_num == acc_num){
            found = 1;
        }else{
            fwrite(&record, sizeof(record), 1, fp2);
        }
    }
    if(found == 0){
        printf("Record not found!\n");
    }else{
        fclose(fp1);
        fclose(fp2);
        remove("bank_record.dat");
        rename("temp.dat", "bank_record.dat");
        printf("Record deleted successfully!\n");
    }
}