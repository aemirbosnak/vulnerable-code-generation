//FormAI DATASET v1.0 Category: Password management ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_USER 10
#define MAX_PASSWD 20

/* Structure for User Information */
struct user_info
{
    char username[MAX_USER];
    char password[MAX_PASSWD];
};

/* Function to display menu */
void menu()
{
    printf("***********Password Management***********\n");
    printf("1. Create New User Account.\n");
    printf("2. Login with Existing Account.\n");
    printf("3. Change Password.\n");
    printf("4. Exit.\n");
    printf("Enter your choice: ");
}

/* Function to create new user account */
void create_new_user(struct user_info *users, int *num_users)
{
    if(*num_users < MAX_USER)
    {
        printf("\nEnter username: ");
        scanf("%s", users[*num_users].username);

        printf("Enter password: ");
        scanf("%s", users[*num_users].password);

        (*num_users)++;
        printf("\nNew User Account created successfully!\n\n");
    }
    else
    {
        printf("\nMaximum number of users reached.\n\n");
    }
}

/* Function to authenticate user login */
int login(struct user_info *users, int num_users)
{
    char username[MAX_USER], password[MAX_PASSWD];
    int i;

    printf("\nEnter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for(i=0; i<num_users; i++)
    {
        if(strcmp(users[i].username, username)==0 && strcmp(users[i].password, password)==0)
        {
            printf("\nLogin Successful!\n\n");
            return i;
        }
    }

    printf("\nInvalid username or password.\n\n");
    return -1;
}

/* Function to change password */
void change_password(struct user_info *users, int num_users, int current_user)
{
    char new_password[MAX_PASSWD];

    printf("\nEnter new password: ");
    scanf("%s", new_password);

    strcpy(users[current_user].password, new_password);

    printf("\nPassword changed successfully!\n\n");
}

int main()
{
    struct user_info users[MAX_USER];
    int num_users = 0, choice, current_user = -1;

    while(1)
    {
        menu();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create_new_user(users, &num_users);
                break;
            case 2:
                current_user = login(users, num_users);
                break;
            case 3:
                if(current_user != -1)
                    change_password(users, num_users, current_user);
                else
                    printf("\nYou need to login to change password.\n\n");
                break;
            case 4:
                printf("\nThank you for using Password Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    }

    return 0;
}