//FormAI DATASET v1.0 Category: Password management ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void addPassword();
void viewPasswords();
void deletePassword();

struct Password{
    char website[100];
    char username[100];
    char password[100];
};

int main(){
    int choice;
    printf("My darling, would you like to:\n1. Add a new password\n2. View all saved passwords\n3. Delete a saved password\n");
    printf("Please enter your choice, my love: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            addPassword();
            printf("Your password has been saved, my precious.\n");
            break;
        case 2:
            viewPasswords();
            break;
        case 3:
            deletePassword();
            printf("Your password has been deleted, my love.\n");
            break;
        default:
            printf("Invalid choice, my love. Please select a valid option.\n");
            break;
    }
    return 0;
}

void addPassword(){
    struct Password password;
    FILE *fp;
    fp = fopen("password.txt", "a+");
    
    printf("Please enter the website name, my love: ");
    scanf("%s", password.website);
    fprintf(fp, "Website Name: %s\n", password.website);
    
    printf("Please enter your username, my darling: ");
    scanf("%s", password.username);
    fprintf(fp, "Username: %s\n", password.username);
    
    printf("Please enter your password, my heart: ");
    scanf("%s", password.password);
    fprintf(fp, "Password: %s\n", password.password);
    
    fclose(fp);
}

void viewPasswords(){
    FILE *fp;
    fp = fopen("password.txt", "r");
    char ch = fgetc(fp);
    while(ch != EOF){
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);
}

void deletePassword(){
    char website[100];
    printf("Please enter the website name of the password you want to delete, my love: ");
    scanf("%s", website);
    
    FILE *fp, *temp;
    fp = fopen("password.txt", "r");
    temp = fopen("temp.txt", "w");
    
    char ch = fgetc(fp);
    int flag = 0;
    while(ch != EOF){
        if(ch == 'W'){ // W for Website Name. This checks that the website name is being checked and deleted
            char tempWebsite[100];
            fscanf(fp, "%s", tempWebsite);
            if(strcmp(website, tempWebsite) == 0){
                flag = 1;
                char tempCh = fgetc(fp);
                while(tempCh != '\n'){
                    tempCh = fgetc(fp);
                }
            }
            else{
                fprintf(temp, "Website Name: %s\n", tempWebsite);
            }
        }
        else{
            fprintf(temp, "%c", ch);
        }
        ch = fgetc(fp);
    }
    fclose(fp);
    fclose(temp);
    remove("password.txt");
    rename("temp.txt", "password.txt");
    if(flag == 0){
        printf("Sorry, my love. No password found for this website name.\n");
    }
}