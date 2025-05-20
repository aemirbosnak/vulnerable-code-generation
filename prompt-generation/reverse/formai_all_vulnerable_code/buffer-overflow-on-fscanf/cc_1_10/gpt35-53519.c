//FormAI DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define struct for each password entry
typedef struct password {
    char website[50];
    char username[20];
    char password[20];
} Password;

//Function to read password entry from file
void read_password_entry(FILE *fp, Password *p) {
    fscanf(fp, "%s %s %s", p->website, p->username, p->password);
}

//Function to write password entry to file
void write_password_entry(FILE *fp, Password *p) {
    fprintf(fp, "%s %s %s\n", p->website, p->username, p->password);
}

//Function to add new password entry
void add_password_entry(FILE *fp) {
    Password p;
    printf("Enter Website: ");
    scanf("%s", p.website);
    printf("Enter Username: ");
    scanf("%s", p.username);
    printf("Enter Password: ");
    scanf("%s", p.password);
    write_password_entry(fp, &p);
    printf("Password added successfully!\n");
}

//Function to search for password entry by website
void search_password_entry(FILE *fp) {
    char website[50];
    Password p;
    printf("Enter Website to search: ");
    scanf("%s", website);
    rewind(fp); //move file pointer to beginning of file
    while(!feof(fp)) { //loop until end of file is reached
        read_password_entry(fp, &p);
        if(strcmp(p.website, website) == 0) { //website found
            printf("Website: %s\nUsername: %s\nPassword: %s\n", p.website, p.username, p.password);
            return;
        }
    }
    printf("Website not found!\n");
}

//Function to display all password entries
void display_all_password_entries(FILE *fp) {
    Password p;
    rewind(fp); //move file pointer to beginning of file
    while(!feof(fp)) { //loop until end of file is reached
        read_password_entry(fp, &p);
        if(!feof(fp)) { //avoid displaying last entry twice
            printf("Website: %s\nUsername: %s\nPassword: %s\n\n", p.website, p.username, p.password);
        }
    }
}

int main() {
    FILE *fp;
    char file_name[] = "passwords.dat";
    char password[] = "pa55word"; //set a master password
    char input_password[20];

    fp = fopen(file_name, "rb+"); //open file for reading and writing, in binary format
    if(fp == NULL) { //file does not exist, create new file and set master password
        printf("Creating new password file...\n");
        fp = fopen(file_name, "wb+");
        if(fp == NULL) {
            printf("Error creating file!\n");
            return 1; //terminate program with error code
        }
        printf("Enter new master password: ");
        scanf("%s", password);
        fwrite(password, strlen(password) + 1, 1, fp);
        printf("Password file created successfully!\n");
    } else { //file exists, prompt for master password
        printf("Enter master password: ");
        scanf("%s", input_password);
        fread(password, strlen(input_password) + 1, 1, fp);
        if(strcmp(input_password, password) != 0) { //wrong password
            printf("Incorrect password! Exiting...\n");
            fclose(fp);
            return 1; //terminate program with error code
        }
        printf("Welcome to the password manager!\n");
    }

    int choice;
    do {
        printf("\n");
        printf("1. Add password entry\n");
        printf("2. Search for password entry\n");
        printf("3. Display all password entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_password_entry(fp);
                break;
            case 2:
                search_password_entry(fp);
                break;
            case 3:
                display_all_password_entries(fp);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    fclose(fp);
    return 0;
}