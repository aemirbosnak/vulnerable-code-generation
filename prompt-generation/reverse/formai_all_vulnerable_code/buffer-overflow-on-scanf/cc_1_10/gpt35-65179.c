//FormAI DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

void add_contact();
void list_contacts();
void search_contact();
void delete_contact();

int main() {
    int choice;
    
    while (1) {
        printf("\n======= Contact List ========\n");
        printf("1. Add New Contact\n");
        printf("2. List All Contacts\n");
        printf("3. Search for Contact\n");
        printf("4. Delete Contact\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("\nGoodbye!\n");
                return 0;
            case 1:
                add_contact();
                break;
            case 2:
                list_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            default:
                printf("\nInvalid Choice! Try Again.\n");
                break;
        }
    }
    
    return 0;
}

void add_contact() {
    Contact new_contact;
    FILE *fp = fopen("contacts.dat", "ab");
    if (fp == NULL) {
        printf("\nError opening file! Contact list cannot be updated.\n");
        return;
    }
    
    printf("\nEnter Name: ");
    fflush(stdin);
    gets(new_contact.name);
    printf("Enter Email: ");
    fflush(stdin);
    gets(new_contact.email);
    
    fwrite(&new_contact, sizeof(Contact), 1, fp);
    
    printf("\nNew Contact Has Been Added!\n");
    
    fclose(fp);
}

void list_contacts() {
    Contact current_contact;
    int count = 0;
    FILE *fp = fopen("contacts.dat", "rb");
    
    if (fp == NULL) {
        printf("\nError opening file! Contact list cannot be displayed.\n");
        return;
    }
    
    printf("\n======= Contact List ========\n");
    
    while (fread(&current_contact, sizeof(Contact), 1, fp)) {
        printf("Name: %s\n", current_contact.name);
        printf("Email: %s\n", current_contact.email);
        printf("=============================\n");
        count++;
    }
    
    printf("\nTotal Contacts: %d\n", count);
    
    fclose(fp);
}

void search_contact() {
    char search_name[MAX_NAME_LEN];
    Contact current_contact;
    int count = 0;
    FILE *fp = fopen("contacts.dat", "rb");
    
    if (fp == NULL) {
        printf("\nError opening file! Contact list cannot be displayed.\n");
        return;
    }
    
    printf("\nEnter Name to search: ");
    fflush(stdin);
    gets(search_name);
    
    while (fread(&current_contact, sizeof(Contact), 1, fp)) {
        if (strcmp(current_contact.name, search_name) == 0) {
            printf("\n======= Contact Details ========\n");
            printf("Name: %s\n", current_contact.name);
            printf("Email: %s\n", current_contact.email);
            printf("===============================\n");
            count++;
        }
    }
    
    if (count == 0) {
        printf("\nNo Contact Found!\n");
    } else {
        printf("\nTotal Contacts Found: %d\n", count);
    }
    
    fclose(fp);
}

void delete_contact() {
    char delete_name[MAX_NAME_LEN];
    Contact current_contact;
    FILE *fp = fopen("contacts.dat", "rb");
    FILE *temp_fp = fopen("temp.dat", "wb");
    
    if (fp == NULL) {
        printf("\nError opening file! Contact list cannot be modified.\n");
        return;
    }
    
    printf("\nEnter Name to Delete: ");
    fflush(stdin);
    gets(delete_name);
    
    while (fread(&current_contact, sizeof(Contact), 1, fp)) {
        if (strcmp(current_contact.name, delete_name) != 0) {
            fwrite(&current_contact, sizeof(Contact), 1, temp_fp);
        }
    }
    
    remove("contacts.dat");
    rename("temp.dat", "contacts.dat");
    
    printf("\nContact '%s' Has Been Deleted!\n", delete_name);
    
    fclose(fp);
    fclose(temp_fp);
}