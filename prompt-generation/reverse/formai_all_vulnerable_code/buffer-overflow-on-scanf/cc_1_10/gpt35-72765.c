//FormAI DATASET v1.0 Category: Phone Book ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Contact {
    char name[50];
    char phone_number[15];
    char email[50];
};

void add_contact();
void display_contact();
void search_contact();
void delete_contact();

int main() {
    int option, count=0;
    while(1) {
        printf("\n\t**********************\n");
        printf("\t  PHONE BOOK APPLICATION\n");
        printf("\t**********************\n");
        printf("\tMenu:\n");
        printf("\t1. Add Contact\n");
        printf("\t2. Display All Contacts\n");
        printf("\t3. Search Contact\n");
        printf("\t4. Delete Contact\n");
        printf("\t5. Exit\n");
        printf("\nEnter your Option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                add_contact();
                count++;
                break;
            case 2:
                if(count==0) {
                    printf("\nNo Contacts Found!\n");
                } else {
                    display_contact();
                }
                break;
            case 3:
                if(count==0) {
                    printf("\nNo Contacts Found!\n");
                } else {
                    search_contact();
                }
                break;
            case 4:
                if(count==0) {
                    printf("\nNo Contacts Found!\n");
                } else {
                    delete_contact();
                    count--;
                }
                break;
            case 5:
                printf("\nExiting Phone Book Application..");
                exit(0);
                break;
            default:
                printf("\nInvalid Option! Try Again!\n");
                break;
        }
    }
    return 0;
}

void add_contact() {
    struct Contact new_contact;
    printf("\nEnter Contact Details:\n");
    printf("Name: ");
    fflush(stdin);
    gets(new_contact.name);
    printf("Phone Number: ");
    fflush(stdin);
    gets(new_contact.phone_number);
    printf("Email: ");
    fflush(stdin);
    gets(new_contact.email);
    FILE *fptr;
    fptr=fopen("phonebook.txt", "a+");
    fprintf(fptr, "%s %s %s\n", new_contact.name, new_contact.phone_number, new_contact.email);
    fclose(fptr);
    printf("\nContact Added Successfully!\n");
}

void display_contact() {
    struct Contact c;
    FILE *fptr;
    fptr=fopen("phonebook.txt", "r");
    printf("\n %-25s %-20s %-20s\n", "Name", "Phone Number", "Email");
    printf("----------------------------------------------------------------------------\n");
    while(fscanf(fptr, "%s %s %s\n", c.name, c.phone_number, c.email)!=EOF) {
        printf(" %-25s %-20s %-20s\n", c.name, c.phone_number, c.email);
    }
    fclose(fptr);
}

void search_contact() {
    struct Contact c;
    char search_name[50];
    int found = 0;
    printf("\nEnter Name to Search: ");
    fflush(stdin);
    gets(search_name);
    FILE *fptr;
    fptr=fopen("phonebook.txt", "r");
    while(fscanf(fptr, "%s %s %s", c.name, c.phone_number, c.email)!=EOF) {
        if(strcmp(search_name, c.name)==0) {
            printf("\n %-25s %-20s %-20s\n", "Name", "Phone Number", "Email");
            printf("----------------------------------------------------------------------------\n");
            printf(" %-25s %-20s %-20s\n", c.name, c.phone_number, c.email);
            found = 1;
            break;
        }
    }
    if(found==0) {
        printf("\nNo Contact Found!\n");
    }
    fclose(fptr);
}

void delete_contact() {
    struct Contact c;
    char delete_name[50], temp[50];
    int found=0;
    printf("\nEnter Name to Delete: ");
    fflush(stdin);
    gets(delete_name);
    FILE *fptr, *fptr1;
    fptr=fopen("phonebook.txt", "r");
    fptr1=fopen("temp.txt", "w");
    while(fscanf(fptr, "%s %s %s", c.name, c.phone_number, c.email)!=EOF) {
        if(strcmp(delete_name, c.name)!=0) {
            fprintf(fptr1, "%s %s %s\n", c.name, c.phone_number, c.email);
        } else {
            found = 1;
        }
    }
    fclose(fptr);
    fclose(fptr1);
    if(found==0) {
        printf("\nNo Contact Found with the Name: %s\n", delete_name);
    } else {
        fptr=fopen("phonebook.txt", "w");
        fptr1=fopen("temp.txt", "r");
        while(fscanf(fptr1, "%s %s %s", c.name, c.phone_number, c.email)!=EOF) {
            fprintf(fptr, "%s %s %s\n", c.name, c.phone_number, c.email);
        }
        fclose(fptr);
        fclose(fptr1);
        printf("\nContact Deleted Successfully!\n");
    }
}