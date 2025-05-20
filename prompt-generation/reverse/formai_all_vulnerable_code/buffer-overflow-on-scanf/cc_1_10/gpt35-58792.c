//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: invasive
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() {

    printf("Welcome to the Invasive Game!\n");
    printf("You'll be playing as a doctor, trying to cure your patients of their most invasive and dangerous diseases.\n");
    printf("Are you ready to begin the game?\n\n");

    char name[20]; 
    printf("First, what is your name, doctor? "); 
    scanf("%s", name); 

    printf("\n%s, you have just received a new patient. They have a strange and uncommon disease that is causing them severe pain and discomfort. ", name); 
    printf("Your job is to diagnose their symptoms and come up with a cure. "); 
    printf("Are you ready to meet your patient? (Y/N) "); 

    char answer[1]; 
    scanf("%s", answer); 

    if (strcmp(answer, "Y") == 0) {
        printf("\nGreat! Let's begin.\n"); 
    }
    else {
        printf("\nToo bad! Your patient needs you. Let's get started.\n"); 
    }

    printf("\nYou enter the patient's room and introduce yourself. They are clearly in pain and desperately need your help."); 
    printf("You begin to run some tests and take note of their symptoms. "); 
    printf("You find out that they have a rare and invasive parasitic infection that is spreading throughout their body. "); 
    printf("You need to act quickly to stop the infection from spreading any further.\n\n"); 

    printf("What will you do, doctor?\n"); 
    printf("1. Prescribe a strong dose of antibiotics.\n"); 
    printf("2. Perform surgery to remove the infected areas.\n"); 
    printf("3. Inject the patient with an experimental drug.\n"); 

    int choice; 
    printf("Enter your choice: "); 
    scanf("%d", &choice); 

    switch (choice) {
        case 1: 
            printf("\nYou prescribe a strong dose of antibiotics to the patient. ");
            printf("Unfortunately, the infection is too severe and the antibiotics are not effective. "); 
            printf("The patient's condition worsens and they die just a few days later. "); 
            printf("Game over!\n");
            break; 
        case 2:
            printf("\nYou perform surgery to remove the infected areas. ");
            printf("The surgery is successful and the patient starts to recover. "); 
            printf("A few weeks later, they are released from the hospital and are able to live a healthy life. "); 
            printf("Congratulations, you saved your patient's life!\n"); 
            break; 
        case 3:
            printf("\nYou inject the patient with an experimental drug. ");
            printf("The drug seems promising and the patient's condition starts to improve. "); 
            printf("However, the side effects of the drug are severe and the patient develops serious complications. "); 
            printf("Despite your best efforts, the patient dies. "); 
            printf("Game over!\n"); 
            break; 
        default: 
            printf("\nInvalid choice. Game over!\n"); 
            break; 
    }

    return 0; 
}