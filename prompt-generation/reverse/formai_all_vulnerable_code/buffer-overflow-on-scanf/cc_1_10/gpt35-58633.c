//FormAI DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct password {
    char siteName[50];
    char userName[50];
    char passWord[50];
};

void addPassword(struct password pass[], int *count) {
    printf("\n\n===== ADD NEW PASSWORD =====\n");
    printf("Enter site name: ");
    scanf("%s", pass[*count].siteName);
    printf("Enter username: ");
    scanf("%s", pass[*count].userName);
    printf("Enter password: ");
    scanf("%s", pass[*count].passWord);
    *count += 1;
    printf("New password added!\n");
}

void viewPasswords(struct password pass[], int count) {
    printf("\n\n===== VIEW PASSWORDS =====\n");
    if(count == 0) {
        printf("There are no saved passwords.\n");
        return;
    }
    for(int i = 0; i < count; i++) {
        printf("%s\n", pass[i].siteName);
        printf("\tUsername: %s\n", pass[i].userName);
        printf("\tPassword: %s\n", pass[i].passWord);
    }
}

void searchPasswords(struct password pass[], int count) {
    if(count == 0) {
        printf("There are no saved passwords to search.\n");
        return;
    }
    char siteName[50];
    printf("\n\n===== SEARCH PASSWORDS =====\n");
    printf("Enter the site name you want to search for: ");
    scanf("%s", siteName);
    for(int i = 0; i < count; i++) {
        if(strcmp(pass[i].siteName, siteName) == 0) {
            printf("%s\n", pass[i].siteName);
            printf("\tUsername: %s\n", pass[i].userName);
            printf("\tPassword: %s\n", pass[i].passWord);
            return;
        }
    }
    printf("Site name not found in saved passwords.\n");
}

int main() {
    struct password pass[50];
    int count = 0;
    int choice;
    while(1) {
        printf("\n\n===== PASSWORD MANAGEMENT SYSTEM =====\n");
        printf("\t1. Add new password\n");
        printf("\t2. View saved passwords\n");
        printf("\t3. Search saved passwords\n");
        printf("\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addPassword(pass, &count);
                break;
            
            case 2:
                viewPasswords(pass, count);
                break;
            
            case 3:
                searchPasswords(pass, count);
                break;

            case 4:
                printf("Goodbye!");
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}