//FormAI DATASET v1.0 Category: Password management ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define DATAFILE "passwords.txt"

typedef struct Pass{
    char website[MAX];
    char username[MAX];
    char password[MAX];
}Password;

void addPassword(Password p);
void printPasswords();
void searchPasswords(char *website);

int main(){
    char c;
    Password p;
    int choice;
    
    do{
        printf("\n\n\t\tWelcome to Password Management System\n");
        printf("\t\t------------------------------------\n");
        printf("\n\t1. View Passwords");
        printf("\n\t2. Add Password");
        printf("\n\t3. Search Password");
        printf("\n\t4. Exit");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: printPasswords();
                    break;
            case 2: printf("\n\tEnter website: ");
                    scanf("%s", p.website);
                    printf("\n\tEnter username: ");
                    scanf("%s", p.username);
                    printf("\n\tEnter password: ");
                    scanf("%s", p.password);
                    addPassword(p);
                    break;
            case 3: printf("\n\tEnter website to search: ");
                    char website[MAX];
                    scanf("%s", website);
                    searchPasswords(website);
                    break;
            case 4: printf("\nYou chose to exit the program");
                    break;
            default: printf("\nInvalid choice.");
        }
        
        printf("\nDo you wish to continue? (y/n): ");
        c = getchar();
    }while(c == 'y' || c == 'Y');   
    
    return 0;
}

void addPassword(Password p){
    FILE *fp;
    fp = fopen(DATAFILE, "ab");
    if(fp == NULL){
        printf("\nError opening file!");
        return;
    }
    
    fwrite(&p, sizeof(Password), 1, fp);
    printf("\nPassword added successfully!");
    fclose(fp);
}

void printPasswords(){
    FILE *fp;
    fp = fopen(DATAFILE, "rb");
    if(fp == NULL){
        printf("\nError opening file!");
        return;
    }
    
    Password p;
    printf("\n\tWebsite\t\tUsername\tPassword\n");
    while(fread(&p, sizeof(Password), 1, fp)){
        printf("\n\t%s\t%s\t%s", p.website, p.username, p.password);
    }
    
    fclose(fp);
}

void searchPasswords(char *website){
    FILE *fp;
    fp = fopen(DATAFILE, "rb");
    if(fp == NULL){
        printf("\nError opening file!");
        return;
    }
    
    Password p;
    int found = 0;
    while(fread(&p, sizeof(Password), 1, fp)){
        if(strcmp(p.website, website) == 0){
            printf("\n\tWebsite\t\tUsername\tPassword\n");
            printf("\n\t%s\t%s\t%s", p.website, p.username, p.password);
            found = 1;
            break;
        }
    }
    
    if(!found){
        printf("\n\tNo matching record found.");
    }
    
    fclose(fp);
}