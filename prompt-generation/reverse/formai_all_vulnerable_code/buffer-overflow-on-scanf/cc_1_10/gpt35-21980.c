//FormAI DATASET v1.0 Category: Password management ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Structure to store password
struct Password{
    char website[50];
    char username[50];
    char password[50];
};

// Function to add new password
void addPassword(struct Password *P, int *n){
    printf("Enter the website name: ");
    scanf("%s",P[*n].website);
    printf("Enter the username: ");
    scanf("%s",P[*n].username);
    printf("Enter the password: ");
    scanf("%s",P[*n].password);
    printf("Password added successfully!\n");
    *n += 1; // Increase the password count
}

// Function to search for a password
int searchPassword(struct Password *P, int n, char *website){
    for(int i=0;i<n;i++){
        if(strcmp(P[i].website,website)==0){
            printf("Website: %s\n",P[i].website);
            printf("Username: %s\n",P[i].username);
            printf("Password: %s\n",P[i].password);
            return i; // Return the index of password found
        }
    }
    printf("Password not found!\n");
    return -1; // Return -1 for password not found
}

// Function to delete a password
void deletePassword(struct Password *P, int *n, char *website){
    int index = searchPassword(P,*n,website);
    if(index==-1)
        return;
    for(int i=index;i<*n-1;i++)
        P[i] = P[i+1]; // Shift elements one place left
    *n -= 1; // Decrease the password count
    printf("Password deleted successfully!\n");
}

// Function to change a password
void changePassword(struct Password *P, int n, char *website){
    int index = searchPassword(P,n,website);
    if(index==-1)
        return;
    printf("Enter the new password: ");
    scanf("%s",P[index].password);
    printf("Password changed successfully!\n");
}

// Function to generate a random password
void generatePassword(char *password){
    srand(time(NULL));
    int len = rand()%8 + 8; // Generate length between 8 and 16
    for(int i=0;i<len;i++){
        int option = rand()%3; // Choose from options: lowercase, uppercase, digit
        if(option==0)
            password[i] = 'a' + rand()%26; // Generate lowercase letter
        else if(option==1)
            password[i] = 'A' + rand()%26; // Generate uppercase letter
        else
            password[i] = '0' + rand()%10; // Generate digit
    }
    password[len] = '\0'; // Terminate the password with null character
}

int main(){
    struct Password passwordList[100]; // Array to store passwords
    int passwordCount = 0; // Counter for number of passwords
    while(1){
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. Search Password\n");
        printf("3. Delete Password\n");
        printf("4. Change Password\n");
        printf("5. Generate Password\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addPassword(passwordList,&passwordCount);
                break;
            case 2:
                printf("Enter the website name: ");
                char website[50];
                scanf("%s",website);
                searchPassword(passwordList,passwordCount,website);
                break;
            case 3:
                printf("Enter the website name: ");
                char website2[50];
                scanf("%s",website2);
                deletePassword(passwordList,&passwordCount,website2);
                break;
            case 4:
                printf("Enter the website name: ");
                char website3[50];
                scanf("%s",website3);
                changePassword(passwordList,passwordCount,website3);
                break;
            case 5:
                printf("The generated password is: ");
                char password[50];
                generatePassword(password);
                printf("%s\n",password);
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}