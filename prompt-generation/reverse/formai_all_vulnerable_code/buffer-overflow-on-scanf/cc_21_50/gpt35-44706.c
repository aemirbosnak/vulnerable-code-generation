//FormAI DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_LIST_LENGTH 5

int main(){

    char mailing_lists[MAX_LIST_LENGTH][MAX_EMAIL_LENGTH]; //array to store mailing lists
    int num_lists = 0; //number of current mailing lists
    char email[MAX_EMAIL_LENGTH]; //email to be added to a mailing list

    printf("Welcome to the mailing list manager!\n");

    while(1){
        int choice;

        printf("\nPlease choose an option:\n");
        printf("1. Add an email to a mailing list\n");
        printf("2. Create a new mailing list\n");
        printf("3. Remove an email from a mailing list\n");
        printf("4. Remove a mailing list\n");
        printf("5. Print all mailing lists and their emails\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(num_lists == 0){
                    printf("\nThere are no existing mailing lists. Please create one first.\n");
                }
                else{
                    printf("\nEnter the email you would like to add: ");
                    scanf("%s", email);
                    int found = 0;
                    for(int i=0; i<num_lists; i++){
                        if(strcmp(email, mailing_lists[i]) == 0){
                            printf("\nThe email already exists in the %s mailing list.\n", mailing_lists[i]);
                            found = 1;
                        }
                    }
                    if(found == 0){
                        printf("\nEnter the name of the mailing list you would like to add the email to: ");
                        scanf("%s", email);
                        int found2 = 0;
                        for(int i=0; i<num_lists; i++){
                            if(strcmp(email, mailing_lists[i]) == 0){
                                printf("\nEmail successfully added to %s mailing list.\n", mailing_lists[i]);
                                found2 = 1;
                            }
                        }
                        if(found2 == 0){
                            printf("\nSorry, the mailing list %s does not exist.\n", email);
                        }
                    }
                }
                break;

            case 2:
                if(num_lists == MAX_LIST_LENGTH){
                    printf("\nYou have reached the maximum number of mailing lists, which is %d.\n", MAX_LIST_LENGTH);
                }
                else{
                    printf("\nEnter the name of the new mailing list: ");
                    scanf("%s", mailing_lists[num_lists]);
                    num_lists++;
                    printf("\nMailing list %s successfully created.\n", mailing_lists[num_lists-1]);
                }
                break;

            case 3:
                if(num_lists == 0){
                    printf("\nThere are no existing mailing lists. Please create one first.\n");
                }
                else{
                    printf("\nEnter the email you would like to remove: ");
                    scanf("%s", email);
                    int found = 0;
                    for(int i=0; i<num_lists; i++){
                        if(strcmp(email, mailing_lists[i]) == 0){
                            printf("\nEmail successfully removed from %s mailing list.\n", mailing_lists[i]);
                            found = 1;
                        }
                    }
                    if(found == 0){
                        printf("\nSorry, the email %s does not exist in any mailing list.\n", email);
                    }
                }
                break;

            case 4:
                if(num_lists == 0){
                    printf("\nThere are no existing mailing lists. Please create one first.\n");
                }
                else{
                    printf("\nEnter the name of the mailing list you would like to remove: ");
                    scanf("%s", email);
                    int found = 0;
                    for(int i=0; i<num_lists; i++){
                        if(strcmp(email, mailing_lists[i]) == 0){
                            printf("\nMailing list %s successfully removed.\n", mailing_lists[i]);
                            found = 1;
                            for(int j=i; j<num_lists-1; j++){
                                strcpy(mailing_lists[j], mailing_lists[j+1]);
                            }
                            num_lists--;
                        }
                    }
                    if(found == 0){
                        printf("\nSorry, the mailing list %s does not exist.\n", email);
                    }
                }
                break;

            case 5:
                if(num_lists == 0){
                    printf("\nThere are no existing mailing lists. Please create one first.\n");
                }
                else{
                    printf("\nMailing list(s):\n");
                    for(int i=0; i<num_lists; i++){
                        printf("%d. %s\n", i+1, mailing_lists[i]);
                        printf("   Emails:\n");
                        //print all emails in the current mailing list
                        printf("\n");
                    }
                }
                break;

            case 6:
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    }

    return 0;
}