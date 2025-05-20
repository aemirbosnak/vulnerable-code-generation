//FormAI DATASET v1.0 Category: Password management ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct password{
    char siteName[50], username[30], password[30];
};

void addPassword();
void viewPasswords();
void searchPassword();

//to encrypt the password
char *encrypt(char *str)
{
    int len = strlen(str);
    char *encr = malloc(len * sizeof(char));
    for(int i=0; i<len; i++){
        encr[i] = str[i] + 1; //shift every character by 1
    }
    encr[len] = '\0';
    return encr;
}

//to decrypt the password
char *decrypt(char *str)
{
    int len = strlen(str);
    char *decr = malloc(len * sizeof(char));
    for(int i=0; i<len; i++){
        decr[i] = str[i] - 1; //shift every character back by 1
    }
    decr[len] = '\0';
    return decr;
}

void addPassword(){
    FILE *fp;
    fp = fopen("passwords.txt", "a");

    struct password p;

    printf("\nEnter Site Name: ");
    scanf("%s", p.siteName);

    printf("\nEnter Username: ");
    scanf("%s", p.username);

    printf("\nEnter Password: ");
    scanf("%s", p.password);

    //encrypt the password before storing
    strcpy(p.password, encrypt(p.password));
    
    fprintf(fp, "%s %s %s\n", p.siteName, p.username, p.password);
    printf("\nPassword added successfully!\n");

    fclose(fp);
}

void viewPasswords(){
    FILE *fp;
    fp = fopen("passwords.txt", "r");

    char ch = fgetc(fp);
    while(ch != EOF){
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);
}

void searchPassword(){
    FILE *fp;
    fp = fopen("passwords.txt", "r");

    char siteName[MAX];
    printf("\nEnter Site Name to search: ");
    scanf("%s", siteName);

    struct password p;
    int found = 0;
    while(fscanf(fp, "%s %s %s", p.siteName, p.username, p.password) != EOF){
        if(strcmp(p.siteName, siteName) == 0){
            printf("\nSite Name: %s\nUsername: %s\nPassword: %s\n", p.siteName, p.username, decrypt(p.password));
            found = 1;
            break;
        }
    }
    if(!found){
        printf("\nNo Passwords found for the given site name.\n");
    }
    fclose(fp);
}

int main(){
    int choice;

    do{
        printf("\n\nPassword Manager\n");
        printf("==============================================\n\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Search Password\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                searchPassword();
                break;
            case 4:
                printf("\nExiting Password Manager\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    }while(1);

    return 0;
}