//FormAI DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

struct User {
    char name[50];
    int age;
    char occupation[50];
};

int main() {
    struct User user_list[MAX_USERS];
    int num_users = 0;
    
    // Print welcome message
    printf("Welcome to the User Database Program!\n\n");
    
    // Loop for user input
    char input[10];
    while (1) {
        printf("Type 'add' to add a user, 'search' to search for a user, or 'quit' to exit: ");
        scanf("%s", input);
        
        // Add user
        if (strcmp(input, "add") == 0) {
            // Check if list is full
            if (num_users >= MAX_USERS) {
                printf("Maximum number of users reached.\n\n");
                continue;
            }
            
            // Get user input
            char name[50], occupation[50];
            int age;
            
            printf("Enter user name: ");
            scanf("%s", name);
            
            printf("Enter user age: ");
            scanf("%d", &age);
            
            printf("Enter user occupation: ");
            scanf("%s", occupation);
            
            // Add user to list
            struct User new_user;
            strcpy(new_user.name, name);
            new_user.age = age;
            strcpy(new_user.occupation, occupation);
            
            user_list[num_users++] = new_user;
            
            printf("User added!\n\n");
        }
        
        // Search for user
        else if (strcmp(input, "search") == 0) {
            // Get search query
            char query[50];
            printf("Enter search query: ");
            scanf("%s", query);
            
            // Find matching users and print their info
            int num_matches = 0;
            
            for (int i = 0; i < num_users; i++) {
                struct User user = user_list[i];
                
                if (strstr(user.name, query) != NULL || strstr(user.occupation, query) != NULL) {
                    printf("User #%d: Name=%s Age=%d Occupation=%s\n", i+1, user.name, user.age, user.occupation);
                    num_matches++;
                }
            }
            
            printf("%d match(es) found.\n\n", num_matches);
        }
        
        // Quit program
        else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        
        // Invalid input
        else {
            printf("Invalid input. Try again.\n\n");
        }
    }
    
    return 0;
}