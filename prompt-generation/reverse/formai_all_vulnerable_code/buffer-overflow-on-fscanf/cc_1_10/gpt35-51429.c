//FormAI DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

#define MAX_PASSWORDS 100 

struct password { 
    char site_name[50]; 
    char username[50]; 
    char password[50]; 
}; 

struct password password_list[MAX_PASSWORDS]; 
int num_passwords = 0; 

void add_password() { 
    struct password new_password; 
    printf("Enter site name: "); 
    scanf("%s", new_password.site_name); 
    printf("Enter username: "); 
    scanf("%s", new_password.username); 
    printf("Enter password: "); 
    scanf("%s", new_password.password); 

    password_list[num_passwords] = new_password; 
    num_passwords++; 
} 

void search_password() { 
    char site_name[50]; 
    printf("Enter site name to search for: "); 
    scanf("%s", site_name); 

    for(int i = 0; i < num_passwords; i++) { 
        if(strcmp(password_list[i].site_name, site_name) == 0) { 
            printf("Site name: %s\n", password_list[i].site_name); 
            printf("Username: %s\n", password_list[i].username); 
            printf("Password: %s\n", password_list[i].password); 
            return; 
        } 
    } 

    printf("No password found for site %s\n", site_name); 
} 

void list_passwords() { 
    printf("Site Name\tUsername\tPassword\n"); 
    printf("----------------------------------------------------------\n"); 
    for(int i = 0; i < num_passwords; i++) { 
        printf("%s\t%s\t%s\n", password_list[i].site_name, password_list[i].username, password_list[i].password); 
    } 
} 

void save_passwords() { 
    FILE *fp; 
    fp = fopen("passwords.txt", "w"); 

    fprintf(fp, "%d\n", num_passwords); 

    for(int i = 0; i < num_passwords; i++) { 
        fprintf(fp, "%s\n", password_list[i].site_name); 
        fprintf(fp, "%s\n", password_list[i].username); 
        fprintf(fp, "%s\n", password_list[i].password); 
    } 

    fclose(fp); 

    printf("Passwords saved to file.\n"); 
} 

void load_passwords() { 
    FILE *fp; 
    fp = fopen("passwords.txt", "r"); 

    if(fp == NULL) { 
        printf("No saved passwords found.\n"); 
        return; 
    } 

    fscanf(fp, "%d\n", &num_passwords); 

    for(int i = 0; i < num_passwords; i++) { 
        fscanf(fp, "%s\n", password_list[i].site_name); 
        fscanf(fp, "%s\n", password_list[i].username); 
        fscanf(fp, "%s\n", password_list[i].password); 
    } 

    fclose(fp); 

    printf("Passwords loaded from file.\n"); 
} 

int main() { 
    int option; 

    printf("Password Manager\n"); 

    while(1) { 
        printf("\nSelect an option:\n"); 
        printf("1. Add password\n"); 
        printf("2. Search for password\n"); 
        printf("3. List all passwords\n"); 
        printf("4. Save passwords to file\n"); 
        printf("5. Load passwords from file\n"); 
        printf("6. Exit\n\n"); 

        scanf("%d", &option); 

        switch(option) { 
            case 1: 
                add_password(); 
                break; 
            case 2: 
                search_password(); 
                break; 
            case 3: 
                list_passwords(); 
                break; 
            case 4: 
                save_passwords(); 
                break; 
            case 5: 
                load_passwords(); 
                break; 
            case 6: 
                printf("Exiting...\n"); 
                exit(0); 
            default: 
                printf("Invalid option. Please try again.\n"); 
                break; 
        } 
    } 

    return 0; 
}