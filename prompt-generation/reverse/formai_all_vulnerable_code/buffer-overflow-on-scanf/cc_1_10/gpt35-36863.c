//FormAI DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Creating a struct to hold contact information
struct contact{
    char name[50];
    char phone[20];
    char email[50];
};

int main(){

    int choice, count=0;
    struct contact contacts[100];

    //Opening message in Cyberpunk style
    printf("Greetings, Netrunner. Welcome to the Cyberpunk Phone Book.\n");

    do{
        //Displaying menu options
        printf("Select an option:\n");
        printf("1. Add Contact\n");
        printf("2. View Contact\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: //Adding a contact
                printf("\nEnter Contact Details:\n");
                printf("Name: ");
                scanf("%s",contacts[count].name);
                printf("Phone: ");
                scanf("%s",contacts[count].phone);
                printf("Email: ");
                scanf("%s",contacts[count].email);

                count++;
                printf("\nContact added successfully. Good job, Netrunner.\n");
                break;
            case 2: //Displaying a contact
                if(count==0){
                    printf("\nNo contacts found. Better luck next time, Netrunner.\n");
                    break;
                }
                printf("\nEnter Name to Search: ");
                char searchName[50];
                scanf("%s",searchName);

                int i, found=0;
                for(i=0;i<count;i++){
                    if(strcmp(contacts[i].name, searchName)==0){
                        printf("\nContact Details Found:\n");
                        printf("Name: %s\n",contacts[i].name);
                        printf("Phone: %s\n",contacts[i].phone);
                        printf("Email: %s\n",contacts[i].email);
                        found=1;
                        break;
                    }
                }
                if(found==0)
                    printf("\nNo contacts found with that name. Keep searching, Netrunner.\n");
                break;
            case 3: //Exiting the program
                printf("\nExiting Cyberpunk Phone Book. Stay Frosty, Netrunner.\n");
                exit(0);
            default: //Invalid menu choice
                printf("\nNot a valid option, Netrunner. Try again.\n");
        }
    }while(choice!=3);

    //Program has ended successfully
    return 0;
}