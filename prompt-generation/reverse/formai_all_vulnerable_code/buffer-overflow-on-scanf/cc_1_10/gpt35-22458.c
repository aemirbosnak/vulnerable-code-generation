//FormAI DATASET v1.0 Category: Password management ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct password_store{
    char website[50];
    char username[50];
    char password[50];
};

void add_password(struct password_store db[], int *count);   //prototype
void view_passwords(struct password_store db[], int count);   //prototype
void search_password(struct password_store db[], int count);  //prototype
void encrypt_decrypt(char *password, int key);        //prototype
void clear_input_buffer();                           //prototype 
void password_strength(char *password);              //prototype 
int check_username(char *username);                  //prototype
void clear_screen();                                 //prototype

int main()
{
    int choice, count=0;
    struct password_store db[50];
    clear_screen();
    printf("Password Manager\n");
    printf("=================\n\n");
    do
    {
        printf("1) Add password\n");
        printf("2) View passwords\n");
        printf("3) Search for password\n");
        printf("4) Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();
        switch(choice)
        {
            case 1:
                add_password(db, &count);
                printf("\nPress Enter to continue...");
                getchar();
                clear_screen(); 
                break;
            case 2:
                view_passwords(db, count);
                printf("\nPress Enter to continue...");
                getchar();
                clear_screen(); 
                break;
            case 3:
                search_password(db, count);
                printf("\nPress Enter to continue...");
                getchar();
                clear_screen(); 
                break;
            case 4:
                printf("\nThanks for using Password Manager!");
                break;
            default:
                printf("\nInvalid choice! Please try again.");
                printf("\nPress Enter to continue...");
                getchar();
                clear_screen(); 
                break;
        }
    }while(choice!=4);

    return 0;
}

void add_password(struct password_store db[], int *count)
{
    char pw[50], username[50];
    printf("\nEnter website (without spaces): ");
    scanf("%s", db[*count].website);
    clear_input_buffer();
    printf("\nEnter username (without spaces): ");
    scanf("%[^\n]s", db[*count].username);
    clear_input_buffer();
    if(check_username(db[*count].username) == 0){
        printf("\nThe username can only contain alphabets and numeric characters.");
        printf("\nAn entry for %s cannot be added. Press Enter to continue...", db[*count].website);
        clear_input_buffer();
        return;
    }
    printf("\nEnter password (must contain at least 8 characters): ");
    scanf("%[^\n]s", pw);
    clear_input_buffer();
    password_strength(pw);
    printf("\nEncrypting password...");
    encrypt_decrypt(pw, 5);
    strcpy(db[*count].password, pw);
    printf("\nPassword added successfully!");
    (*count)++;
}

void view_passwords(struct password_store db[], int count)
{  
    if(count == 0){
        printf("\nThere are no passwords stored yet.");
        return;
    }
    printf("\nWebsite\tUsername\tPassword\n");
    for(int i=0; i<count; i++)
    {
        printf("%s\t%s\t\t%s\n", db[i].website, db[i].username, db[i].password);
    }
}

void search_password(struct password_store db[], int count)
{
    if(count == 0){
        printf("\nThere are no passwords stored yet.");
        return;
    }
    char website[50];
    printf("\nEnter website to search for (without spaces): ");
    scanf("%s", website);
    clear_input_buffer();
    for(int i=0; i<count; i++)
    {
        if(strcmp(website, db[i].website) == 0){
            printf("\nWebsite\tUsername\tPassword\n");
            printf("%s\t%s\t\t%s\n", db[i].website, db[i].username, db[i].password);
            return;
        }
    }
    printf("\nAn entry for %s was not found.", website);
}

void password_strength(char *password)
{
    int upper=0, lower=0, digit=0;
    for(int i=0; i<strlen(password); i++)
    {
        if(isupper(password[i])) upper++;
        else if(islower(password[i])) lower++;
        else if(isdigit(password[i])) digit++;
    }
    if(upper==0 || lower==0 || digit==0 || strlen(password)<8)
    {
        printf("\nA strong password should contain at least one uppercase letter, one lowercase letter, one digit, and must be at least 8 characters long.");
    }
}

void encrypt_decrypt(char *password, int key)
{
    for(int i=0; i<strlen(password); i++)
    {
        if(isalpha(password[i]))
        {
            if(isupper(password[i]))
                password[i] = (((password[i] - 'A') + key) % 26) + 'A';
            else
                password[i] = (((password[i] - 'a') + key) % 26) + 'a';    
        }
    }
}

void clear_input_buffer()
{
    while(getchar()!='\n');
}

int check_username(char *username)
{
    for(int i=0; i<strlen(username); i++)
    {
        if(!isalnum(username[i]))
            return 0;
    }
    return 1;
}

void clear_screen()
{
    system("cls||clear");
}