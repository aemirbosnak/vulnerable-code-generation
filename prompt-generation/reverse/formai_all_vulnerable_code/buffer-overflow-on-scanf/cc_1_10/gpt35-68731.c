//FormAI DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

struct Person {
    char name[20];
    int age;
};

struct Relationship {
    struct Person person1;
    struct Person person2;
    char status[10];
};

int main() {
    struct Person romeo = {"Romeo", 18};
    struct Person juliet = {"Juliet", 16};
    struct Relationship relationship = {romeo, juliet, "single"};
    
    printf("Welcome to the Database Simulation of Romeo and Juliet's Relationship\n\n");
    
    int choice;
    do {
        printf("Press 1 to view Romeo and Juliet's current status\n");
        printf("Press 2 to update Romeo and Juliet's status\n");
        printf("Press 3 to exit the program\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("\nRomeo and Juliet's current status: %s\n\n", relationship.status);
        } else if (choice == 2) {
            printf("\nChoose a status for Romeo and Juliet:\n");
            printf("1. Single\n");
            printf("2. Dating\n");
            printf("3. Engaged\n\n");
            printf("Enter your choice: ");
            int status_choice;
            scanf("%d", &status_choice);
            
            if (status_choice == 1) {
                strcpy(relationship.status, "single");
                printf("\nRomeo and Juliet are now single\n\n");
            } else if (status_choice == 2) {
                strcpy(relationship.status, "dating");
                printf("\nRomeo and Juliet are now dating\n\n");
            } else if (status_choice == 3) {
                strcpy(relationship.status, "engaged");
                printf("\nRomeo and Juliet are now engaged\n\n");
            } else {
                printf("\nInvalid choice, please try again\n\n");
            }
        } else if (choice == 3) {
            printf("\nExiting the program, thank you!\n");
            break;
        } else {
            printf("\nInvalid choice, please try again\n\n");
        }
    } while (choice != 3);
    
    return 0;
}