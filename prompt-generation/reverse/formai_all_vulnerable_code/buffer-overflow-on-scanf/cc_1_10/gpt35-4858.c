//FormAI DATASET v1.0 Category: Password management ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct password{
    char website[50];
    char password[50];
};

void addPassword(struct password *pswd, int *numPasswords);
void viewPasswords(struct password *pswd, int numPasswords);
void savePasswords(struct password *pswd, int numPasswords);
void loadPasswords(struct password *pswd, int *numPasswords);
void encrypt(char *str);
void decrypt(char *str);

int main(){
    struct password passwords[50];
    int numPasswords = 0;
    char choice;

    loadPasswords(passwords, &numPasswords);

    printf("Welcome to Password Manager!\n");

    do{
        printf("\nSelect an option:\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Save passwords\n");
        printf("4. Exit\n");
        scanf(" %c", &choice);

        switch(choice){
            case '1':
                addPassword(passwords, &numPasswords);
                break;
            case '2':
                viewPasswords(passwords, numPasswords);
                break;
            case '3':
                savePasswords(passwords, numPasswords);
                break;
            case '4':
                printf("Thank you for using Password Manager!\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    }while(choice!='4');

    return 0;
}

void addPassword(struct password *pswd, int *numPasswords){
    char website[50];
    char unencryptedPassword[50];
    char encryptedPassword[50];

    printf("Enter website name: ");
    scanf(" %[^\n]", website);

    printf("Enter password: ");
    scanf(" %[^\n]", unencryptedPassword);
    encrypt(unencryptedPassword);
    strcpy(pswd[*numPasswords].password, unencryptedPassword);

    strcpy(pswd[*numPasswords++].website, website);

    printf("Password added successfully!\n");
}

void viewPasswords(struct password *pswd, int numPasswords){
    if(numPasswords == 0){
        printf("No passwords added yet.\n");
    }else{
        for(int i=0;i<numPasswords;i++){
            char decryptedPassword[50];
            strcpy(decryptedPassword, pswd[i].password);
            decrypt(decryptedPassword);
            printf("%s: %s\n", pswd[i].website, decryptedPassword);
        }
    }
}

void savePasswords(struct password *pswd, int numPasswords){
    FILE *fp;

    fp = fopen("passwords.txt", "w");

    if(fp == NULL){
        printf("Error saving passwords.\n");
    }else{
        fprintf(fp, "%d\n", numPasswords);

        for(int i=0;i<numPasswords;i++){
            fprintf(fp, "%s,%s\n", pswd[i].website, pswd[i].password);
        }

        fclose(fp);

        printf("Passwords saved successfully!\n");
    }
}

void loadPasswords(struct password *pswd, int *numPasswords){
    FILE *fp;
    int numPwds;

    fp = fopen("passwords.txt", "r");

    if(fp == NULL){
        printf("No saved passwords found.\n");
    }else{
        fscanf(fp, "%d", &numPwds);
        *numPasswords = numPwds;

        for(int i=0;i<numPwds;i++){
            fscanf(fp, " %[^,],%s", pswd[i].website, pswd[i].password);
        }

        fclose(fp);

        printf("%d passwords loaded successfully!\n", numPwds);
    }
}

void encrypt(char *str){
    for(int i=0;i<strlen(str);i++){
        str[i] += 3;
    }
}

void decrypt(char *str){
    for(int i=0;i<strlen(str);i++){
        str[i] -= 3;
    }
}