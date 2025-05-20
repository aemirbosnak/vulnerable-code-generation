//FormAI DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Password {
    char website[50];
    char username[20];
    char password[20];
};

int main() {
    int choice, i, flag=0, num=0;
    char search[50];
    struct Password p[20];
    
    printf("\nWelcome to Password Management System!");
    while(1) {
        printf("\n\nMENU");
        printf("\n1. Add Password");
        printf("\n2. View All Passwords");
        printf("\n3. Search Password");
        printf("\n4. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("\nADD PASSWORD DETAILS:");
                printf("\nEnter website url: ");
                scanf("%s", p[num].website);
                printf("Enter username: ");
                scanf("%s", p[num].username);
                printf("Enter password: ");
                scanf("%s", p[num].password);
                num++;
                printf("\nPassword added successfully!");
                break;
        
            case 2:
                if(num>0) {
                    printf("\nALL PASSWORDS:");
                    printf("\nWebsite URL \t\t Username \t Password");
                    printf("\n--------------------------------------------------");
                    for(i=0; i<num; i++) {
                        printf("\n%s \t %s \t %s", p[i].website, p[i].username, p[i].password);
                    }
                }
                else {
                    printf("\nNo Passwords are added yet!");
                }
                break;

            case 3:
                printf("\nEnter the website url to be searched: ");
                scanf("%s", search);
                for(i=0; i<num; i++) {
                    if(strcmp(p[i].website, search)==0) {
                        flag=1;
                        printf("\nPassword for %s:\n", search);
                        printf("\nWebsite URL \t\t Username \t Password");
                        printf("\n--------------------------------------------------");
                        printf("\n%s \t %s \t %s", p[i].website, p[i].username, p[i].password);
                        break;
                    }
                }
                if(flag==0) {
                    printf("\nNo website with the given url found!\n");
                }
                break;

            case 4:
                printf("\nThanks for using Password Management System!");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again!");
                break;
        }
    }

    return 0;
}