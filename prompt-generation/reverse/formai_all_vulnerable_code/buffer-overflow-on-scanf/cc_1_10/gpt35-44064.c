//FormAI DATASET v1.0 Category: Password management ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20

/* Structure to store username and password */
struct Details {
    char username[MAX];
    char password[MAX];
};

/* Function to print menu and ask for input */
int menu() {
    int choice;
    printf("\n---Password Management System---\n");
    printf("1. Add new details\n");
    printf("2. View details\n");
    printf("3. Update details\n");
    printf("4. Delete details\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

/* Function to add new details to file */
void addDetails(FILE *fp) {
    struct Details temp;
    printf("\nEnter username: ");
    scanf("%s", temp.username);
    printf("Enter password: ");
    scanf("%s", temp.password);
    fwrite(&temp, sizeof(temp), 1, fp);
    printf("\nDetails added successfully.\n");
}

/* Function to view details from file */
void viewDetails(FILE *fp) {
    struct Details temp;
    int count = 0;
    printf("\n---List of Details---\n");
    while(fread(&temp, sizeof(temp), 1, fp)) {
        printf("Username: %s\nPassword: %s\n", temp.username, temp.password);
        count++;
    }
    if(count == 0) printf("No details found.\n");
}

/* Function to update details in file */
void updateDetails(FILE *fp) {
    struct Details temp, newtemp;
    int found = 0;
    printf("\nEnter the username to update: ");
    scanf("%s", temp.username);
    printf("Enter the new password: ");
    scanf("%s", newtemp.password);
    rewind(fp);
    while(fread(&temp, sizeof(temp), 1, fp)) {
        if(strcmp(temp.username, newtemp.username) == 0) {
            fseek(fp, -sizeof(temp), SEEK_CUR);
            fwrite(&newtemp, sizeof(newtemp), 1, fp);
            found = 1;
            break;
        }
    }
    if(found == 1) printf("\nDetails updated successfully.\n");
    else printf("\nDetails not found.\n");
}

/* Function to delete details from file */
void deleteDetails(FILE *fp) {
    struct Details temp;
    int found = 0;
    FILE *fp2;
    fp2 = fopen("temp.txt", "wb");
    printf("\nEnter the username to delete: ");
    scanf("%s", temp.username);
    rewind(fp);
    while(fread(&temp, sizeof(temp), 1, fp)) {
        if(strcmp(temp.username, temp.username) != 0) {
            fwrite(&temp, sizeof(temp), 1, fp2);
        }
        else found = 1;
    }
    fclose(fp);
    fclose(fp2);
    remove("details.txt");
    rename("temp.txt", "details.txt");
    if(found == 1) printf("\nDetails deleted successfully.\n");
    else printf("\nDetails not found.\n");
}

/* Main function to call other functions */
int main() {
    FILE *fp;
    int choice;
    char password[] = "password123";
    printf("Enter the password: ");
    char temp[15];
    scanf("%s", temp);
    if(strcmp(temp, password) != 0) {
        printf("\nThe password is incorrect. Exiting...\n");
        return 0;
    }
    fp = fopen("details.txt", "ab+");
    if(fp == NULL) {
        printf("\nError opening file. Exiting...\n");
        return 0;
    }
    while(1) {
        choice = menu();
        switch(choice) {
            case 1:
                addDetails(fp);
                break;
            case 2:
                viewDetails(fp);
                break;
            case 3:
                updateDetails(fp);
                break;
            case 4:
                deleteDetails(fp);
                break;
            case 5:
                fclose(fp);
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}