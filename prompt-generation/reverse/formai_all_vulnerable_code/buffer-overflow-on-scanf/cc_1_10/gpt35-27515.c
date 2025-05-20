//FormAI DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
struct password {
    char website[100];
    char username[100];
    char password[100];
};
 
int main() {
    int choice, n = 0, i, index;
    
    struct password p[100]; // assuming there are max 100 passwords to store
 
    while (1) {
        printf("1. Add Password\n");
        printf("2. Find Password\n");
        printf("3. Display all Passwords\n");
        printf("4. Exit\n");
 
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("\nEnter website: ");
                scanf("%s", p[n].website);
 
                printf("Enter username: ");
                scanf("%s", p[n].username);
 
                printf("Enter password: ");
                scanf("%s", p[n].password);
 
                printf("Password successfully added!\n");
                n++;
                break;
 
            case 2:
                printf("\nEnter website: ");
                char website[100];
                scanf("%s", website);
 
                for (i = 0; i < n; i++) {
                    if (strcmp(p[i].website, website) == 0) {
                        printf("\nWebsite: %s\n", p[i].website);
                        printf("Username: %s\n", p[i].username);
                        printf("Password: %s\n", p[i].password);
                        break;
                    }
                }
                if (i == n) {
                    printf("\nPassword not found!\n");
                }
                break;
 
            case 3:
                printf("\nAll Passwords:\n");
                for (i = 0; i < n; i++) {
                    printf("\nWebsite: %s\n", p[i].website);
                    printf("Username: %s\n", p[i].username);
                    printf("Password: %s\n", p[i].password);
                }
                break;
 
            case 4:
                printf("Exiting program...\n");
                exit(0);
 
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
 
    return 0;
}