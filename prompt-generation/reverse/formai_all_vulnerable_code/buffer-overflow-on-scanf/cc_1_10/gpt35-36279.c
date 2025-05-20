//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MEDS 100
#define MAX_NAME_LEN 50

// Struct to hold medicine information
typedef struct{
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
} Medicine;

// Function to generate random medicine quantity
int generateMedQuantity(){
    return rand() % 100;
}

int main(){
    // Initialize medicine array and variables
    Medicine meds[MAX_MEDS];
    int numMeds = 0;
    srand(time(0));

    // Program greeting
    printf("Welcome to the Medical Store Management System!\n\n");

    // Main menu loop
    while(1){
        // Print menu options
        printf("---Main Menu---\n");
        printf("1. Add New Medicine\n");
        printf("2. View Medicine Inventory\n");
        printf("3. Exit\n");
        printf("Enter your choice:");

        // Get user choice
        int choice;
        scanf("%d", &choice);

        // Add new medicine
        if(choice == 1){
            // Check if max medicine quantity is reached
            if(numMeds == MAX_MEDS){
                printf("ERROR: Max medicine quantity reached!\n\n");
                continue;
            }

            // Get medicine name
            char name[MAX_NAME_LEN];
            printf("Enter medicine name:");
            scanf("%s", name);

            // Add medicine to array and update quantity
            meds[numMeds].id = numMeds;
            strcpy(meds[numMeds].name, name);
            meds[numMeds].quantity = generateMedQuantity();
            printf("\nNew medicine added!\n\n");
            numMeds++;
        }
        // View medicine inventory
        else if(choice == 2){
            // Check if medicines are present
            if(numMeds == 0){
                printf("No medicines available in inventory.\n\n");
            }
            else{
                // Print medicine information
                printf("\n---Medicine Inventory---\n");
                printf("ID\tName\tQuantity\n");
                for(int i=0; i<numMeds; i++){
                    printf("%d\t%s\t%d\n", meds[i].id, meds[i].name, meds[i].quantity);
                }
                printf("\n");
            }
        }
        // Exit program
        else if(choice == 3){
            printf("\nGoodbye!\n");
            break;
        }
        // Invalid choice
        else{
            printf("Invalid choice! Try again.\n\n");
        }
    }
    return 0;
}