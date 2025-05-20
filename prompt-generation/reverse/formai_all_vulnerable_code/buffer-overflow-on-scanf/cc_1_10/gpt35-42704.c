//FormAI DATASET v1.0 Category: Banking Record System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for bank record system
struct Reg_Record {
    char name[50];
    char address[100];
    char phone[20];
    float balance;
} record;

// Function to add new record
void addRecord() {
    printf("Enter name: ");
    scanf("%s", &record.name);
    printf("Enter address: ");
    scanf("%s", &record.address);
    printf("Enter phone: ");
    scanf("%s", &record.phone);
    printf("Enter balance: ");
    scanf("%f", &record.balance);
    
    FILE *fp = fopen("bank_records.txt", "a"); // Opening the file in append mode
    
    // Checking if file exists or not
    if(fp == NULL) {
        printf("Can't open file for writing!");
        exit(1);
    }
    
    // Writing record to the file
    fprintf(fp, "%s, %s, %s, %.2f\n", record.name, record.address, record.phone, record.balance);
    fclose(fp);
    
    printf("Record added successfully!\n");
}

// Function to list all records
void listRecords() {
    FILE *fp = fopen("bank_records.txt", "r"); // Opening the file in read mode
    
    // Checking if file exists or not
    if(fp == NULL) {
        printf("File doesn't exist yet!\n");
        return;
    }
    
    printf("%-20s %-40s %-20s %-20s\n", "Name", "Address", "Phone", "Balance");
    while(fscanf(fp, "%[^,],%[^,],%[^,],%f\n", record.name, record.address, record.phone, &record.balance) != EOF) {
        printf("%-20s %-40s %-20s %-20.2f\n", record.name, record.address, record.phone, record.balance);
    }
    fclose(fp);
}

// Function to search for a record by name
void searchRecord() {
    char name[50];
    int found = 0;
    
    printf("Enter name to search: ");
    scanf("%s", &name);
    
    FILE *fp = fopen("bank_records.txt", "r"); // Opening the file in read mode
    
    // Checking if file exists or not
    if(fp == NULL) {
        printf("File doesn't exist yet!\n");
        return;
    }
    
    while(fscanf(fp, "%[^,],%[^,],%[^,],%f\n", record.name, record.address, record.phone, &record.balance) != EOF) {
        if(strcmp(name, record.name) == 0) {
            printf("Record found!\n");
            printf("%-20s %-40s %-20s %-20s\n", "Name", "Address", "Phone", "Balance");
            printf("%-20s %-40s %-20s %-20.2f\n", record.name, record.address, record.phone, record.balance);
            found = 1;
            break;
        }
    }
    
    if(found == 0) {
        printf("Record not found!\n");
    }
    
    fclose(fp);
}

// Function to update a record by name
void updateRecord() {
    char name[50];
    int found = 0;
    
    printf("Enter name to update: ");
    scanf("%s", &name);
    
    FILE *fp = fopen("bank_records.txt", "r+"); // Opening the file in read/write mode
    
    // Checking if file exists or not
    if(fp == NULL) {
        printf("File doesn't exist yet!\n");
        return;
    }
    
    while(fscanf(fp, "%[^,],%[^,],%[^,],%f\n", record.name, record.address, record.phone, &record.balance) != EOF) {
        if(strcmp(name, record.name) == 0) {
            printf("Record found!\n");
            
            // Updating the record
            printf("Enter new address: ");
            scanf("%s", &record.address);
            printf("Enter new phone: ");
            scanf("%s", &record.phone);
            printf("Enter new balance: ");
            scanf("%f", &record.balance);
            
            fseek(fp, -1 * (strlen(record.name) + strlen(record.address) + strlen(record.phone) + 5), SEEK_CUR); // Moving file pointer back to the beginning of the record
            
            // Writing updated record to the file
            fprintf(fp, "%s, %s, %s, %.2f\n", record.name, record.address, record.phone, record.balance);
            
            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }
    
    if(found == 0) {
        printf("Record not found!\n");
    }
    
    fclose(fp);
}

// Function to delete a record by name
void deleteRecord() {
    char name[50];
    int found = 0;
    
    printf("Enter name to delete: ");
    scanf("%s", &name);
    
    FILE *fp = fopen("bank_records.txt", "r"); // Opening the file in read mode
    
    // Checking if file exists or not
    if(fp == NULL) {
        printf("File doesn't exist yet!\n");
        return;
    }
    
    FILE *temp = fopen("temp.txt", "w"); // Creating temporary file in write mode
    
    while(fscanf(fp, "%[^,],%[^,],%[^,],%f\n", record.name, record.address, record.phone, &record.balance) != EOF) {
        if(strcmp(name, record.name) == 0) {
            printf("Record found and deleted!\n");
            found = 1;
        } else {
            fprintf(temp, "%s, %s, %s, %.2f\n", record.name, record.address, record.phone, record.balance);
        }
    }
    
    if(found == 0) {
        printf("Record not found!\n");
    }
    
    // Closing both files and replacing old file with temporary file
    fclose(fp);
    fclose(temp);
    remove("bank_records.txt");
    rename("temp.txt", "bank_records.txt");
}

// Main function
int main() {
    int choice;
    
    do {
        printf("\n");
        printf("     C BANKING RECORD SYSTEM\n");
        printf("----------------------------------\n");
        printf("| 1. Add new record             |\n");
        printf("| 2. List all records           |\n");
        printf("| 3. Search for a record        |\n");
        printf("| 4. Update a record            |\n");
        printf("| 5. Delete a record            |\n");
        printf("| 6. Exit program               |\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addRecord();
                    break;
            case 2: listRecords();
                    break;
            case 3: searchRecord();
                    break;
            case 4: updateRecord();
                    break;
            case 5: deleteRecord();
                    break;
            case 6: printf("Thank you for using C Banking Record System!\n");
                    break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 6);
    
    return 0;
}