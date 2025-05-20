//FormAI DATASET v1.0 Category: Password management ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function definitions
void addPassword();
void viewPasswords();
void searchPassword();
void deletePassword();
void updatePassword();
void menu();

//Data structure to hold password details
struct password{
    char website[50];
    char username[20];
    char password[20];
    char email[50];
};

//Global variables
int n=0;  //Number of passwords
struct password passwords[50];

int main(){
    menu();   //Calling the menu function
    return 0;
}

void menu(){
    int choice;
    while(1){   //Infinite loop to keep the menu running
        printf("\n---------------------------\n");
        printf("PASSWORD MANAGER\n");
        printf("---------------------------\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Search Password\n");
        printf("4. Delete Password\n");
        printf("5. Update Password\n");
        printf("6. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: addPassword();   //Calling addPassword function
                    break;
            case 2: viewPasswords();   //Calling viewPasswords function
                    break;
            case 3: searchPassword();   //Calling searchPassword function
                    break;
            case 4: deletePassword();   //Calling deletePassword function
                    break;
            case 5: updatePassword();   //Calling updatePassword function
                    break;
            case 6: printf("Exiting program...\n");   //Exiting program
                    exit(0);
            default: printf("Invalid choice, please choose again\n");
                     break;
        }
    }
}

//Function to add a new password to the data structure
void addPassword(){
    printf("\nEnter the details of the password:\n");
    printf("Website: ");
    scanf("%s", passwords[n].website);
    printf("Username: ");
    scanf("%s", passwords[n].username);
    printf("Password: ");
    scanf("%s", passwords[n].password);
    printf("Email: ");
    scanf("%s", passwords[n].email);
    printf("\nPassword added successfully!\n");
    n++;
}

//Function to view all the passwords in the data structure
void viewPasswords(){
    if(n==0){
        printf("\nNo passwords found!\n");
        return;
    }
    printf("\n---------------------------\n");
    printf("WEBSITE\t\tUSERNAME\n");
    printf("---------------------------\n");
    for(int i=0; i<n; i++){
        printf("%s\t\t%s\n", passwords[i].website, passwords[i].username);
    }
    printf("---------------------------\n");
    printf("Total passwords: %d\n",n);
}

//Function to search for a particular password in the data structure
void searchPassword(){
    if(n==0){
        printf("\nNo passwords found!\n");
        return;
    }
    char website[50];
    printf("\nEnter the website to search for: ");
    scanf("%s", website);
    int flag = 0;
    for(int i=0; i<n; i++){
        if(strcmp(passwords[i].website, website)==0){
            printf("\n---------------------------\n");
            printf("WEBSITE: %s\n", passwords[i].website);
            printf("USERNAME: %s\n", passwords[i].username);
            printf("PASSWORD: %s\n", passwords[i].password);
            printf("EMAIL: %s\n", passwords[i].email);
            printf("---------------------------\n");
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("\nPassword not found!\n");
    }
}

//Function to delete a particular password from the data structure
void deletePassword(){
    if(n==0){
        printf("\nNo passwords found!\n");
        return;
    }
    char website[50];
    printf("\nEnter the website to delete the password: ");
    scanf("%s", website);
    int flag = 0;
    for(int i=0; i<n; i++){
        if(strcmp(passwords[i].website, website)==0){
            for(int j=i; j<n-1; j++){
                passwords[j] = passwords[j+1];
            }
            n--;
            flag = 1;
            printf("\nPassword deleted successfully!\n");
            break;
        }
    }
    if(flag==0){
        printf("\nPassword not found!\n");
    }
}

//Function to update a particular password in the data structure
void updatePassword(){
    if(n==0){
        printf("\nNo passwords found!\n");
        return;
    }
    char website[50];
    printf("\nEnter the website to update the password: ");
    scanf("%s", website);
    int flag = 0;
    for(int i=0; i<n; i++){
        if(strcmp(passwords[i].website, website)==0){
            printf("\nEnter the updated details:\n");
            printf("Website: ");
            scanf("%s", passwords[i].website);
            printf("Username: ");
            scanf("%s", passwords[i].username);
            printf("Password: ");
            scanf("%s", passwords[i].password);
            printf("Email: ");
            scanf("%s", passwords[i].email);
            printf("\nPassword updated successfully!\n");
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("\nPassword not found!\n");
    }
}