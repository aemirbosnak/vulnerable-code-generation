//FormAI DATASET v1.0 Category: Password management ; Style: complete
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100

int main() {
    char passwords[MAX_SIZE][MAX_SIZE]; //2D array to store passwords
    int num_passwords = 0; //initialize number of passwords to 0
    char choice;
    
    //loop to get user input
    do {
        //menu
        printf("\nMenu:\n");
        printf("1. Add password\n");
        printf("2. View password\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        //switch case for user input
        switch (choice) {
            case '1':
                printf("\nEnter your password: ");
                scanf("%s", passwords[num_passwords]); //store password
                num_passwords++; //increment number of passwords
                printf("Password added successfully!\n");
                break;
                
            case '2':
                if (num_passwords == 0) { //check if there are no passwords
                    printf("\nNo passwords added yet.\n");
                    break;
                }
                printf("\nYour saved passwords are:\n");
                for (int i=0; i<num_passwords; i++) {
                    printf("%d. %s\n", i+1, passwords[i]); //display all passwords
                }
                break;
                
            case '3':
                printf("\nExiting program...\n");
                break;
                
            default:
                printf("\nInvalid input. Please try again.\n");
        }
        
    } while (choice != '3');
    
    return 0;
}