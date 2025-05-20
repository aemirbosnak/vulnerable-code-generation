//FormAI DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_MAX_LEN 16
#define MASTER_PASS "thisismymasterpassword"

typedef struct password {
    char site_name[25];
    char username[25];
    char password[PASSWORD_MAX_LEN+1];
} Password;

void print_password(Password p) {
    printf("\nSite Name: %s\n", p.site_name);
    printf("Username: %s\n", p.username);
    printf("Password: %s\n", p.password);
}

void encrypt(char* password, char* key) {
    int i;
    for(i = 0; i < strlen(password); i++) {
        password[i] ^= key[i % strlen(key)];
    }
}

void add_password(char* master_pass) {
    char site_name[25], username[25], password[PASSWORD_MAX_LEN+1];
    Password p;
    printf("\nEnter Site Name: ");
    scanf(" %[^\n]", site_name);
    printf("Enter Username: ");
    scanf(" %[^\n]", username);
    printf("Enter Password: ");
    scanf(" %[^\n]", password);
    strcpy(p.site_name, site_name);
    strcpy(p.username, username);
    encrypt(password, master_pass);
    strcpy(p.password, password);
    FILE *fp = fopen("passwords.dat", "ab");
    if(fp == NULL) {
        printf("Error in opening file for writing");
        exit(1);
    }
    fwrite(&p, sizeof(Password), 1, fp);
    fclose(fp);
    printf("\nPassword added successfully!\n");
}

void view_passwords(char* master_pass) {
    Password p;
    FILE *fp = fopen("passwords.dat", "rb");
    if(fp == NULL) {
        printf("No passwords found!\n");
        return;
    }
    printf("\nSaved Passwords:\n");
    while(fread(&p, sizeof(Password), 1, fp)) {
        char passwd[PASSWORD_MAX_LEN+1];
        strcpy(passwd, p.password);
        encrypt(passwd, master_pass);
        strcpy(p.password, passwd);
        print_password(p);
    }
    fclose(fp);
}

void search_password(char* master_pass) {
    char site_name[25];
    Password p;
    int found = 0;
    printf("\nEnter site name to search: ");
    scanf(" %[^\n]", site_name);
    FILE *fp = fopen("passwords.dat", "rb");
    if(fp == NULL) {
        printf("No passwords found!\n");
        return;
    }
    while(fread(&p, sizeof(Password), 1, fp)) {
        if(strcmp(p.site_name, site_name) == 0) {
            char passwd[PASSWORD_MAX_LEN+1];
            strcpy(passwd, p.password);
            encrypt(passwd, master_pass);
            strcpy(p.password, passwd);
            print_password(p);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if(!found) printf("\nSite not found!\n");
}

void delete_password(char* master_pass) {
    char site_name[25];
    Password p;
    int found = 0;
    printf("\nEnter site name to delete: ");
    scanf(" %[^\n]", site_name);
    FILE *fp = fopen("passwords.dat", "rb");
    if(fp == NULL) {
        printf("No passwords found!\n");
        return;
    }
    FILE *temp = fopen("temp.dat", "wb");
    if(temp == NULL) {
        printf("Error in opening temporary file");
        exit(1);
    }
    while(fread(&p, sizeof(Password), 1, fp)) {
        if(strcmp(p.site_name, site_name) != 0) {
            fwrite(&p, sizeof(Password), 1, temp);
        }
        else {
            char passwd[PASSWORD_MAX_LEN+1];
            strcpy(passwd, p.password);
            encrypt(passwd, master_pass);
            if(strcmp(passwd, MASTER_PASS) == 0) {
                printf("\nSorry, cannot delete password for master password!\n");
                found = 1;
                break;
            }
            else {
                printf("\nPassword for site '%s' deleted successfully!\n", p.site_name);
                found = 1;
            }
        }
    }
    fclose(fp);
    fclose(temp);
    if(!found) printf("\nSite not found!\n");
    else {
        remove("passwords.dat");
        rename("temp.dat", "passwords.dat");
    }
}

int main() {
    char master_pass_input[25];
    system("clear");
    printf("\n\n************************************************************\n\n");
    printf("\t  C PASSWORD MANAGER\n");
    printf("\n\n************************************************************\n\n");
    printf("Enter Master Password: ");
    scanf(" %[^\n]", master_pass_input);
    if(strcmp(master_pass_input, MASTER_PASS) != 0) {
        printf("\nWrong password!\n");
        return 0;
    }
    while(1) {
        int choice;
        printf("\n1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Search Password\n");
        printf("4. Delete Password\n");
        printf("5. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_password(MASTER_PASS); break;
            case 2: view_passwords(MASTER_PASS); break;
            case 3: search_password(MASTER_PASS); break;
            case 4: delete_password(MASTER_PASS); break;
            case 5: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}