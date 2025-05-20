//FormAI DATASET v1.0 Category: Password management ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 1000000
 
struct password_data {
    char website[100];
    char username[50];
    char password[50];
};
 
struct password_data passwords[MAX];// defining structure to store password data
 
int count = 0;
char temp[100];// temporary variable to store user input
 
void add_password() {
    struct password_data new_password;
    printf("\nEnter website name:\n");
    scanf("%s", new_password.website);
    printf("\nEnter username:\n");
    scanf("%s", new_password.username);
    printf("\nEnter password:\n");
    scanf("%s", new_password.password);
    passwords[count] = new_password;
    count++;
    printf("\nPassword added successfully!\n");
}
 
void view_password() {
    char website_name[100];
    printf("\nEnter website name:\n");
    scanf("%s", website_name);
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(passwords[i].website, website_name) == 0) {
            printf("\nWebsite Name: %s", passwords[i].website);
            printf("\nUsername: %s", passwords[i].username);
            printf("\nPassword: %s", passwords[i].password);
            found = 1;
        }  
    }
    if(found == 0) {
        printf("\nNo password found for given website name!\n");
    }
}
 
void generate_password() {
    int length;
    printf("\nEnter length of password you want to generate:\n");
    scanf("%d", &length);
    srand(time(0));
    char password[length+1];
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+{}[];:'<>,.?/|";
    int charset_length = strlen(charset);
    for(int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_length];
    }
    password[length] = '\0';
    printf("\nGenerated Password: %s\n", password);
}
 
void shape_shift() { //shaping into a new look
    printf("\n------------------------------------------------------\n");
    printf("\nWelcome to the Password Manager Program!\n");
    printf("\n------------------------------------------------------\n");
    printf("\nPlease choose an option from the menu:\n");
    printf("1. Add a Password\n");
    printf("2. View a Password\n");
    printf("3. Generate Password\n-");
    int option;
    scanf("%d", &option);
    switch(option) {
        case 1: add_password();
                break;
        case 2: view_password();
                break;
        case 3: generate_password();
                break;
        default: printf("\nInvalid option!\n");
    }
    printf("\nDo you want to continue? (y/n):\n");
    char choice;
    scanf(" %c", &choice);
    if(choice == 'y' || choice == 'Y') {
        shape_shift(); //recursive call for shaping
    }
    else {
        printf("\nExiting Program!\n");
    }
}
 
int main() {
    shape_shift(); //program starts with shape_shift function
    return 0;
}