//FormAI DATASET v1.0 Category: Online Examination System ; Style: grateful
#include<stdio.h> 
#include<stdlib.h> 
#define MAX 100 

void mainmenu(); 

int main() 
{ 
    char password[MAX]; 
    char mainmenuinput; 
    
    printf("Please enter the password to access the C online examination system:\n"); 
    scanf("%s", password); 
    
    if(strcmp(password, "Cpassword") == 0) //checking password 
    { 
        printf("\nWelcome to the C programming language online examination system.\n"); 
        mainmenu(); 
    } 
    else 
    { 
        printf("\nIncorrect Password. Please try again later.\n"); 
    } 
    return 0; 
} 

void mainmenu() 
{ 
    int choice = 0; 
    
    printf("MAIN MENU:\n"); 
    printf("1. Start Exam\n"); 
    printf("2. Instructions\n"); 
    printf("3. Exit\n"); 
    printf("Enter choice: "); 
    scanf("%d", &choice); 
    
    switch(choice) 
    { 
        case 1: 
            printf("\nStarting Exam...\n"); 
            //call exam function 
            break; 
        case 2: 
            printf("\nInstructions:\n"); 
            printf("1. This exam contains 20 multiple choice questions.\n"); 
            printf("2. Each question is worth 5 points.\n"); 
            printf("3. You have 1 hour to complete the exam.\n"); 
            printf("4. Good luck!\n\n"); 
            mainmenu(); 
            break; 
        case 3: 
            printf("\nYou have selected to exit. Thank you and have a nice day!\n"); 
            break; 
        default: 
            printf("\nInvalid selection. Please try again.\n"); 
            mainmenu(); 
            break; 
    } 
}