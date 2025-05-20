//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 10
#define MAX_OPTIONS 5

typedef struct {
    char name[50];
    int option;
} Voter;

Voter voters[MAX_VOTERS];
int num_voters = 0;

void print_voters(void) {
    printf("Voters:\n");
    for(int i = 0; i < num_voters; i++) {
        printf("Name: %s\n", voters[i].name);
        printf("Option: %d\n", voters[i].option);
        printf("\n");
    }
}

void add_voter(char *name, int option) {
    if(num_voters >= MAX_VOTERS) {
        printf("Error: Maximum number of voters reached.\n");
        return;
    }
    
    strcpy(voters[num_voters].name, name);
    voters[num_voters].option = option;
    
    num_voters++;
}

int main(void) {
    char name[50];
    int option;
    
    printf("Welcome to the Electronic Voting System!\n");
    
    while(1) {
        printf("1. Add Voter\n");
        printf("2. Print Voters\n");
        printf("3. Exit\n");
        
        int choice;
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                add_voter(name, 0);
                break;
                
            case 2:
                print_voters();
                break;
                
            case 3:
                return 0;
                
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}