//FormAI DATASET v1.0 Category: Banking Record System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

struct bank_record{
    int id;
    char name[50];
    int balance;
};

int main(){

    int option;
    struct bank_record record;
    FILE *file_pointer;

    printf("Welcome to the Medieval Banking Record System!\n\n");

    while(1){
        printf("\nPlease select an option:\n");
        printf("1. Add a new record\n");
        printf("2. Search for a record\n");
        printf("3. Delete a record\n");
        printf("4. Update a record\n");
        printf("5. Display all records\n");
        printf("6. Quit\n\n");
        scanf("%d", &option);

        switch(option){
            case 1:
                file_pointer = fopen("bank_records.txt", "a");
                if(file_pointer == NULL){
                    printf("Oops! Something went wrong. Please try again later.\n");
                    exit(1);
                }
                printf("Please enter the knight's ID: ");
                scanf("%d", &record.id);
                printf("Please enter the knight's name: ");
                scanf("%s", &record.name);
                printf("Please enter the knight's balance: ");
                scanf("%d", &record.balance);
                fwrite(&record, sizeof(struct bank_record), 1, file_pointer);
                fclose(file_pointer);
                printf("\nRecord added successfully!\n");
                break;
            case 2:
                file_pointer = fopen("bank_records.txt", "r");
                if(file_pointer == NULL){
                    printf("Oops! Something went wrong. Please try again later.\n");
                    exit(1);
                }
                printf("Please enter the knight's ID to search: ");
                int search_id;
                int found = 0;
                scanf("%d", &search_id);
                while(fread(&record, sizeof(struct bank_record), 1, file_pointer)){
                    if(record.id == search_id){
                        printf("ID: %d\n", record.id);
                        printf("Name: %s\n", record.name);
                        printf("Balance: %d\n", record.balance);
                        found = 1;
                        break;
                    }
                }
                if(found == 0){
                    printf("Record not found!\n");
                }
                fclose(file_pointer);
                break;
            case 3:
                file_pointer = fopen("bank_records.txt", "r");
                if(file_pointer == NULL){
                    printf("Oops! Something went wrong. Please try again later.\n");
                    exit(1);
                }
                printf("Please enter the knight's ID to delete: ");
                int delete_id;
                int deleted = 0;
                scanf("%d", &delete_id);
                FILE *temp_pointer;
                temp_pointer = fopen("temp_bank_records.txt", "w");
                while(fread(&record, sizeof(struct bank_record), 1, file_pointer)){
                    if(record.id != delete_id){
                        fwrite(&record, sizeof(struct bank_record), 1, temp_pointer);
                    }
                    else{
                        deleted = 1;
                    }
                }
                fclose(file_pointer);
                fclose(temp_pointer);
                remove("bank_records.txt");
                rename("temp_bank_records.txt", "bank_records.txt");
                if(deleted == 1){
                    printf("\nRecord deleted successfully!\n");
                }
                else{
                    printf("\nRecord not found!\n");
                }
                break;
            case 4:
                file_pointer = fopen("bank_records.txt", "r");
                if(file_pointer == NULL){
                    printf("Oops! Something went wrong. Please try again later.\n");
                    exit(1);
                }
                printf("Please enter the knight's ID to update: ");
                int update_id;
                int updated = 0;
                scanf("%d", &update_id);
                while(fread(&record, sizeof(struct bank_record), 1, file_pointer)){
                    if(record.id == update_id){
                        printf("Please enter the updated balance: ");
                        scanf("%d", &record.balance);
                        updated = 1;
                        break;
                    }
                }
                fclose(file_pointer);
                file_pointer = fopen("bank_records.txt", "r+");
                if(file_pointer == NULL){
                    printf("Oops! Something went wrong. Please try again later.\n");
                    exit(1);
                }
                while(fread(&record, sizeof(struct bank_record), 1, file_pointer)){
                    if(record.id == update_id){
                        fseek(file_pointer, -1*sizeof(struct bank_record), SEEK_CUR);
                        fwrite(&record, sizeof(struct bank_record), 1, file_pointer);
                        break;
                    }
                }
                fclose(file_pointer);
                if(updated == 1){
                    printf("\nRecord updated successfully!\n");
                }
                else{
                    printf("\nRecord not found!\n");
                }
                break;
            case 5:
                file_pointer = fopen("bank_records.txt", "r");
                if(file_pointer == NULL){
                    printf("Oops! Something went wrong. Please try again later.\n");
                    exit(1);
                }
                printf("All records:\n");
                while(fread(&record, sizeof(struct bank_record), 1, file_pointer)){
                    printf("ID: %d\n", record.id);
                    printf("Name: %s\n", record.name);
                    printf("Balance: %d\n\n", record.balance);
                }
                fclose(file_pointer);
                break;
            case 6:
                printf("\nThank you for using the Medieval Banking Record System!\n");
                exit(0);
            default:
                printf("\nInvalid option, please try again.\n");
        }

    }

    return 0;
}