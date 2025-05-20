//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include<stdio.h> //Header Files Required
#include<stdlib.h>

int main() //Start of Main Function
{
    int choice, n=0, i=0, j=0, temp=0, item=0, flag=0;
    int arr[20]={0}; //Array of Items in the Store with Initial Quantity 0

    while(1) //Loop Continues Infinitely Until User Quits
    {
        system("cls"); //Clears Screen

        printf("\t\t\t\tMedical Store Management System\n\n"); //Title of Program

        printf("1. Add Item\n"); //Menu Option 1
        printf("2. Remove Item\n"); //Menu Option 2
        printf("3. Display all Items\n"); //Menu Option 3
        printf("4. Search for Item\n"); //Menu Option 4
        printf("5. Quit\n\n"); //Menu Option 5

        printf("Enter Your Choice: "); //Prompts User for Choice
        scanf("%d",&choice); 

        switch (choice) //Switch Case Based on User's Choice
        {
            case 1: //User Wants to Add an Item
                printf("\nEnter the Number of Items you Want to Add: "); //Prompt for Number of Items to Add
                scanf("%d",&n);

                printf("\nEnter the Item(s):\n"); //Prompt for Item Name(s) to Add
                for(i=0;i<n;i++)
                {
                    fflush(stdin); //Clears Buffer
                    gets(arr[j]); //Stores Items
                    j++;
                }

                printf("\n%d Item(s) Added Successfully!",n); //Displays Success Message
                break;
                
            case 2: //User Wants to Remove an Item
                printf("\nEnter the Item you Want to Remove: "); //Prompt for Item Name to Remove
                fflush(stdin); //Clears Buffer
                gets(item);

                for(i=0;i<j;i++)
                {
                    if(strcmp(arr[i],item)==0) //Item Found
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1) //Item Found, Remove It
                {
                    for(i=0;i<j;i++)
                    {
                        if(strcmp(arr[i],item)==0) //Find Location of Item in Array
                        {
                            temp=i;
                            break;
                        }
                    }
                    for(i=temp;i<j-1;i++) //Shift Items After Removed Item One Position Backward
                    {
                        arr[i]=arr[i+1];
                    }
                    printf("\n%s Removed Successfully!",item); //Displays Success Message
                    j--; //Decrease Total Number of Items After Removal
                }
                else //Item Not Found
                {
                    printf("\n%s Not Found in the Store!",item); //Displays Failure Message
                }
                break;
                
            case 3: //User Wants to Display all Items
                printf("\nItems in the Store:\n"); //Displays All Items
                for(i=0;i<j;i++)
                {
                    printf("%d. %s\n",i+1,arr[i]);
                }
                break;
                
            case 4: //User Wants to Search for an Item
                printf("\nEnter the Item you Want to Search: "); //Prompt for Item to Search
                fflush(stdin); //Clears Buffer
                gets(item);

                for(i=0;i<j;i++)
                {
                    if(strcmp(arr[i],item)==0) //Item Found
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1) //Item Found, Display It
                {
                    printf("\n%s Found in the Store!",item); //Displays Success Message
                }
                else //Item Not Found
                {
                    printf("\n%s Not Found in the Store!",item); //Displays Failure Message
                }
                break;
                
            case 5: //User Wants to Quit
                printf("\nThank You for Using this Program!"); //Displays Exit Message
                exit(0); //Ends Program
                break;
                
            default: //Invalid Choice
                printf("\nInvalid Choice, Please Try Again!"); //Displays Error Message
                break;
        }
        getchar(); //Clears Buffer
        printf("\nPress Enter to Continue..."); //Prompts User to Continue
        getchar(); //Waits for User's Input
    }
    return 0; //End of Program
}