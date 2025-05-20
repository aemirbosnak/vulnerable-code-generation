//FormAI DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//structure to represent each member in the mailing list
struct mailingListMember{
    char name[50];
    char email[50];
};

//function to add a new member to the mailing list
void addMember(struct mailingListMember *list, int *numMembers){
    char temp[50]; //temporary string to store user input
    printf("Enter member's name: ");
    fgets(temp, 50, stdin); //get user input
    strcpy(list[*numMembers].name, temp); //copy into member's name field

    printf("Enter member's email: ");
    fgets(temp, 50, stdin); //get user input
    strcpy(list[*numMembers].email, temp); //copy into member's email field

    (*numMembers)++; //increment number of members in the list
}

//function to display all members in the mailing list
void displayMembers(struct mailingListMember *list, int numMembers){
    printf("Current members in the mailing list:\n");
    for(int i=0; i<numMembers; i++){
        printf("%d. Name: %sEmail: %s", i+1, list[i].name, list[i].email);
    }
}

int main(){
    struct mailingListMember list[100]; //create an array to hold mailing list members
    int numMembers = 0; //initialize number of members to zero

    while(1){ //loop until user chooses to exit
        int choice;
        printf("\nSELECT AN OPTION\n");
        printf("1. Add a member\n");
        printf("2. Display all members\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); //consume newline character from input buffer

        switch(choice){
            case 1:
                addMember(list, &numMembers); //call addMember function
                break;
            case 2:
                displayMembers(list, numMembers); //call displayMembers function
                break;
            case 3:
                printf("Exiting...\n");
                exit(0); //exit program
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}