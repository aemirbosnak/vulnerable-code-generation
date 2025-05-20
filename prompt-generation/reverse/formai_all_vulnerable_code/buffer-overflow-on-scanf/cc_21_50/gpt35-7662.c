//FormAI DATASET v1.0 Category: Password management ; Style: authentic
#include<stdio.h>
#include<string.h>

//Structure to hold the password and username of a user
struct password
{
    char user_name[20];
    char pass_word[20];
};

int main()
{
    struct password user[5]; //Array of 5 users to store their details
    int option, i, flag, j; //Variables to hold user input and loop conditions
    char input[20]; //Variable to hold user input for login
    
    //Loop to get user input for storing usernames and passwords
    for(i=0;i<5;i++)
    {
        printf("\nEnter username of user %d: ",i+1);
        scanf("%s",user[i].user_name);
        
        //Loop to check if the entered password is strong enough
        do
        {
            flag=1;
            printf("Enter a password (At least 5 characters and should include one uppercase, one lowercase and one number): ");
            scanf("%s",user[i].pass_word);
            
            //Loop to check if password meets criteria
            for(j=0;j<strlen(user[i].pass_word);j++)
            {
                if(user[i].pass_word[j]>='A' && user[i].pass_word[j]<='Z') //Checking uppercase
                {
                    flag++;
                    break;
                }
            }
            
            for(j=0;j<strlen(user[i].pass_word);j++)
            {
                if(user[i].pass_word[j]>='a' && user[i].pass_word[j]<='z') //Checking lowercase
                {
                    flag++;
                    break;
                }
            }
            
            for(j=0;j<strlen(user[i].pass_word);j++)
            {
                if(user[i].pass_word[j]>='0' && user[i].pass_word[j]<='9') //Checking number
                {
                    flag++;
                    break;
                }
            }
            
            if(flag!=4 || strlen(user[i].pass_word)<5) //Checking if all three criteria are met
            {
                printf("Password is weak. Please try again.\n");
                flag=1;
            }
        }while(flag!=4);
    }
    
    //Loop to display options for login or exit
    do
    {
        printf("\nChoose an option:\n");
        printf("1. Login\n");
        printf("2. Exit\n");
        scanf("%d",&option);
        
        switch(option)
        {
            case 1:
                flag=0;
                printf("\nEnter your username: ");
                scanf("%s",input);
                
                //Loop to check if entered username exists in the database
                for(i=0;i<5;i++)
                {
                    if(strcmp(input,user[i].user_name)==0) //Checking if input matches with username
                    {
                        printf("Enter your password: ");
                        scanf("%s",input);
                        
                        //Checking if entered password is correct for entered username
                        if(strcmp(input,user[i].pass_word)==0)
                        {
                            printf("\nWelcome %s!\n",user[i].user_name);
                            flag=1;
                            break;
                        }
                        else
                        {
                            printf("\nInvalid password. Please try again.\n");
                            flag=1; //Setting flag to 1 indicating that username exists but password entered is incorrect
                            break;
                        }
                    }
                }
                
                if(flag==0) //If username does not exist
                {
                    printf("\nUsername does not exist.\n");
                }
                
                break;
                
            case 2:
                printf("\nExiting program...\n");
                break;
                
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }while(option!=2); //Loop continues until user enters option 2 to exit
    
    return 0;
}