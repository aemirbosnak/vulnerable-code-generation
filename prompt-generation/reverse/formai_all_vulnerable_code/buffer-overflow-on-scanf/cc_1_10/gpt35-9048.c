//FormAI DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100  // maximum number of records that can be stored
#define MAX_USERNAME 20  // maximum length of the username
#define MAX_PASSWORD 20  // maximum length of the password

typedef struct{
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
}record_t;

record_t records[MAX_RECORDS];  // array to store all records
int num_records = 0;  // current number of stored records

void add_record(){
    if(num_records == MAX_RECORDS){
        printf("Max number of records reached.\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", records[num_records].username);
    printf("Enter password: ");
    scanf("%s", records[num_records].password);
    num_records++;
    printf("Record added.\n");
}

void delete_record(){
    if(num_records == 0){
        printf("No records to delete.\n");
        return;
    }
    char username[MAX_USERNAME];
    printf("Enter username to delete: ");
    scanf("%s", username);
    for(int i=0; i<num_records; i++){
        if(strcmp(records[i].username, username) == 0){
            // found the record to delete
            for(int j=i; j<num_records-1; j++){
                // shift records after the deleted one to fill the gap
                strcpy(records[j].username, records[j+1].username);
                strcpy(records[j].password, records[j+1].password);
            }
            num_records--;
            printf("Record deleted.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

void change_password(){
    if(num_records == 0){
        printf("No records to change password.\n");
        return;
    }
    char username[MAX_USERNAME];
    char new_password[MAX_PASSWORD];
    printf("Enter username to change password: ");
    scanf("%s", username);
    for(int i=0; i<num_records; i++){
        if(strcmp(records[i].username, username) == 0){
            // found the record to change password
            printf("Enter new password: ");
            scanf("%s", new_password);
            strcpy(records[i].password, new_password);
            printf("Password changed.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

void list_records(){
    if(num_records == 0){
        printf("No records to list.\n");
        return;
    }
    for(int i=0; i<num_records; i++){
        printf("%s : %s\n", records[i].username, records[i].password);
    }
}

int main(){
    printf("Welcome to the Password Management System.\n");
    int choice;
    do {
        printf("\n\nChoose an option:\n");
        printf("1. Add a record\n");
        printf("2. Delete a record\n");
        printf("3. Change password\n");
        printf("4. List all records\n");
        printf("5. Quit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_record();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                change_password();
                break;
            case 4:
                list_records();
                break;
            case 5:
                printf("Thank you for using Password Management System.\n");
                break;
            default:
                printf("Invalid choice. Choose again.\n");
                break;
        }
    } while(choice != 5);
    return 0;
}