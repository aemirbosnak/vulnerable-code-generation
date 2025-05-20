//FormAI DATASET v1.0 Category: Password management ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define PASSWORD_FILE "passwords.txt" // file name to store passwords

typedef struct {
    char site[32]; // name of the website or app
    char username[16]; // username for the site or app
    char password[32]; // password for the site or app
} account;

void get_password(char *password){
    char c;
    int count = 0;
    while((c = getchar()) != '\n' && count < 32){ // read user input until newline or max password length
        if(isalnum(c) || ispunct(c)){ // check if character is alphanumeric or a punctuation mark
            password[count++] = c; // add character to password
            putchar('*'); // mask character with asterisk on the console
        }
    }
    password[count] = '\0'; // add null character to terminate string
}

void add_password(){
    account new_account;
    FILE *fp;
    fp = fopen(PASSWORD_FILE, "a"); // open file for appending
    if(fp == NULL){
        printf("Error: could not open file\n");
        return;
    }

    printf("Enter website or app name: ");
    fgets(new_account.site, 32, stdin); // read user input for site name
    printf("Enter username: ");
    fgets(new_account.username, 16, stdin); // read user input for username
    printf("Enter password: ");
    get_password(new_account.password); // get password from user input

    fprintf(fp, "%s:%s:%s\n", new_account.site, new_account.username, new_account.password); // write account details to file in format "site:username:password"
    fclose(fp);
    printf("\nPassword added successfuly.\n");
}

void print_accounts(){
    account curr_account;
    FILE *fp;
    fp = fopen(PASSWORD_FILE, "r"); // open file for reading
    if(fp == NULL){
        printf("Error: could not open file\n");
        return;
    }

    printf("%-32s %-16s %-32s\n", "Site", "Username", "Password"); // print table headers
    printf("------------------------------------------------------------------------------\n");

    while(fscanf(fp, "%[^:]:%[^:]:%[^\n]\n", curr_account.site, curr_account.username, curr_account.password) != EOF){ // read account details from file in format "site:username:password"
        printf("%-32s %-16s %-32s\n", curr_account.site, curr_account.username, curr_account.password); // print account details in table format
    }

    fclose(fp);
}

void search_password(){
    char site[32];
    char c;
    int i=0;
    account curr_account;
    FILE *fp;
    fp = fopen(PASSWORD_FILE, "r"); // open file for reading
    if(fp == NULL){
        printf("Error: could not open file\n");
        return;
    }

    printf("Enter website or app name: ");
    while((c=getchar()) != '\n' && i<32){ // read user input until newline or max site name length
        site[i++] = c;
    }
    site[i] = '\0'; // add null character to terminate string

    while(fscanf(fp, "%[^:]:%[^:]:%[^\n]\n", curr_account.site, curr_account.username, curr_account.password) != EOF){ // read account details from file in format "site:username:password"
        if(strcmp(curr_account.site, site) == 0){ // check if site name matches
            printf("\nSite: %s\nUsername: %s\nPassword: %s\n", curr_account.site, curr_account.username, curr_account.password); // print account details
            fclose(fp);
            return;
        }
    }

    printf("\nSite not found.\n");
    fclose(fp);
}

void delete_password(){
    char site[32];
    char c;
    int i=0;
    account curr_account;
    FILE *fp1, *fp2;
    fp1 = fopen(PASSWORD_FILE, "r"); // open file for reading
    if(fp1 == NULL){
        printf("Error: could not open file\n");
        return;
    }
    fp2 = fopen("temp.txt", "w"); // open temp file for writing
    if(fp2 == NULL){
        printf("Error: could not open file\n");
        fclose(fp1);
        return;
    }

    printf("Enter website or app name: ");
    while((c=getchar()) != '\n' && i<32){ // read user input until newline or max site name length
        site[i++] = c;
    }
    site[i] = '\0'; // add null character to terminate string

    while(fscanf(fp1, "%[^:]:%[^:]:%[^\n]\n", curr_account.site, curr_account.username, curr_account.password) != EOF){ // read account details from file in format "site:username:password"
        if(strcmp(curr_account.site, site) != 0){ // check if site name doesn't match
            fprintf(fp2, "%s:%s:%s\n", curr_account.site, curr_account.username, curr_account.password); // write account details to temp file
        }
    }

    fclose(fp1);
    fclose(fp2);
    remove(PASSWORD_FILE); // remove old password file
    rename("temp.txt", PASSWORD_FILE); // rename temp file
    printf("\nPassword deleted successfully.\n");
}

void update_password(){
    char site[32];
    char c;
    int i=0;
    account curr_account;
    FILE *fp1, *fp2;
    fp1 = fopen(PASSWORD_FILE, "r"); // open file for reading
    if(fp1 == NULL){
        printf("Error: could not open file\n");
        return;
    }
    fp2 = fopen("temp.txt", "w"); // open temp file for writing
    if(fp2 == NULL){
        printf("Error: could not open file\n");
        fclose(fp1);
        return;
    }

    printf("Enter website or app name: ");
    while((c=getchar()) != '\n' && i<32){ // read user input until newline or max site name length
        site[i++] = c;
    }
    site[i] = '\0'; // add null character to terminate string

    while(fscanf(fp1, "%[^:]:%[^:]:%[^\n]\n", curr_account.site, curr_account.username, curr_account.password) != EOF){ // read account details from file in format "site:username:password"
        if(strcmp(curr_account.site, site) == 0){ // check if site name matches
            printf("\nEnter new username or leave blank to keep current username (%s): ", curr_account.username);
            fgets(curr_account.username, 16, stdin); // read user input for new username
            printf("Enter new password or leave blank to keep current password: ");
            get_password(curr_account.password); // get password from user input
            fprintf(fp2, "%s:%s:%s\n", curr_account.site, curr_account.username, curr_account.password); // write updated account details to temp file
            printf("\nPassword updated successfully.\n");
        }
        else{
            fprintf(fp2, "%s:%s:%s\n", curr_account.site, curr_account.username, curr_account.password); // write unchanged account details to temp file
        }
    }

    fclose(fp1);
    fclose(fp2);
    remove(PASSWORD_FILE); // remove old password file
    rename("temp.txt", PASSWORD_FILE); // rename temp file
}

int main(){
    int choice;

    printf("C Password Manager\n");
    printf("-------------------\n");

    while(1){
        printf("\nPlease choose an option:\n");
        printf("1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Search for password\n");
        printf("4. Delete password\n");
        printf("5. Update password\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_password();
                break;
            case 2:
                print_accounts();
                break;
            case 3:
                search_password();
                break;
            case 4:
                delete_password();
                break;
            case 5:
                update_password();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}