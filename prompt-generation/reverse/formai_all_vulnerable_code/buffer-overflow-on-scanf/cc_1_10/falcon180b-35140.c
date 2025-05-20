//Falcon-180B DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    printf("Welcome to the Error Handling Program!\n");
    printf("Please choose an option:\n");
    printf("1. Divide by zero\n");
    printf("2. Invalid input\n");
    printf("3. Memory allocation error\n");
    printf("4. File handling error\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You chose to divide by zero.\n");
            printf("Result: Error\n");
            break;
        case 2:
            printf("You chose invalid input.\n");
            printf("Result: Error\n");
            break;
        case 3:
            printf("You chose memory allocation error.\n");
            int *ptr = NULL;
            *ptr = 10;
            printf("Result: Error\n");
            break;
        case 4:
            printf("You chose file handling error.\n");
            FILE *fp = fopen("nonexistentfile.txt", "r");
            if(fp == NULL) {
                printf("Error opening file\n");
            } else {
                fclose(fp);
            }
            break;
        case 5:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}